/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 20:40:21 by pmarkaid          #+#    #+#             */
/*   Updated: 2025/04/29 21:46:57 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include "easyfind.hpp"

int main()
{
    // Test with vector
    std::vector<int> vec = {1, 2, 3, 4, 5};
    std::cout << "=== Testing with vector ===" << std::endl;
    
    try {
        auto result = easyfind(vec, 3);
        std::cout << "Found value: " << *result << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
	std::cout << "\n=== Testing with vector: not found error ===" << std::endl;
    try {
        auto result = easyfind(vec, 10);  // Value not in vector
        std::cout << "Found value: " << *result << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    // Test with list
    std::list<int> lst = {10, 20, 30, 40, 50};
    std::cout << "\n=== Testing with list ===" << std::endl;
    
    try {
        auto result = easyfind(lst, 30);
        std::cout << "Found value: " << *result << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    // Test with deque
    std::deque<int> deq = {100, 200, 300, 400};
    std::cout << "\n=== Testing with deque ===" << std::endl;
    
    try {
        auto result = easyfind(deq, 200);
        std::cout << "Found value: " << *result << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    // Test with empty container
    std::vector<int> empty_vec;
    std::cout << "\n=== Testing with empty vector ===" << std::endl;
    
    try {
        auto result = easyfind(empty_vec, 5);
        std::cout << "Found value: " << *result << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    return 0;
}