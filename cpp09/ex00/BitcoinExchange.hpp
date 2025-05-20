/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 19:12:29 by pmarkaid          #+#    #+#             */
/*   Updated: 2025/05/20 19:23:35 by pmarkaid         ###   ########.fr       */
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

class BitcoinExchange {
private:
    std::map<std::string, float> database_;
    
    bool isValidDate(const std::string& date) const;
    bool isValidValue(const float value) const;
    bool parseDatabase(const std::string& filename);
    std::string findClosestDate(const std::string& date) const;
    
public:
    BitcoinExchange();
    BitcoinExchange(const std::string& databaseFile);
    BitcoinExchange(const BitcoinExchange& other);
    BitcoinExchange& operator=(const BitcoinExchange& other);
    ~BitcoinExchange();
    
    bool processInputFile(const std::string& inputFile);
};

#endif // BITCOINEXCHANGE_HPP