/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 12:35:24 by pmarkaid          #+#    #+#             */
/*   Updated: 2025/05/01 15:01:27 by pmarkaid         ###   ########.fr       */
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

template <typename Container>
class PmergeMe {
private:
    Container container_;
    
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
    
public:
    typedef typename Container::value_type ValueType;
    typedef typename Container::iterator Iterator;
    
    PmergeMe() {}
    
    PmergeMe(const PmergeMe& src) : container_(src.container_) {}
    
    PmergeMe& operator=(const PmergeMe& src) {
        if (this != &src) {
            container_ = src.container_;
        }
        return *this;
    }
    
    ~PmergeMe() {}
    
    // Parse input arguments
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
            
            if (std::find(container_.begin(), container_.end(), num) != container_.end()) {
                return false;
            }
            
            container_.push_back(num);
        }
        
        return true;
    }
    
    // Iterator methods
    Iterator begin() { return container_.begin(); }
    Iterator end() { return container_.end(); }
    
    // Display container with label
    void display(const std::string& label) {
        std::cout << label;
        for (Iterator it = begin(); it != end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
    }
};

// Overload output operator for PmergeMe
template <typename Container>
std::ostream& operator<<(std::ostream& os, const PmergeMe<Container>& obj) {
    for (typename PmergeMe<Container>::Iterator it = obj.begin(); it != obj.end(); ++it) {
        os << *it << " ";
    }
    return os;
}

#endif