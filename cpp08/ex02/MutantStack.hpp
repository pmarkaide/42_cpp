/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 10:12:30 by pmarkaid          #+#    #+#             */
/*   Updated: 2025/04/30 10:32:19 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>

template <typename T>
class MutantStack : public std::stack<T> {
public:
	MutantStack() : std::stack<T()> {}
	MutantStack(const MutantStack& other) : std::stack<T>(other) {}
	MutantStack& operator=(const MutantStack& other) {
		if (this != &other)
			std::stack<T>::operator=(other);
		return *this;
	}
	~MutantStack() {}
};

#endif // MUTANTSTACK_HPP