/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 20:36:06 by pmarkaid          #+#    #+#             */
/*   Updated: 2025/04/29 21:41:30 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <algorithm>
#include <exception>

class NotFoundException: public std::exception
{
	public:
		virtual const char* what() const throw()
		{
			return ("Integer not found in container");
		}
};

template <typename T>
typename T::iterator easyfind(T& container, int value)
{
	auto result = std::find(container.begin(), container.end(), value);

	if (result != container.end())
		return result;
	else
		throw NotFoundException();
}

#endif // EASYFIND_HPP