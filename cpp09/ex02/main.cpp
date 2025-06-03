/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 12:40:12 by pmarkaid          #+#    #+#             */
/*   Updated: 2025/06/03 19:54:03 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <climits>
#include <stdexcept>
#include <chrono>

bool isValidNumber(const std::string& str) {
    if (str.empty()) return false;
    
    for (char c : str) {
        if (!std::isdigit(c)) return false;
    }
    return true;
}

bool isInputValid(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Error: no arguments provided" << std::endl;
        return false;
    }

    for (int i = 1; i < argc; i++) {
        std::string arg(argv[i]);
        if (!isValidNumber(arg)) {
            std::cerr << "Error: invalid input" << std::endl;
            return false;
        }
    }
    
    return true;
}

std::vector<int> parseArguments(int argc, char* argv[]) {
    std::vector<int> numbers;
    
    for (int i = 1; i < argc; i++) {
        std::string arg(argv[i]);
        std::stringstream ss(arg);
        long long num;
        
        ss >> num;
        
        if (num <= 0) {
            throw std::invalid_argument("Error: only positive numbers are allowed");
        }
        
        if (num > INT_MAX) {
            throw std::invalid_argument("Error: number exceeds maximum integer value");
        }
        
        int value = static_cast<int>(num);
        
        if (std::find(numbers.begin(), numbers.end(), value) != numbers.end()) {
            throw std::invalid_argument("Error: duplicate values are not allowed");
        }
        
        numbers.push_back(value);
    }
    
    return numbers;
}

bool isSorted(const std::vector<int>& arr) {
    for (size_t i = 1; i < arr.size(); i++) {
        if (arr[i - 1] > arr[i]) {
            return false;
        }
    }
    return true;
}

int main(int argc, char* argv[]) {
    try {
        if (!isInputValid(argc, argv)) {
            return 1;
        }
        
        std::vector<int> numbers = parseArguments(argc, argv);
        
        if (numbers.empty()) {
            std::cerr << "Error: no valid numbers to sort" << std::endl;
            return 1;
        }
        
        PmergeMe sorter;
        
        std::cout << "Before: ";
        sorter.printVector(numbers);
        
        auto start = std::chrono::high_resolution_clock::now();
        std::vector<int> sorted = sorter.fordJohnsonSort(numbers);
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        
        std::cout << "After: ";
        sorter.printVector(sorted);
        
        std::cout << "Time to process a range of " << numbers.size() 
                  << " elements with std::vector : " << duration.count() << " us" << std::endl;
        
        if (!isSorted(sorted)) {
            std::cerr << "Error: sorting failed" << std::endl;
            return 1;
        }
        
        std::cout << "Sort verification: PASSED" << std::endl;
        
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}