/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 21:00:55 by pmarkaid          #+#    #+#             */
/*   Updated: 2025/04/24 21:03:44 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Iter_HPP
# define Iter_HPP

# include <cstddef>
# include <iostream>


template<typename T>
void iter(T* array, size_t length, void (*func)(T&)) {
	for (size_t i = 0; i < length; i++) {
		func(array[i]);
	}
}


void print(int& x) {
	std::cout << x << " ";
}

#endif // Iter_HPP

