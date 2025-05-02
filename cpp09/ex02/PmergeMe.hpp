/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 12:35:24 by pmarkaid          #+#    #+#             */
/*   Updated: 2025/05/02 13:24:54 by pmarkaid         ###   ########.fr       */
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
#include <list>

// Jacobsthal number calculation
inline size_t getJacobsthalNumber(size_t n) {
    // Formula: (2^(n+1) - (-1)^n) / 3
    double pow2 = std::pow(2, n + 1);
    double powNeg1 = (n % 2 == 0) ? 1 : -1;
    return static_cast<size_t>((pow2 - powNeg1) / 3);
}

// Generate Jacobsthal sequence up to limit
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
    typedef typename Container::iterator Iterator;
    
    // Check if input string has only digits
    bool isValidInput(const std::string& input) {
        if (std::any_of(input.begin(), input.end(), [](char c) { return !std::isdigit(c); })) {
            return false;
        }
        
        try {
            long num = std::stol(input);
            return (num > 0 && num <= INT_MAX);
        } catch (const std::exception&) {
            return false;
        }
    }
    
    // Print container for debugging
    void printContainer(const Container& cont, const std::string& label, size_t chunkSize = 1) {
        if (!debug_) return;

        std::cout << label << ": ";
        size_t count = 0;
        for (const ValueType& val : cont) {
            std::cout << val << " ";
            count++;
            if (count % chunkSize == 0 && count != cont.size()) {
                std::cout << "| ";
            }
        }
        std::cout << std::endl;
    }
    
    // Comparison function with counter
    bool compare(const ValueType& a, const ValueType& b) {
        comparisons_++;
        return a < b;
    }
    
    // Recursive Ford-Johnson sort implementation
    void fordJohnsonSort(Container& container, size_t chunkSize = 1) {
        if (container.size() <= 1) return;
        
        if (debug_) {
            std::cout << "\n--- Starting recursion with chunk size: " << chunkSize << " ---\n";
            printContainer(container, "Current array", chunkSize);
        }
        
        // Base case: if we can't form pairs of chunks anymore
        if (container.size() < 2 * chunkSize) {
            if (debug_) {
                std::cout << "Reached base case, returning\n";
            }
            return;
        }
        
        // Step 1: Form pairs of chunks and sort them
        std::vector<std::pair<Iterator, Iterator>> pairs;
        bool hasOdd = false;
        Iterator oddStart;
        
        // Group elements into pairs of chunks
        for (Iterator it = container.begin(); it != container.end(); ) {
            Iterator chunkStart1 = it;
            
            // Advance to end of first chunk
            for (size_t i = 0; i < chunkSize && it != container.end(); ++i) {
                ++it;
            }
            
            // Check if we have room for a second chunk
            if (std::distance(it, container.end()) >= static_cast<long>(chunkSize)) {
                Iterator chunkStart2 = it;
                
                // Advance to end of second chunk
                for (size_t i = 0; i < chunkSize && it != container.end(); ++i) {
                    ++it;
                }
                
                pairs.push_back(std::make_pair(chunkStart1, chunkStart2));
            }
            else {
                // We have an odd chunk
                hasOdd = true;
                oddStart = chunkStart1;
                break;
            }
        }
        
        if (debug_) {
            std::cout << "Formed " << pairs.size() << " pairs of chunks\n";
            if (hasOdd) std::cout << "Has odd chunk: Yes\n";
        }
        
        // Sort each pair by comparing the largest elements in each chunk
        for (auto& pair : pairs) {
            Iterator max1 = std::max_element(pair.first, 
                std::next(pair.first, std::min(static_cast<size_t>(std::distance(pair.first, container.end())), chunkSize)));
            Iterator max2 = std::max_element(pair.second, 
                std::next(pair.second, std::min(static_cast<size_t>(std::distance(pair.second, container.end())), chunkSize)));
                
            if (compare(*max2, *max1)) {
                // Swap the chunks
                for (size_t i = 0; i < chunkSize; ++i) {
                    if (std::next(pair.first, i) != container.end() && 
                        std::next(pair.second, i) != container.end()) {
                        std::iter_swap(std::next(pair.first, i), std::next(pair.second, i));
                    }
                }
            }
        }
        
        if (debug_) {
            std::cout << "After sorting pairs:\n";
            printContainer(container, "Updated array", chunkSize);
        }
        
        // Recursive call with double chunk size
        fordJohnsonSort(container, chunkSize * 2);
        
        if (debug_) {
            std::cout << "\n--- Returned to chunk size: " << chunkSize << " ---\n";
            printContainer(container, "Array after recursion", chunkSize);
        }
        
        // Now handle merge-insertion for current chunk size
        Container result;
        Container pend;
        
        // Build the main chain: first b1 chunk, then all a chunks
        auto it = container.begin();
        
        // Add first b chunk (first chunk of first pair)
        for (size_t i = 0; i < chunkSize && it != container.end(); ++i) {
            result.push_back(*it++);
        }
        
        // Add all a chunks (second chunks of all pairs)
        for (size_t pairIdx = 0; pairIdx < pairs.size(); ++pairIdx) {
            Iterator aStart = pairs[pairIdx].second;
            for (size_t i = 0; i < chunkSize && aStart != container.end(); ++i) {
                result.push_back(*aStart++);
            }
        }
        
        // Build the pend chain: all remaining b chunks (except b1)
        for (size_t pairIdx = 1; pairIdx < pairs.size(); ++pairIdx) {
            Iterator bStart = pairs[pairIdx].first;
            for (size_t i = 0; i < chunkSize && bStart != container.end(); ++i) {
                pend.push_back(*bStart++);
            }
        }
        
        // Add odd chunk to pend if exists
        if (hasOdd) {
            Iterator it = oddStart;
            for (size_t i = 0; i < chunkSize && it != container.end(); ++i) {
                pend.push_back(*it++);
            }
        }
        
        if (debug_) {
            printContainer(result, "Main chain", chunkSize);
            printContainer(pend, "Pend chain", chunkSize);
        }
        
        // Calculate Jacobsthal-based insertion order
        std::vector<size_t> insertOrder;
        std::vector<size_t> jacobsthalNumbers = getJacobsthalSequence(pairs.size());
        
        size_t prevJac = 1; // Start from 1 (first element already processed)
        for (size_t jac : jacobsthalNumbers) {
            if (jac <= pairs.size()) {
                // Add the Jacobsthal number
                insertOrder.push_back(jac);
                
                // Add indices between current and previous Jacobsthal in reverse
                for (size_t i = jac - 1; i > prevJac; --i) {
                    insertOrder.push_back(i);
                }
                
                prevJac = jac;
            }
        }
        
        // Add any remaining indices in reverse
        for (size_t i = pairs.size(); i > prevJac; --i) {
            insertOrder.push_back(i);
        }
        
        if (debug_) {
            std::cout << "Insertion order: ";
            for (size_t idx : insertOrder) std::cout << idx << " ";
            std::cout << std::endl;
        }
        
        // Perform insertions in Jacobsthal order
        size_t pendChunkPos = 0;
        for (size_t idx : insertOrder) {
            if (idx > 1 && idx <= pairs.size()) {
                size_t chunkIdx = idx - 2; // Adjust for 0-based indexing and skipping first pair
                
                // Calculate position in pend for the current chunk
                size_t pendPos = chunkIdx * chunkSize;
                
                // Create a temporary container for the chunk we want to insert
                Container chunkToInsert;
                for (size_t offset = 0; offset < chunkSize && pendPos + offset < pend.size(); ++offset) {
                    chunkToInsert.push_back(pend[pendPos + offset]);
                }
                
                if (chunkToInsert.empty()) continue;
                
                // Calculate bound for binary search
                // The bound is (idx)*chunkSize elements, which includes
                // b1 and all a chunks up to idx
                size_t bound = std::min(result.size(), (idx) * chunkSize);
                
                // Find the insertion position based on the first element in the chunk
                // But ensure we only insert at chunk boundaries
                auto boundIt = result.begin() + bound;
                auto pos = std::lower_bound(result.begin(), boundIt, chunkToInsert.front(), 
                          [this](const ValueType& a, const ValueType& b) { return this->compare(a, b); });
                
                // Adjust to ensure we're at a chunk boundary
                size_t distance = std::distance(result.begin(), pos);
                size_t chunkBoundary = (distance / chunkSize) * chunkSize;
                pos = result.begin() + chunkBoundary;
                
                // If the insertion point is the same as the bound, we should insert at the end of the bound
                if (pos == boundIt) {
                    // Insert at the end of the current bound
                    result.insert(pos, chunkToInsert.begin(), chunkToInsert.end());
                } else {
                    // Compare with the chunk at the position
                    auto nextChunkPos = pos + chunkSize;
                    if (nextChunkPos <= boundIt && 
                        this->compare(chunkToInsert.front(), *pos)) {
                        // Insert before this chunk
                        result.insert(pos, chunkToInsert.begin(), chunkToInsert.end());
                    } else {
                        // Insert after this chunk
                        pos += chunkSize;
                        result.insert(pos, chunkToInsert.begin(), chunkToInsert.end());
                    }
                }
                
                if (debug_) {
                    std::cout << "Inserted chunk at position " 
                              << chunkBoundary << std::endl;
                }
                
                pendChunkPos += chunkSize;
            }
        }
        
        // Handle odd chunk if it exists
        if (hasOdd) {
            // Find position for odd chunk - use binary insertion for each element
            for (size_t i = pairs.size() * chunkSize; i < pend.size(); ++i) {
                ValueType val = pend[i];
                
                // Use binary search for insertion position
                auto pos = std::lower_bound(result.begin(), result.end(), val,
                           [this](const ValueType& a, const ValueType& b) { return this->compare(a, b); });
                
                result.insert(pos, val);
                
                if (debug_) {
                    std::cout << "Inserted odd element " << val << " at position " 
                              << std::distance(result.begin(), pos) << std::endl;
                }
            }
        }
        
        // Update the original container
        container = result;
        
        if (debug_) {
            printContainer(container, "Sorted at current level", chunkSize);
        }
    }
    
public:
    Container vec_;
    
    PmergeMe() : debug_(false), comparisons_(0) {}
    PmergeMe(bool debug) : debug_(debug), comparisons_(0) {}
    ~PmergeMe() {}
    
    void setDebug(bool debug) { debug_ = debug; }
    int getComparisons() const { return comparisons_; }
    
    // Parse command-line arguments
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
    
    // Display container
    void display(const std::string& prefix) const {
        std::cout << prefix;
        for (const ValueType& num : vec_) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
    
    // Sort entry point

	typedef std::vector<ValueType> Chunk;

    void sort(Container& container) {
        comparisons_ = 0; // Reset comparison counter
        
        if (container.size() <= 1) return; // Already sorted
        
        // Start the Ford-Johnson / Merge-Insert Sort with chunk size 1
        fordJohnsonSort(container);
        
        if (debug_) {
            std::cout << "Total comparisons: " << comparisons_ << std::endl;
        }
    }
};

#endif