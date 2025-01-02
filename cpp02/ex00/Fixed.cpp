/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 10:47:13 by pmarkaid          #+#    #+#             */
/*   Updated: 2025/01/02 11:05:23 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Fixed.hpp"
# include <iostream>

Fixed::Fixed() : fixedPoint_(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& src): fixedPoint_(src.fixedPoint_){
	std::cout << "Copy constructor called" << std::endl;
}

Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
}

Fixed & Fixed::operator=(Fixed const & src){
	std::cout << "Copy Assignation operator called" << std::endl;
	if (this != &src) {  // Self-assignment check
		fixedPoint_ = src.getRawBits();
	}
	return *this;
}

int Fixed::getRawBits() const {
	std::cout << "getRawBits function called" << std::endl;
	return fixedPoint_;
}

void Fixed::setRawBits(int const raw){
	std::cout << "setRawBits function called" << std::endl;
	fixedPoint_ = raw;
}