/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 12:35:24 by pmarkaid          #+#    #+#             */
/*   Updated: 2025/05/02 10:50:11 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <vector>
#include <deque>
#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <climits>
#include <algorithm>
#include <ctime>

// Jacobsthal number calculation
size_t getJacobsthalNumber(size_t n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return getJacobsthalNumber(n - 1) + 2 * getJacobsthalNumber(n - 2);
}

// Get Jacobsthal sequence up to a certain limit
std::vector<size_t> getJacobsthalSequence(size_t limit) {
    std::vector<size_t> sequence;
    size_t n = 3; // Start from 3rd Jacobsthal number (3)
    
    while (true) {
        size_t jacobsthal = getJacobsthalNumber(n);
        if (jacobsthal > limit) break;
        sequence.push_back(jacobsthal);
        n++;
    }
    
    return sequence;
}

template <typename Container>
class PmergeMe {
private:   
    bool isValidInput(const std::string& input) {
        // Check if input string has only digits
        if (std::any_of(input.begin(), input.end(), [](char c) { return !std::isdigit(c); })) {
            return false;
        }
        
        try {
            // Use stol with exception handling for out-of-range values
            long num = std::stol(input);
            return (num > 0 && num <= INT_MAX);
        } catch (const std::exception&) {
            return false;
        }
    }
    
    // Helper function to advance iterator
    template <typename Iterator>
    Iterator advanceIterator(Iterator it, int steps) {
        Iterator result = it;
        std::advance(result, steps);
        return result;
    }
    
public:
    Container vec_;
    typedef typename Container::value_type ValueType;
    typedef typename Container::iterator Iterator;
    
    PmergeMe() {}
    
    PmergeMe(const Container& container) : vec_(container) {}
    
    PmergeMe(const PmergeMe& src) : vec_(src.vec_) {}
    
    PmergeMe& operator=(const PmergeMe& src) {
        if (this != &src) {
            vec_ = src.vec_;
        }
        return *this;
    }
    
    ~PmergeMe() {}
    
    bool parseArguments(int argc, char **argv) {
        if (argc < 2) {
            return false;
        }
        
        for (int i = 1; i < argc; i++) {
            std::string arg = argv[i];
            
            if (!isValidInput(arg)) {
                return false;
            }
            
            int num = std::stoi(arg);
            
            if (std::find(vec_.begin(), vec_.end(), num) != vec_.end()) {
                return false;
            }
            
            vec_.push_back(num);
        }
        
        return true;
    }
    
    Iterator begin() { return vec_.begin(); }
    Iterator end() { return vec_.end(); }
    
    void display(const std::string& prefix) const {
        std::cout << prefix;
        for (auto num : vec_) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }

    // First phase: sort pairs by comparing larger elements
    void sortPairs(Container& container, int order = 1) {
        // Base case: if elements per group is too small or equal to container size
        size_t element_size = container.size() / order;
        if (element_size < 2) return;
        
        bool is_odd = element_size % 2 == 1;
        Iterator start = vec_.begin();
        Iterator end = vec_.begin() + ((order * element_size) - (is_odd * order));
    
        for (Iterator it = start; it < end; it += (order * 2)) {
            if (*(it + (order - 1)) > *(it + ((order * 2) - 1))) {
                for (int i = 0; i < order; i++) {
                    std::swap(*(it + i), *(it + i + order));
                }
            }
        }
        
        sortPairs(container, order * 2);
    }
    
    // Second phase: merge-insertion using Jacobsthal numbers
    void mergeInsert(Container& container) {
        if (container.size() <= 1) return;
        
        // Create pairs and handle odd element
        bool hasOddElement = container.size() % 2 == 1;
        ValueType oddElement = hasOddElement ? container.back() : ValueType();
        
        std::vector<std::pair<ValueType, ValueType>> pairs;
        for (size_t i = 0; i < container.size() - hasOddElement; i += 2) {
            ValueType a = container[i];
            ValueType b = container[i + 1];
            if (a > b) std::swap(a, b);
            pairs.push_back(std::make_pair(a, b));
        }
        
        // Sort by second element (larger elements)
        std::sort(pairs.begin(), pairs.end(), 
                 [](const std::pair<ValueType, ValueType>& a, const std::pair<ValueType, ValueType>& b) {
                     return a.second < b.second;
                 });
        
        // Main chain starts with the first pair
        Container main;
        main.push_back(pairs[0].first);
        main.push_back(pairs[0].second);
        
        // Add all second elements to main chain
        std::vector<ValueType> pend;
        for (size_t i = 1; i < pairs.size(); i++) {
            pend.push_back(pairs[i].first);  // Store smaller elements for insertion
            main.push_back(pairs[i].second); // Add larger elements to the sorted chain
        }
        
        // Add odd element to pend if it exists
        if (hasOddElement) {
            pend.push_back(oddElement);
        }
        
        // Generate Jacobsthal insertion sequence
        std::vector<size_t> jacobsthalIndices = getJacobsthalSequence(pend.size());
        
        // Insert pending elements using binary search and Jacobsthal numbers
        std::vector<size_t> insertionOrder;
        for (size_t i = 0; i < jacobsthalIndices.size(); i++) {
            size_t idx = jacobsthalIndices[i] - 1;
            if (idx < pend.size() && std::find(insertionOrder.begin(), insertionOrder.end(), idx) == insertionOrder.end()) {
                insertionOrder.push_back(idx);
            }
            
            // Add indices between current and previous Jacobsthal number
            size_t prev = (i == 0) ? 0 : jacobsthalIndices[i-1];
            for (size_t j = idx - 1; j >= prev && j < pend.size(); j--) {
                if (std::find(insertionOrder.begin(), insertionOrder.end(), j) == insertionOrder.end()) {
                    insertionOrder.push_back(j);
                }
                if (j == 0) break;  // Avoid underflow
            }
        }
        
        // Add any remaining indices
        for (size_t i = 0; i < pend.size(); i++) {
            if (std::find(insertionOrder.begin(), insertionOrder.end(), i) == insertionOrder.end()) {
                insertionOrder.push_back(i);
            }
        }
        
        // Insert elements from pend into the main
        for (size_t idx : insertionOrder) {
            if (idx >= pend.size()) continue;
            
            ValueType value = pend[idx];
            typename Container::iterator pos = std::lower_bound(main.begin(), main.end(), value);
            main.insert(pos, value);
        }
        
        // Update the original container
        container = main;
    }
    
    // Complete Ford-Johnson sort
    void sort(Container& container) {
        if (container.size() <= 1) return;

        // Phase 1: Sort pairs
        sortPairs(container);

        // Display after pair sorting
        // std::cout << "After pair sort: ";
        // for (auto num : container) std::cout << num << " ";
        // std::cout << std::endl;

        // Phase 2: Merge insertion with Jacobsthal numbers
        mergeInsert(container);
    }
};

template <typename Container>
std::ostream& operator<<(std::ostream& os, const PmergeMe<Container>& obj) {
    for (auto num : obj.vec_) {
        os << num << " ";
    }
    return os;
}

#endif