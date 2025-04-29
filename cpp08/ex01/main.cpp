/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 22:15:51 by pmarkaid          #+#    #+#             */
/*   Updated: 2025/04/29 22:45:26 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Span.hpp"

#include <iostream>
#include <ctime>    // For time() function
#include <cstdlib>  // For rand() and srand() functions
#include <vector>
#include "Span.hpp"

// Function to test the basic functionality
void testBasicFunctionality()
{
    std::cout << "=== Testing Basic Functionality ===" << std::endl;
    
    try {
        // Subject example
        Span sp = Span(5);
        
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
        
        // Should throw an exception (adding 6th element)
        std::cout << "Attempting to add a 6th element..." << std::endl;
        sp.addNumber(25);
    }
    catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
}

// Function to test edge cases
void testEdgeCases()
{
    std::cout << "\n=== Testing Edge Cases ===" << std::endl;
    
    // Test with empty Span
    try {
        std::cout << "Testing with empty Span:" << std::endl;
        Span emptySpan(5);
        std::cout << "Attempting to find shortest span..." << std::endl;
        emptySpan.shortestSpan();
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    // Test with single element
    try {
        std::cout << "\nTesting with single element:" << std::endl;
        Span singleSpan(5);
        singleSpan.addNumber(42);
        std::cout << "Attempting to find longest span..." << std::endl;
        singleSpan.longestSpan();
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    // Test with identical numbers
    try {
        std::cout << "\nTesting with identical numbers:" << std::endl;
        Span identicalSpan(5);
        identicalSpan.addNumber(7);
        identicalSpan.addNumber(7);
        identicalSpan.addNumber(7);
        std::cout << "Shortest span: " << identicalSpan.shortestSpan() << std::endl;
        std::cout << "Longest span: " << identicalSpan.longestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    // Test with negative numbers
    try {
        std::cout << "\nTesting with negative numbers:" << std::endl;
        Span negativeSpan(5);
        negativeSpan.addNumber(-5);
        negativeSpan.addNumber(10);
        negativeSpan.addNumber(-20);
        std::cout << "Shortest span: " << negativeSpan.shortestSpan() << std::endl;
        std::cout << "Longest span: " << negativeSpan.longestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
}

int main()
{
    testBasicFunctionality();
    testEdgeCases();
    return 0;
}