/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 12:35:24 by pmarkaid          #+#    #+#             */
/*   Updated: 2025/05/01 14:44:49 by pmarkaid         ###   ########.fr       */
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

class PmergeMe {
private:
    std::vector<int> _numbers_vec;
    std::deque<int> _numbers_deq;

    template<typename T>
    bool isValidInput(const T& input);
    
public:
    PmergeMe();
    PmergeMe(const PmergeMe& src);
    PmergeMe& operator=(const PmergeMe& src);
    ~PmergeMe();
    
    bool parseArguments(int argc, char **argv);
    
    // Display function as a public template method
    template<typename Container>
    void displayContainer(const Container& container, const std::string& label) const;
    
    // Getter methods for containers
    const std::vector<int>& getVector() const { return _numbers_vec; }
    const std::deque<int>& getDeque() const { return _numbers_deq; }
};

template<typename T>
bool PmergeMe::isValidInput(const T& input) {
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

template<typename Container>
void PmergeMe::displayContainer(const Container& container, const std::string& label) const {
    std::cout << label;
    for (const auto& element : container) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}

#endif