/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 19:12:29 by pmarkaid          #+#    #+#             */
/*   Updated: 2025/05/20 19:45:32 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <chrono>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <cctype>
#include <stdexcept>

class BitcoinExchange {
private:
    // Container to store bitcoin exchange rates by date
    std::map<std::string, float> database_;
    
    // Private methods
    bool isValidDate(const std::string& date) const;
    bool isValidValue(const std::string& valueStr, float& value) const;
    bool parseDatabase(const std::string& filename);
    std::string findClosestDate(const std::string& date) const;
    
    // String utilities
    std::string trim(const std::string& str) const;
    bool isNumeric(const std::string& str) const;
    
public:
    // Orthodox Canonical Form
    BitcoinExchange(); // Default constructor
    BitcoinExchange(const std::string& databaseFile); // Parameterized constructor
    BitcoinExchange(const BitcoinExchange& other); // Copy constructor
    BitcoinExchange& operator=(const BitcoinExchange& other); // Copy assignment operator
    ~BitcoinExchange(); // Destructor
    
    // Public methods
    bool processInputFile(const std::string& inputFile);
    
    // Debug/Testing methods
    void printDatabase() const;
    bool isDatabaseEmpty() const;
};

#endif