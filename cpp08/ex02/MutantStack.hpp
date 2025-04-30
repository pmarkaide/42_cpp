/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 10:12:30 by pmarkaid          #+#    #+#             */
/*   Updated: 2025/04/30 10:42:41 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <deque>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
	MutantStack() : std::stack<T>() {}
	MutantStack(const MutantStack& other) : std::stack<T>(other) {}
	MutantStack& operator=(const MutantStack& other) {
		if (this != &other)
			std::stack<T>::operator=(other);
		return *this;
	}
	~MutantStack() {}

	// Iterator typedefs
	typedef typename std::deque<T>::iterator iterator;
	typedef typename std::deque<T>::const_iterator const_iterator;

	// Iterator methods
	iterator begin() { return this->c.begin(); }
	iterator end() { return this->c.end(); }
		
	const_iterator begin() const { return this->c.begin(); }
	const_iterator end() const { return this->c.end(); }
};

#endif // MUTANTSTACK_HPP