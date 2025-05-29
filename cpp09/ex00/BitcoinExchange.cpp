/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 19:12:16 by pmarkaid          #+#    #+#             */
/*   Updated: 2025/05/29 15:33:52 by pmarkaid         ###   ########.fr       */
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
    // Skip header line - database format is trusted
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

// Validate date format with robust manual validation
bool BitcoinExchange::isValidDate(const std::string& date) const {
    // Quick format check: YYYY-MM-DD (length = 10)
    if (date.length() != 10 || date[4] != '-' || date[7] != '-') {
        return false;
    }
    
    try {
        // Manual parsing of date components
        std::string yearStr = date.substr(0, 4);
        std::string monthStr = date.substr(5, 2);
        std::string dayStr = date.substr(8, 2);
        
        // Check if all components are numeric
        if (!std::all_of(yearStr.begin(), yearStr.end(), ::isdigit) ||
            !std::all_of(monthStr.begin(), monthStr.end(), ::isdigit) ||
            !std::all_of(dayStr.begin(), dayStr.end(), ::isdigit)) {
            return false;
        }
        
        // Convert to integers
        int year = std::stoi(yearStr);
        int month = std::stoi(monthStr);
        int day = std::stoi(dayStr);
        
        // Validate ranges
        if (year < 1000 || year > 9999) return false;
        if (month < 1 || month > 12) return false;
        if (day < 1 || day > 31) return false;
        
        // Days per month validation
        static const int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int maxDays = daysInMonth[month - 1];
        
        // Handle leap year for February
        if (month == 2) {
            bool isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
            if (isLeap) maxDays = 29;
        }
        
        return day <= maxDays;
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

// Process the input file with strict validation
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
        // Validate header line
        if (isFirstLine) {
            isFirstLine = false;
            if (line != "date | value") {
                std::cerr << "Error: bad input => " << line << std::endl;
                continue;
            }
            continue;
        }
        
        // Skip empty lines
        if (line.empty()) {
            continue;
        }
        
        // Find pipe separator - must be exactly one
        size_t pipePos = line.find('|');
        
        // Check for invalid format cases
        if (pipePos == std::string::npos) {
            // No pipe found
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        
        // Check for multiple pipes
        if (line.find('|', pipePos + 1) != std::string::npos) {
            // Multiple pipes found
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        
        // Split into exactly 2 parts
        std::string dateStr = trim(line.substr(0, pipePos));
        std::string valueStr = trim(line.substr(pipePos + 1));
        
        // Check for empty parts
        if (dateStr.empty() || valueStr.empty()) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        
        // Validate date
        if (!isValidDate(dateStr)) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        
        // Validate value
        float value;
        if (!isNumeric(valueStr)) {
            std::cerr << "Error: bad input => " << line << std::endl;
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