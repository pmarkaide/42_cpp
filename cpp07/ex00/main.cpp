/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 20:34:34 by pmarkaid          #+#    #+#             */
/*   Updated: 2025/04/24 20:51:41 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <string>
#include "Whatever.hpp"

class Test {
	private:
		int _value;
	public:
		Test(int value) : _value(value) {}
		
		bool operator>(const Test& rhs) const { return _value > rhs._value; }
		bool operator<(const Test& rhs) const { return _value < rhs._value; }
		
		int getValue() const { return _value; }
	};
	
	std::ostream& operator<<(std::ostream& os, const Test& obj) {
		os << obj.getValue();
		return os;
	}
	

int main(void) {
	int a = 2;
	int b = 3;
	
	::swap(a, b);
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
	std::cout << "max(a, b) = " << ::max(a, b) << std::endl;
	
	std::string c = "string_1";
	std::string d = "string_2";
	
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min(c, d) = " << ::min(c, d) << std::endl;
	std::cout << "max(c, d) = " << ::max(c, d) << std::endl;

	// Test with custom class
	Test i(100);
	Test j(200);
	
	std::cout << "\n--- Custom Class Tests ---" << std::endl;
	std::cout << "Before swap: i = " << i << ", j = " << j << std::endl;
	::swap(i, j);
	std::cout << "After swap: i = " << i << ", j = " << j << std::endl;
	std::cout << "min(i, j) = " << ::min(i, j) << std::endl;
	std::cout << "max(i, j) = " << ::max(i, j) << std::endl;
	
	return 0;
}