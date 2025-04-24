/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 21:02:46 by pmarkaid          #+#    #+#             */
/*   Updated: 2025/04/24 21:27:36 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Iter.hpp"


void multiply(int & x) {
	x *= 2;
}

template<typename T>
void print(T const & x) {
	std::cout << x << " ";
}

int main() {
	int intArray[] = {1, 2, 3, 4, 5};
	std::string strArray[] = {"Hello", "world", "!"};
		
	// Test with integers and print function
	std::cout << "Int array: ";
	iter(intArray, 5, print<int>);
	std::cout << std::endl;
		
	// Test with strings and print function
	std::cout << "String array: ";
	iter(strArray, 3, print<std::string>);
	std::cout << std::endl;
		
	// Test with normal function
	iter(intArray, 5, multiply);
		
	// Print after modification
	std::cout << "After multiplication: ";
	iter(intArray, 5, print<int>);
	std::cout << std::endl;
		
	return 0;
}