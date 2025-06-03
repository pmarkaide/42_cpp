/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 12:40:12 by pmarkaid          #+#    #+#             */
/*   Updated: 2025/06/03 20:06:53 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <vector>
#include <deque>
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

template<typename Container>
Container parseArguments(int argc, char* argv[]) {
    Container numbers;
    
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

template<typename Container>
bool isSorted(const Container& arr) {
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
        
        std::vector<int> numbers_vec = parseArguments<std::vector<int>>(argc, argv);
        std::deque<int> numbers_deq = parseArguments<std::deque<int>>(argc, argv);
        
        if (numbers_vec.empty()) {
            std::cerr << "Error: no valid numbers to sort" << std::endl;
            return 1;
        }
        
        PmergeMe sorter;
        
        std::cout << "Before: ";
        sorter.printContainer(numbers_vec);
        
        // Sort with vector
        auto start_vec = std::chrono::high_resolution_clock::now();
        std::vector<int> sorted_vec = sorter.fordJohnsonSort(numbers_vec);
        auto end_vec = std::chrono::high_resolution_clock::now();
        auto duration_vec = std::chrono::duration_cast<std::chrono::microseconds>(end_vec - start_vec);
        
        // Sort with deque
        auto start_deq = std::chrono::high_resolution_clock::now();
        std::deque<int> sorted_deq = sorter.fordJohnsonSort(numbers_deq);
        auto end_deq = std::chrono::high_resolution_clock::now();
        auto duration_deq = std::chrono::duration_cast<std::chrono::microseconds>(end_deq - start_deq);
        
        std::cout << "After: ";
        sorter.printContainer(sorted_vec);
        
        std::cout << "Time to process a range of " << numbers_vec.size() 
                  << " elements with std::vector : " << duration_vec.count() << " us" << std::endl;
        std::cout << "Time to process a range of " << numbers_deq.size() 
                  << " elements with std::deque : " << duration_deq.count() << " us" << std::endl;
        
        if (!isSorted(sorted_vec) || !isSorted(sorted_deq)) {
            std::cerr << "Error: sorting failed" << std::endl;
            return 1;
        }
        
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}