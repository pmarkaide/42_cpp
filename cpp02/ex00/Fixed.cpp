/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 10:47:13 by pmarkaid          #+#    #+#             */
/*   Updated: 2025/01/02 10:48:19 by pmarkaid         ###   ########.fr       */
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
	std::cout << "Assignation operator called" << std::endl;
	if (this != &src) {  // Self-assignment check
		fixedPoint_ = src.fixedPoint_;
	}
	return *this;
}

int Fixed::getRawBits() const {
	return fixedPoint_;
}

void Fixed::setRawBits(int const raw){
	fixedPoint_ = raw;
}