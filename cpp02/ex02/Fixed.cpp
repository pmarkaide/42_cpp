/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 14:04:48 by pmarkaid          #+#    #+#             */
/*   Updated: 2025/01/03 14:07:14 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Fixed.hpp"

Fixed::Fixed() : fixedPoint_(0) {
	//std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int nb) : fixedPoint_(nb << fractionalBits_){
	//std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float n) : fixedPoint_(roundf(n * (1 << fractionalBits_))) {
	//std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& src): fixedPoint_(src.fixedPoint_){
	//std::cout << "Copy constructor called" << std::endl;
}

Fixed::~Fixed(){
	//std::cout << "Destructor called" << std::endl;
}

Fixed & Fixed::operator=(Fixed const & src){
	//std::cout << "Copy Assignation operator called" << std::endl;
	if (this != &src) {  // Self-assignment check
		fixedPoint_ = src.getRawBits();
	}
	return *this;
}

int Fixed::getRawBits() const {
	return fixedPoint_;
}

void Fixed::setRawBits(int const raw){
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

Fixed Fixed::operator+(const Fixed &other) const {
	Fixed result;

	long long temp = static_cast<long long>(this->getRawBits()) + static_cast<long long>(other.getRawBits());
		
	if (temp > INT_MAX || temp < INT_MIN)
		throw std::overflow_error("Fixed-point addition overflow");
		
	result.setRawBits(static_cast<int>(temp));
	return result;
}

Fixed Fixed::operator-(const Fixed &other) const {
	Fixed result;

	long long temp = static_cast<long long>(this->getRawBits()) - static_cast<long long>(other.getRawBits());
		
	if (temp > INT_MAX || temp < INT_MIN)
		throw std::overflow_error("Fixed-point subtraction overflow");
		
	result.setRawBits(static_cast<int>(temp));
	return result;
}

Fixed Fixed::operator*(const Fixed &other) const {
	Fixed result;

	long long temp = static_cast<long long>(this->getRawBits()) * static_cast<long long>(other.getRawBits());
	temp = temp >> fractionalBits_;
	if (temp > INT_MAX || temp < INT_MIN)
		throw std::overflow_error("Fixed-point multiplication overflow");
	result.setRawBits(static_cast<int>(temp));
	return result;
}

Fixed Fixed::operator/(const Fixed &other) const {
	if (other.getRawBits() == 0)
		throw std::runtime_error("Division by zero");

	Fixed result;

	long long temp = static_cast<long long>(this->getRawBits()) << fractionalBits_;
	temp = temp / other.getRawBits();
	if (temp > INT_MAX || temp < INT_MIN)
		throw std::overflow_error("Fixed-point division overflow");
	result.setRawBits(static_cast<int>(temp));
	return result;
}

bool Fixed::operator>(const Fixed &other) const {
	return this->getRawBits() > other.getRawBits();
}

bool Fixed::operator<(const Fixed &other) const {
	return this->getRawBits() < other.getRawBits();
}

bool Fixed::operator>=(const Fixed &other) const {
	return this->getRawBits() >= other.getRawBits();
}

bool Fixed::operator<=(const Fixed &other) const {
	return this->getRawBits() <= other.getRawBits();
}

bool Fixed::operator==(const Fixed &other) const {
	return this->getRawBits() == other.getRawBits();
}

bool Fixed::operator!=(const Fixed &other) const {
	return this->getRawBits() != other.getRawBits();
}

Fixed& Fixed::operator++() {
	fixedPoint_ += 1;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed temp(*this);
	fixedPoint_ += 1;
	return temp;		// return the copy (original value)
}

Fixed& Fixed::operator--() {
	fixedPoint_ -= 1;
	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed temp(*this);
	fixedPoint_ -= 1;
	return temp;		// return the copy (original value)
}

// in case of equality, first argument is returned,
// as std::min does
Fixed& Fixed::min(Fixed &a, Fixed &b){
	if(b < a)			
		return b;
	return a;
}

Fixed& Fixed::max(Fixed &a, Fixed &b){
	if(b > a)
		return b;
	return a;
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b){
	if(b < a)
		return b;
	return a;
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b){
	if(b > a)
		return b;
	return a;
}