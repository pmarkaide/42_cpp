/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 20:21:40 by pmarkaid          #+#    #+#             */
/*   Updated: 2025/04/24 20:45:20 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Whatever_HPP
# define Whatever_HPP


template<typename T>
void swap(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
}


template<typename T>
const T& min(const T& a, const T& b) {
	return (a < b) ? a : b;
}


template<typename T>
const T& max(const T& a, const T& b) {
	return (a > b) ? a : b;
}

#endif // Whatever_HPP