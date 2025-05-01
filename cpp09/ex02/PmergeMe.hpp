/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 12:35:24 by pmarkaid          #+#    #+#             */
/*   Updated: 2025/05/01 16:18:56 by pmarkaid         ###   ########.fr       */
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

	void sort(Container& container, int order = 1) {
		
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

		std::cout << "After order " << order << ": ";
		for (size_t i = 0; i < container.size(); i++) {
			std::cout << container[i] << " ";
			if ((i + 1) % order == 0 && i < container.size() - 1) {
				std::cout << "|| ";
			}
		}
		std::cout << std::endl;
	   
		sort(container, order * 2);
	}
};

template <typename Container>
std::ostream& operator<<(std::ostream& os, const PmergeMe<Container>& obj) {
    for (typename PmergeMe<Container>::Iterator it = obj.begin(); it != obj.end(); ++it) {
        os << *it << " ";
    }
    return os;
}

#endif