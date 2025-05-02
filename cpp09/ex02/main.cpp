/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 12:40:12 by pmarkaid          #+#    #+#             */
/*   Updated: 2025/05/02 11:21:24 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <ctime>

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
    for (auto num : vec_sorter.vec_) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    
    // Make copies for sorting
    std::vector<int> vec_copy = vec_sorter.vec_;
    std::deque<int> deq_copy = deq_sorter.vec_;
    
    // Sort with vector
    clock_t vec_start = clock();
    vec_sorter.sort(vec_copy);
    clock_t vec_end = clock();
    double vec_time = (double)(vec_end - vec_start) / CLOCKS_PER_SEC * 1000000;
    
    // Sort with deque
    clock_t deq_start = clock();
    deq_sorter.sort(deq_copy);
    clock_t deq_end = clock();
    double deq_time = (double)(deq_end - deq_start) / CLOCKS_PER_SEC * 1000000;
    
    // Display results
    std::cout << "After: ";
    for (auto num : vec_copy) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    
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