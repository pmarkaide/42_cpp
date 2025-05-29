/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 19:12:16 by pmarkaid          #+#    #+#             */
/*   Updated: 2025/05/29 16:22:52 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
    if (!parseDatabase("data.csv")) {
        std::cerr << "Error: could not open default database file." << std::endl;
    }
}

BitcoinExchange::BitcoinExchange(const std::string& databaseFile) {
    if (!parseDatabase(databaseFile)) {
        std::cerr << "Error: could not open database file: " << databaseFile << std::endl;
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

std::string BitcoinExchange::trim(const std::string& str) const {
    size_t first = str.find_first_not_of(" \t");
    if (first == std::string::npos) {
        return "";
    }
    size_t last = str.find_last_not_of(" \t");
    return str.substr(first, (last - first + 1));
}

bool BitcoinExchange::isNumeric(const std::string& str) const {
    std::istringstream ss(str);
    float value;
    ss >> value;
    return !ss.fail() && ss.eof();
}

bool BitcoinExchange::parseDatabase(const std::string& filename) {
    std::ifstream file(filename);
    
    if (!file.is_open()) {
        return false;
    }
    
    std::string line;
    std::getline(file, line);
    
    while (std::getline(file, line)) {
        std::istringstream ss(line);
        std::string date;
        std::string rateStr;
        
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

bool BitcoinExchange::isValidDate(const std::string& date) const {
    if (date.length() != 10 || date[4] != '-' || date[7] != '-') {
        return false;
    }
    
    try {
        std::string yearStr = date.substr(0, 4);
        std::string monthStr = date.substr(5, 2);
        std::string dayStr = date.substr(8, 2);
        
        if (!std::all_of(yearStr.begin(), yearStr.end(), ::isdigit) ||
            !std::all_of(monthStr.begin(), monthStr.end(), ::isdigit) ||
            !std::all_of(dayStr.begin(), dayStr.end(), ::isdigit)) {
            return false;
        }
        
        int year = std::stoi(yearStr);
        int month = std::stoi(monthStr);
        int day = std::stoi(dayStr);
        
        if (year < 1000 || year > 9999) return false;
        if (month < 1 || month > 12) return false;
        if (day < 1 || day > 31) return false;
        
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

bool BitcoinExchange::isValidValue(const std::string& valueStr, float& value) const {
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

// Find closest date <= query date using binary search
std::string BitcoinExchange::findClosestDate(const std::string& date) const {
    auto it = database_.lower_bound(date);
    
    if (it != database_.end() && it->first == date) {
        return it->first;
    }
    
    if (it == database_.begin()) {
        return "";
    }
    
    --it;
    return it->first;
}

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
        if (isFirstLine) {
            isFirstLine = false;
            if (line != "date | value") {
                std::cerr << "Error: bad input => " << line << std::endl;
                continue;
            }
            continue;
        }
        
        if (line.empty()) {
            continue;
        }
        
        size_t pipePos = line.find('|');
        
        if (pipePos == std::string::npos) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        
        // Reject multiple pipes
        if (line.find('|', pipePos + 1) != std::string::npos) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        
        std::string dateStr = trim(line.substr(0, pipePos));
        std::string valueStr = trim(line.substr(pipePos + 1));
        
        if (dateStr.empty() || valueStr.empty()) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        
        if (!isValidDate(dateStr)) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        
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
        
        std::string closestDate = findClosestDate(dateStr);
        if (closestDate.empty()) {
            std::cerr << "Error: no data available for date " << dateStr << std::endl;
            continue;
        }
        
        float exchangeRate = database_[closestDate];
        float result = value * exchangeRate;
        
        std::cout << dateStr << " => " << value << " = " << result << std::endl;
    }
    
    file.close();
    return true;
}

void BitcoinExchange::printDatabase() const {
    std::cout << "Database contents:" << std::endl;
    for (const auto& entry : database_) {
        std::cout << entry.first << ": " << entry.second << std::endl;
    }
}

bool BitcoinExchange::isDatabaseEmpty() const {
    return database_.empty();
}