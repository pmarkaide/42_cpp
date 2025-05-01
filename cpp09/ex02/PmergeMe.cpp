/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 12:35:12 by pmarkaid          #+#    #+#             */
/*   Updated: 2025/05/01 14:44:15 by pmarkaid         ###   ########.fr       */
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

bool PmergeMe::parseArguments(int argc, char **argv) {
    if (argc < 2) {
        return false;
    }
    
    for (int i = 1; i < argc; i++) {
        std::string arg = argv[i];
        
        if (!isValidInput(arg)) {
            return false;
        }
        
        int num = std::stoi(arg);
        
        // Check for duplicates using modern algorithms
        if (std::find(_numbers_vec.begin(), _numbers_vec.end(), num) != _numbers_vec.end()) {
            return false;
        }
        
        // Use emplace_back instead of push_back
        _numbers_vec.emplace_back(num);
        _numbers_deq.emplace_back(num);
    }
    
    return true;
}

