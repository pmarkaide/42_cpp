/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 12:40:12 by pmarkaid          #+#    #+#             */
/*   Updated: 2025/05/02 14:52:23 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <chrono>

int main(int argc, char **argv) {
    // Check for debug flag
    bool debug = false;
    for (int i = 1; i < argc; ++i) {
        if (std::string(argv[i]) == "--debug") {
            debug = true;
            // Remove debug flag from arguments
            for (int j = i; j < argc - 1; ++j) {
                argv[j] = argv[j + 1];
            }
            argc--;
            break;
        }
    }
    
    // Initialize containers
    PmergeMe<std::vector<int>> vec_sorter;
    PmergeMe<std::deque<int>> deq_sorter;
    
    vec_sorter.setDebug(debug);
    deq_sorter.setDebug(debug);
    
    // Parse arguments
    if (!vec_sorter.parseArguments(argc, argv)) {
        std::cerr << "Error: enter at least 2 non duplicated positive numbers (up to INT_MAX)" << std::endl;
        std::cerr << "Usage: ./PmergeMe 2 13 15 4" << std::endl;
        std::cerr << "Add --debug flag for detailed output" << std::endl;
        return 1;
    }
    
    // Copy arguments to deque sorter
    deq_sorter.vec_ = std::deque<int>(vec_sorter.vec_.begin(), vec_sorter.vec_.end());
    
    // Display unsorted sequence
    std::cout << "Before: ";
    size_t displayLimit = 10;
    size_t displayCount = vec_sorter.vec_.size() <= displayLimit ? vec_sorter.vec_.size() : displayLimit;
    
    for (size_t i = 0; i < displayCount; ++i) {
        std::cout << vec_sorter.vec_[i] << " ";
    }
    
    if (vec_sorter.vec_.size() > displayLimit) {
        std::cout << "[...]";
    }
    std::cout << std::endl;
    
    // Make copies for sorting
    std::vector<int> vec_copy = vec_sorter.vec_;
    std::deque<int> deq_copy = deq_sorter.vec_;
    
    // Sort with vector
    auto vec_start = std::chrono::high_resolution_clock::now();
    vec_sorter.sort(vec_copy);
    auto vec_end = std::chrono::high_resolution_clock::now();
    auto vec_time = std::chrono::duration_cast<std::chrono::microseconds>(vec_end - vec_start).count();
    
    // Sort with deque
    auto deq_start = std::chrono::high_resolution_clock::now();
    deq_sorter.sort(deq_copy);
    auto deq_end = std::chrono::high_resolution_clock::now();
    auto deq_time = std::chrono::duration_cast<std::chrono::microseconds>(deq_end - deq_start).count();
    
    // Test if sorted correctly
    bool isSorted = true;
    for (size_t i = 1; i < vec_copy.size(); ++i) {
        if (vec_copy[i - 1] > vec_copy[i]) {
            isSorted = false;
            break;
        }
    }
    
    // Display results
    std::cout << "After:  ";
    displayCount = vec_copy.size() <= displayLimit ? vec_copy.size() : displayLimit;
    
    for (size_t i = 0; i < displayCount; ++i) {
        std::cout << vec_copy[i] << " ";
    }
    
    if (vec_copy.size() > displayLimit) {
        std::cout << "[...]";
    }
    std::cout << std::endl;
    
    // Display sort validation result with color
    std::cout << "Sort validation: " << (isSorted ? "\033[32mPASSED ✓\033[0m" : "\033[31mFAILED ✗\033[0m") << std::endl;
    
    std::cout << "Time to process a range of " << vec_copy.size() 
              << " elements with std::vector : " << vec_time << " us" << std::endl;
    std::cout << "Time to process a range of " << deq_copy.size() 
              << " elements with std::deque : " << deq_time << " us" << std::endl;
    
    if (debug) {
        std::cout << "Vector comparisons: " << vec_sorter.getComparisons() << std::endl;
        std::cout << "Deque comparisons: " << deq_sorter.getComparisons() << std::endl;
    }
    
    return 0;
}