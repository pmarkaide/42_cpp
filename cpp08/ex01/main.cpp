/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 22:15:51 by pmarkaid          #+#    #+#             */
/*   Updated: 2025/04/29 23:03:20 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void testSimpleAddRange()
{
    std::cout << "\n=== Testing Simple addRange ===" << std::endl;
    
    try {
        // Create a span with capacity for 25 numbers
        Span sp(25);
        
        // Add a few individual numbers first
        sp.addNumber(100);
        sp.addNumber(500);
        std::cout << "Added two numbers individually." << std::endl;
        
        // Create an array of numbers to add at once
        int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
        std::cout << "Adding 10 numbers from array using addRange..." << std::endl;
        sp.addRange(arr, arr + 10);
        
        // Create a vector of more numbers
        std::vector<int> vec = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
        std::cout << "Adding 10 numbers from vector using addRange..." << std::endl;
        sp.addRange(vec.begin(), vec.end());
        
        // Check the spans
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
        
        // Test the exception by trying to add more than capacity
        std::cout << "Trying to add more elements than remaining capacity (should throw)..." << std::endl;
        int more[] = {30, 40, 50, 60, 70};
        sp.addRange(more, more + 5);
    }
    catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
}

int main()
{
    testBasicFunctionality();
    testEdgeCases();
    testSimpleAddRange();
    return 0;
}