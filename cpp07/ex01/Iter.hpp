/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 21:00:55 by pmarkaid          #+#    #+#             */
/*   Updated: 2025/04/24 21:28:00 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <cstddef> // size_t

template<typename T, typename Func>
void iter(T* array, size_t length, Func func) {
	if (!array || !func)
		return;

	for (size_t i = 0; i < length; i++) {
		func(array[i]);
	}
}

#endif // ITER_HPP

