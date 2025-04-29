/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 21:51:23 by pmarkaid          #+#    #+#             */
/*   Updated: 2025/04/29 22:10:27 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Span.hpp
#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>
#include <exception>
#include <algorithm>	// minmax_element
//#include <limits>		// numeric_limits

class Span
{
private:
	unsigned int		maxSize_;
	std::vector<int>	numbers_;
	Span();

public:
	Span(unsigned int N);
	Span(const Span& other);
	Span& operator=(const Span& other);
	~Span();

	void addNumber(int number);
	//unsigned int shortestSpan() const;
	unsigned int longestSpan() const;
	class FullVectorException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};

	class NoSpanException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};
};

#endif // SPAN_HPP