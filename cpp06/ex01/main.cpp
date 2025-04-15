/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 17:18:20 by pmarkaid          #+#    #+#             */
/*   Updated: 2025/04/15 17:24:52 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Serializer.hpp"
#include "Data.hpp"

int main() {
    // Create a Data object
    Data *originalData = new Data;
	originalData->value = 42;
    Data* originalPtr = originalData;
    
    // Serialize the pointer
    uintptr_t serialized = Serializer::serialize(originalPtr);
    
    // Deserialize back to a pointer
    Data* deserializedPtr = Serializer::deserialize(serialized);
    
    // Verify the conversion worked correctly
    std::cout << "Original pointer: " << originalPtr << std::endl;
    std::cout << "Serialized value: " << serialized << std::endl;
    std::cout << "Deserialized pointer: " << deserializedPtr << std::endl;
    
    // Check if pointers are equal
    if (originalPtr == deserializedPtr) {
        std::cout << "Success! Pointers match." << std::endl;
        // Access data to prove it works
        std::cout << "Data value: " << deserializedPtr->value << std::endl;
    } else {
        std::cout << "Error! Pointers don't match." << std::endl;
    }
    
    return 0;
}