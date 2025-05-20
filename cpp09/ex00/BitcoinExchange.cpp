/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 19:12:16 by pmarkaid          #+#    #+#             */
/*   Updated: 2025/05/20 19:31:58 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
    parseDatabase("data.csv");
}

BitcoinExchange::BitcoinExchange(const std::string& databaseFile) {
    if (!parseDatabase(databaseFile)) {
        std::cerr << "Error: could not open database file." << std::endl;
    }
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : database_(other.database_) {
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other) {
        database_ = other.database_;
    }
    return *this;
}


BitcoinExchange::~BitcoinExchange() {
}

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
        float rate;
        
        // Expected format: date,exchange_rate
        if (std::getline(ss, date, ',') && ss >> rate) {
            if (isValidDate(date)) {
                database_[date] = rate;
            }
        }
    }
    
    file.close();
    return !database_.empty();
}

bool BitcoinExchange::isValidDate(const std::string& date) const {
    // Check format: YYYY-MM-DD
    if (date.length() != 10 || date[4] != '-' || date[7] != '-') {
        return false;
    }
    
    try {
        std::istringstream ss(date);
        std::tm t = {};
        ss >> std::get_time(&t, "%Y-%m-%d");
        
        if (ss.fail()) {
            return false;
        }
        
        // Convert back to string to verify normalization preserved the date
        char buf[11];
        std::strftime(buf, sizeof(buf), "%Y-%m-%d", &t);
        
        return date == std::string(buf);
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


bool BitcoinExchange::processInputFile(const std::string& inputFile) {
    std::ifstream file(inputFile);
    
    if (!file.is_open()) {
        std::cerr << "Error: could not open file." << std::endl;
        return false;
    }
    
    std::string line;
    // Skip header line
    std::getline(file, line);
    
    while (std::getline(file, line)) {
        std::istringstream ss(line);
        std::string date;
        std::string separator;
        float value;
        
        // Expected format: date | value
        if (std::getline(ss, date, '|') && (date = date.substr(0, date.find_last_not_of(" \t") + 1), true) && 
            (ss >> value)) {
            
            // Trim leading spaces from date
            date = date.substr(date.find_first_not_of(" \t"));
            
            if (!isValidDate(date)) {
                std::cerr << "Error: bad input => " << date << std::endl;
                continue;
            }
            
            if (value < 0) {
                std::cerr << "Error: not a positive number." << std::endl;
                continue;
            }
            
            if (value > 1000) {
                std::cerr << "Error: too large a number." << std::endl;
                continue;
            }
            
            // Find closest date in database
            std::string closestDate = findClosestDate(date);
            if (closestDate.empty()) {
                std::cerr << "Error: no data available for date " << date << std::endl;
                continue;
            }
            
            // Calculate and output result
            float exchangeRate = database_[closestDate];
            float result = value * exchangeRate;
            
            std::cout << date << " => " << value << " = " << result << std::endl;
        }
        else {
            std::cerr << "Error: bad input => " << line << std::endl;
        }
    }
    
    file.close();
    return true;
}