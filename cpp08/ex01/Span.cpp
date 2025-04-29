/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 21:51:12 by pmarkaid          #+#    #+#             */
/*   Updated: 2025/04/29 22:20:03 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : maxSize_(0){}

Span::Span(unsigned int N) : maxSize_(N){}

Span::Span(const Span& other) : maxSize_(other.maxSize_), numbers_(other.numbers_){}

Span& Span::operator=(const Span& other)
{
	if (this != &other)
	{
		maxSize_ = other.maxSize_;
		numbers_ = other.numbers_;
	}
	return *this;
}

Span::~Span(){}

const char* Span::FullVectorException::what() const throw(){
	return "Vector is already full";
}

const char* Span::NoSpanException::what() const throw(){
	return "No span can be found (need at least 2 numbers)";
}

void Span::addNumber(int number)
{
	if (numbers_.size() >= maxSize_)
		throw FullVectorException();
	numbers_.push_back(number);
}

unsigned int Span::longestSpan() const
{
	if (numbers_.size() < 2)
		throw NoSpanException();
	// Find min and max elements
	auto minMax = std::minmax_element(numbers_.begin(), numbers_.end());

	return static_cast<unsigned int>(*minMax.second - *minMax.first);
}
