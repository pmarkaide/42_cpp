/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 21:51:12 by pmarkaid          #+#    #+#             */
/*   Updated: 2025/04/29 22:00:13 by pmarkaid         ###   ########.fr       */
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