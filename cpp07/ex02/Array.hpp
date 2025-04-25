/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 22:01:53 by pmarkaid          #+#    #+#             */
/*   Updated: 2025/04/25 14:02:59 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <exception>
#include <iostream>

template <typename T>
class Array {
private:
	T* elements_;
	unsigned int size_;

public:

	Array() : elements_(nullptr), size_(0) {}

	Array(unsigned int n) : size_(n) {
		if (n > 0)
			elements_ = new T[n]();
		else
			elements_ = nullptr;
	}

	~Array() {
		if (elements_)
			delete[] elements_;
	}

	Array(const Array& other) : elements_(nullptr), size_(0) {
		*this = other;
	}

	Array& operator=(const Array& other) {
		if (this != &other) {
			if (elements_)
				delete[] elements_;

			size_ = other.size_;

			if (size_ > 0) {
				elements_ = new T[size_];
				for (size_t i = 0; i < size_; i++)
					elements_[i] = other.elements_[i];
			} else {
				elements_ = nullptr;
			}
		}
		return *this;
	}

	// Subscript operator with bounds checking
	T& operator[](unsigned int index) {
		if (index >= size_)
			throw OutOfBoundsException();
		return elements_[index];
	}

	unsigned int size() const {
		return size_;
	}

	class OutOfBoundsException : public std::exception {
		public:
			virtual const char* what() const throw() {
				return "Index out of bounds";
			}
		};
};

#endif // ARRAY_HPP