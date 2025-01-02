/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 14:05:15 by pmarkaid          #+#    #+#             */
/*   Updated: 2025/01/02 15:36:49 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"


int main( void ) {
	// Fixed a(5);
	// Fixed b(10);
	// Fixed c = a + b;
	// Fixed d = a - b;
	// Fixed e = a * b;
	// Fixed f = a / b;

	// std::cout << c << std::endl;
	// std::cout << d << std::endl;
	// std::cout << e << std::endl;
	// std::cout << f << std::endl;
	
	// //Fixed g = a / Fixed(0);

	// std::cout << "a > b: " << (a > b) << std::endl;
	// std::cout << "a < b: " << (a < b) << std::endl;
	// std::cout << "a >= b: " << (a >= b) << std::endl;
	// std::cout << "a <= b: " << (a <= b) << std::endl;

	// c = a;
	// std::cout << "a == c: " << (a == c) << std::endl;
	// std::cout << "a != c: " << (a != c) << std::endl;
	// std::cout << "a >= c: " << (a >= c) << std::endl;
	// std::cout << "a <= c: " << (a <= c) << std::endl;
	
	Fixed a;
	std::cout << "a orig:\t" << a << std::endl;
	std::cout << "++a:\t"  << ++a << std::endl;
	std::cout << "a new:\t" << a << std::endl;
	std::cout << "a++:\t" << a++ << std::endl;
	std::cout << "a new:\t" << a << std::endl;

	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << b << std::endl;
	// std::cout << Fixed::max( a, b ) << std::endl;

	return 0;
}