/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 12:35:24 by pmarkaid          #+#    #+#             */
/*   Updated: 2025/05/02 11:23:14 by pmarkaid         ###   ########.fr       */
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
#include <cmath>

// Efficient Jacobsthal number calculation
inline size_t getJacobsthalNumber(size_t n) {
    // Formula: (2^(n+1) - (-1)^n) / 3
    double pow2 = std::pow(2, n + 1);
    double powNeg1 = (n % 2 == 0) ? 1 : -1;
    return static_cast<size_t>((pow2 - powNeg1) / 3);
}

// Get Jacobsthal sequence up to a certain limit
inline std::vector<size_t> getJacobsthalSequence(size_t limit) {
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
    bool debug_; // Debug flag for printing
    int comparisons_; // Count comparisons for testing
    
    typedef typename Container::value_type ValueType;
    
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
    
    // Print container with optional markers
    void printContainer(const Container& cont, const std::string& label) {
        if (!debug_) return;
        
        std::cout << label << ": ";
        for (const ValueType& val : cont) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
    
    // Comparison function that counts comparisons
    bool compare(const ValueType& a, const ValueType& b) {
        comparisons_++;
        return a < b;
    }
    
    // Custom comparison for pairs
    struct PairCompare {
        PmergeMe* sorter;
        
        PairCompare(PmergeMe* s) : sorter(s) {}
        
        bool operator()(const std::pair<ValueType, ValueType>& p1, 
                         const std::pair<ValueType, ValueType>& p2) const {
            return sorter->compare(p1.second, p2.second);
        }
    };
    
    // Custom comparator for binary search
    struct ValueCompare {
        PmergeMe* sorter;
        
        ValueCompare(PmergeMe* s) : sorter(s) {}
        
        bool operator()(const ValueType& a, const ValueType& b) const {
            return sorter->compare(a, b);
        }
    };
    
public:
    Container vec_;
    
    PmergeMe() : debug_(false), comparisons_(0) {}
    PmergeMe(bool debug) : debug_(debug), comparisons_(0) {}
    ~PmergeMe() {}
    
    void setDebug(bool debug) { debug_ = debug; }
    int getComparisons() const { return comparisons_; }
    
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
            
            // Check for duplicates
            if (std::find(vec_.begin(), vec_.end(), num) != vec_.end()) {
                return false;
            }
            
            vec_.push_back(num);
        }
        
        return true;
    }
    
    void display(const std::string& prefix) const {
        std::cout << prefix;
        for (const ValueType& num : vec_) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
    
    // Ford-Johnson / Merge-Insert Sort
    void sort(Container& container) {
        comparisons_ = 0; // Reset comparison counter
        
        if (container.size() <= 1) return; // Already sorted
        
        if (debug_) {
            printContainer(container, "Original array");
        }
        
        // Step 1: Make pairs and sort them
        bool hasOdd = (container.size() % 2 == 1);
        ValueType oddElement;
        
        if (hasOdd) {
            oddElement = container.back();
            container.pop_back();
        }
        
        // Create sorted pairs
        std::vector<std::pair<ValueType, ValueType>> pairs;
        for (size_t i = 0; i < container.size(); i += 2) {
            ValueType a = container[i];
            ValueType b = container[i + 1];
            
            if (compare(b, a)) {
                std::swap(a, b);
            }
            
            pairs.push_back(std::make_pair(a, b)); // a is smaller, b is larger
        }
        
        // Step 2: Sort pairs by their larger element (b values)
        std::sort(pairs.begin(), pairs.end(), PairCompare(this));
        
        // Step 3: Create main and pend chains
        Container main;
        Container pend;
        
        // Add first element of first pair to main (smallest element)
        main.push_back(pairs[0].first);
        
        // Add all larger elements to main (b values)
        for (const std::pair<ValueType, ValueType>& p : pairs) {
            main.push_back(p.second);
        }
        
        // Add all remaining smaller elements to pend (a values except first one)
        for (size_t i = 1; i < pairs.size(); i++) {
            pend.push_back(pairs[i].first);
        }
        
        // Add odd element to pend if exists
        if (hasOdd) {
            pend.push_back(oddElement);
        }
        
        if (debug_) {
            printContainer(main, "Main chain");
            printContainer(pend, "Pend chain");
        }
        
        // Step 4: Insert pend elements into main using Jacobsthal order
        std::vector<size_t> insertOrder;
        
        // Calculate insertion order based on Jacobsthal numbers
        std::vector<size_t> jacobsthalNumbers = getJacobsthalSequence(pend.size() + 1);
        
        size_t prevJac = 1; // Start from 1 (first element already processed)
        for (size_t jac : jacobsthalNumbers) {
            if (jac <= pend.size()) {
                insertOrder.push_back(jac);
                
                // Add indices between current and previous Jacobsthal number in reverse
                for (size_t i = jac - 1; i > prevJac; i--) {
                    insertOrder.push_back(i);
                }
                
                prevJac = jac;
            }
        }
        
        // Add any remaining indices in reverse
        for (size_t i = pend.size(); i > prevJac; i--) {
            insertOrder.push_back(i);
        }
        
        if (debug_) {
            std::cout << "Insertion order: ";
            for (size_t idx : insertOrder) std::cout << idx << " ";
            std::cout << std::endl;
        }
        
        // Step 5: Perform insertions according to calculated order
        for (size_t idx : insertOrder) {
            if (idx > 0 && idx <= pend.size()) {
                size_t pendIdx = idx - 1; // Convert to 0-based index
                ValueType val = pend[pendIdx];
                
                // Find insertion position using binary search with bound
                size_t bound = std::min(main.size(), idx + 1); // Bound according to the algorithm
                
                typename Container::iterator boundIt = main.begin() + bound;
                typename Container::iterator pos = std::lower_bound(main.begin(), boundIt, val, ValueCompare(this));
                
                size_t insertPos = std::distance(main.begin(), pos);
                main.insert(pos, val);
                
                if (debug_) {
                    std::cout << "Inserted " << val << " at position " << insertPos << std::endl;
                    printContainer(main, "Main after insertion");
                }
            }
        }
        
        // Update the original container
        container = main;
        
        if (debug_) {
            printContainer(container, "Sorted array");
            std::cout << "Total comparisons: " << comparisons_ << std::endl;
        }
    }
};

#endif