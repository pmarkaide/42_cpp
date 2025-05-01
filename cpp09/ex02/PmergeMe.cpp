/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 12:35:12 by pmarkaid          #+#    #+#             */
/*   Updated: 2025/05/01 12:44:45 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& src) {
    *this = src;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& src) {
    if (this != &src) {
        _numbers_vec = src._numbers_vec;
        _numbers_deq = src._numbers_deq;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

bool PmergeMe::isValidInput(const std::string& input) {
    // Check if input string has only digits
    for (size_t i = 0; i < input.length(); i++) {
        if (!isdigit(input[i])) {
            return false;
        }
    }
    
    // Check if it's within int range and positive
    long num = std::atol(input.c_str());
    if (num <= 0 || num > INT_MAX) {
        return false;
    }
    
    return true;
}

bool PmergeMe::parseArguments(int argc, char **argv) {
    if (argc < 2) {
        return false;
    }
    
    for (int i = 1; i < argc; i++) {
        std::string arg = argv[i];
        
        if (!isValidInput(arg)) {
            return false;
        }
        
        int num = std::atoi(arg.c_str());
        
        // Check for duplicates
        for (size_t j = 0; j < _numbers_vec.size(); j++) {
            if (_numbers_vec[j] == num) {
                return false;
            }
        }
        
        _numbers_vec.push_back(num);
        _numbers_deq.push_back(num);
    }
    
    return true;
}

void PmergeMe::displayBeforeSort() const {
    std::cout << "Before: ";
    for (size_t i = 0; i < _numbers_vec.size(); i++) {
        std::cout << _numbers_vec[i] << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::displayAfterSort() const {
    std::cout << "After:  ";
    for (size_t i = 0; i < _numbers_vec.size(); i++) {
        std::cout << _numbers_vec[i] << " ";
    }
    std::cout << std::endl;
}