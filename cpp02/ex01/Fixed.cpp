/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 11:58:16 by pmarkaid          #+#    #+#             */
/*   Updated: 2025/01/02 13:24:22 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Fixed.hpp"

Fixed::Fixed() : fixedPoint_(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int nb) : fixedPoint_(nb << fractionalBits_){
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float n) : fixedPoint_(roundf(n * (1 << fractionalBits_))) {
	std::cout << "Float constructor called" << std::endl;
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

int Fixed::toInt(void) const{
	return (fixedPoint_ >> fractionalBits_);
}

float Fixed::toFloat(void) const{
	return (float)fixedPoint_ / (1 << fractionalBits_);
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
	// Convert the fixed-point number to float and insert it into the stream
	os << fixed.toFloat();
	return os;
}