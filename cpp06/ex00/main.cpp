/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 15:43:37 by pmarkaid          #+#    #+#             */
/*   Updated: 2025/03/29 15:48:28 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Usage: ./convert [value]" << std::endl;
		return 1;
	}
	ScalarConverter::convert(av[1]);
	return 0;
}