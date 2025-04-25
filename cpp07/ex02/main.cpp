#include "Array.hpp"
#include <iostream>
#include <string>

int main() {

	    
	// int * a = new int;
	// std::cout << *a <<std::endl;


	// int * b = new int();
	// std::cout << *b <<std::endl;

    // Test empty array
    std::cout << "=== Testing empty array ===" << std::endl;
    Array<int> emptyArray;
    std::cout << "Empty array size: " << emptyArray.size() << std::endl;
    
    try {
        std::cout << "Trying to access element 0: ";
        std::cout << emptyArray[0] << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    
    // Test array with integers
    std::cout << "\n=== Testing integer array ===" << std::endl;
    Array<int> intArray(5);
    std::cout << "Integer array size: " << intArray.size() << std::endl;
    
    // Initialize array
    for (unsigned int i = 0; i < intArray.size(); i++) {
        intArray[i] = i * 10;
    }

    // Display array
    std::cout << "Array contents: ";
    for (unsigned int i = 0; i < intArray.size(); i++) {
        std::cout << intArray[i] << " ";
    }
    std::cout << std::endl;
    
    // Test copy constructor
    std::cout << "\n=== Testing copy constructor ===" << std::endl;
    Array<int> copyArray(intArray);
    std::cout << "Copy array size: " << copyArray.size() << std::endl;
    
    // Display copied array
    std::cout << "Copy array contents: ";
    for (unsigned int i = 0; i < copyArray.size(); i++) {
        std::cout << copyArray[i] << " ";
    }
    std::cout << std::endl;
    
    // Modify original array and verify copy is independent
    std::cout << "\n=== Testing independence of copies ===" << std::endl;
    intArray[2] = 999;
    
    std::cout << "Original array after modification: ";
    for (unsigned int i = 0; i < intArray.size(); i++) {
        std::cout << intArray[i] << " ";
    }
    std::cout << std::endl;
    
    std::cout << "Copy array: ";
    for (unsigned int i = 0; i < copyArray.size(); i++) {
        std::cout << copyArray[i] << " ";
    }
    std::cout << std::endl;
    
    // Test assignment operator
    std::cout << "\n=== Testing assignment operator ===" << std::endl;
    Array<int> assignedArray;
    assignedArray = intArray;
    
    std::cout << "Assigned array size: " << assignedArray.size() << std::endl;
    std::cout << "Assigned array contents: ";
    for (unsigned int i = 0; i < assignedArray.size(); i++) {
        std::cout << assignedArray[i] << " ";
    }
    std::cout << std::endl;
    
    // Test out of bounds access
    std::cout << "\n=== Testing out of bounds access ===" << std::endl;
    try {
        std::cout << "Trying to access element at index 10: ";
        std::cout << intArray[10] << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    
    // Test with strings
    std::cout << "\n=== Testing with strings ===" << std::endl;
    Array<std::string> stringArray(3);
    stringArray[0] = "Hello";
    stringArray[1] = "World";
    stringArray[2] = "!";
    
    std::cout << "String array contents: ";
    for (unsigned int i = 0; i < stringArray.size(); i++) {
        std::cout << stringArray[i] << " ";
    }
    std::cout << std::endl;
    
    return 0;
}