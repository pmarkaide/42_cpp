/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 19:12:16 by pmarkaid          #+#    #+#             */
/*   Updated: 2025/05/20 19:45:20 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

// Default constructor
BitcoinExchange::BitcoinExchange() {
    // Default database file
    if (!parseDatabase("data.csv")) {
        std::cerr << "Error: could not open default database file." << std::endl;
    }
}

// Parameterized constructor
BitcoinExchange::BitcoinExchange(const std::string& databaseFile) {
    if (!parseDatabase(databaseFile)) {
        std::cerr << "Error: could not open database file: " << databaseFile << std::endl;
    }
}

// Copy constructor
BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : database_(other.database_) {
}

// Copy assignment operator
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other) {
        database_ = other.database_;
    }
    return *this;
}

// Destructor
BitcoinExchange::~BitcoinExchange() {
}

// String utilities
std::string BitcoinExchange::trim(const std::string& str) const {
    size_t first = str.find_first_not_of(" \t");
    if (first == std::string::npos) {
        return ""; // Empty or only whitespace
    }
    size_t last = str.find_last_not_of(" \t");
    return str.substr(first, (last - first + 1));
}

// Check if string is a valid numeric value
bool BitcoinExchange::isNumeric(const std::string& str) const {
    std::istringstream ss(str);
    float value;
    ss >> value;
    // Check if entire string was consumed and no errors occurred
    return !ss.fail() && ss.eof();
}

// Parse the bitcoin exchange rate database
bool BitcoinExchange::parseDatabase(const std::string& filename) {
    std::ifstream file(filename);
    
    if (!file.is_open()) {
        return false;
    }
    
    std::string line;
    // Skip header line
    std::getline(file, line);
    
    while (std::getline(file, line)) {
        std::istringstream ss(line);
        std::string date;
        std::string rateStr;
        
        // Expected format: date,exchange_rate
        if (std::getline(ss, date, ',') && std::getline(ss, rateStr)) {
            date = trim(date);
            rateStr = trim(rateStr);
            
            if (isValidDate(date) && isNumeric(rateStr)) {
                float rate = std::stof(rateStr);
                database_[date] = rate;
            }
        }
    }
    
    file.close();
    return !database_.empty();
}

// Validate date format and check if it's a valid date using chrono
bool BitcoinExchange::isValidDate(const std::string& date) const {
    // Check format: YYYY-MM-DD
    if (date.length() != 10 || date[4] != '-' || date[7] != '-') {
        return false;
    }
    
    try {
        // Extract year, month, and day and check if they're numeric
        std::string yearStr = date.substr(0, 4);
        std::string monthStr = date.substr(5, 2);
        std::string dayStr = date.substr(8, 2);
        
        if (!isNumeric(yearStr) || !isNumeric(monthStr) || !isNumeric(dayStr)) {
            return false;
        }
        
        std::istringstream ss(date);
        std::tm t = {};
        ss >> std::get_time(&t, "%Y-%m-%d");
        
        if (ss.fail()) {
            return false;
        }
        
        // Convert back to string to verify normalization preserved the date
        // This implicitly checks for leap years and valid day/month combinations
        char buf[11];
        std::strftime(buf, sizeof(buf), "%Y-%m-%d", &t);
        
        return date == std::string(buf);
    }
    catch (const std::exception&) {
        return false;
    }
}

// Check if the value is valid (between 0 and 1000)
bool BitcoinExchange::isValidValue(const std::string& valueStr, float& value) const {
    // Check if string is numeric
    if (!isNumeric(valueStr)) {
        return false;
    }
    
    try {
        value = std::stof(valueStr);
        return value >= 0 && value <= 1000;
    }
    catch (const std::exception&) {
        return false;
    }
}

// Find the closest date in the database that is not greater than the given date
std::string BitcoinExchange::findClosestDate(const std::string& date) const {
    // Use lower_bound to find the first element not less than date
    auto it = database_.lower_bound(date);
    
    // If exact match found
    if (it != database_.end() && it->first == date) {
        return it->first;
    }
    
    // If no match and nothing lower exists
    if (it == database_.begin()) {
        return "";
    }
    
    // Return the previous element (which is lower than the date)
    --it;
    return it->first;
}

// Process the input file
bool BitcoinExchange::processInputFile(const std::string& inputFile) {
    std::ifstream file(inputFile);
    
    if (!file.is_open()) {
        std::cerr << "Error: could not open file." << std::endl;
        return false;
    }
    
    if (database_.empty()) {
        std::cerr << "Error: database is empty." << std::endl;
        return false;
    }
    
    std::string line;
    bool isFirstLine = true;
    
    while (std::getline(file, line)) {
        // Skip header line
        if (isFirstLine) {
            isFirstLine = false;
            continue;
        }
        
        // Skip empty lines
        if (line.empty()) {
            continue;
        }
        
        // Find the pipe separator
        size_t pipePos = line.find('|');
        
        // Process valid format: "date | value"
        if (pipePos != std::string::npos) {
            std::string dateStr = trim(line.substr(0, pipePos));
            std::string valueStr = trim(line.substr(pipePos + 1));
            
            // Validate date
            if (!isValidDate(dateStr)) {
                std::cerr << "Error: bad input => " << line << std::endl;
                continue;
            }
            
            // Validate value
            float value;
            if (valueStr.empty()) {
                std::cerr << "Error: missing value => " << line << std::endl;
                continue;
            }
            
            if (!isNumeric(valueStr)) {
                std::cerr << "Error: not a number => " << valueStr << std::endl;
                continue;
            }
            
            value = std::stof(valueStr);
            
            if (value < 0) {
                std::cerr << "Error: not a positive number." << std::endl;
                continue;
            }
            
            if (value > 1000) {
                std::cerr << "Error: too large a number." << std::endl;
                continue;
            }
            
            // Find closest date in database
            std::string closestDate = findClosestDate(dateStr);
            if (closestDate.empty()) {
                std::cerr << "Error: no data available for date " << dateStr << std::endl;
                continue;
            }
            
            // Calculate and output result
            float exchangeRate = database_[closestDate];
            float result = value * exchangeRate;
            
            std::cout << dateStr << " => " << value << " = " << result << std::endl;
        }
        else {
            std::cerr << "Error: bad input => " << line << std::endl;
        }
    }
    
    file.close();
    return true;
}

// Debug method to print database contents
void BitcoinExchange::printDatabase() const {
    std::cout << "Database contents:" << std::endl;
    for (const auto& entry : database_) {
        std::cout << entry.first << ": " << entry.second << std::endl;
    }
}

// Check if database is empty
bool BitcoinExchange::isDatabaseEmpty() const {
    return database_.empty();
}