/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 11:21:23 by pmarkaid          #+#    #+#             */
/*   Updated: 2025/01/17 08:28:22 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "replace.hpp"

int main(int argc, char const *argv[])
{
	if(argc != 4)
	{
		std::cout << "Invalid number of arguments\n\n";
		std::cout << "\tUsage: ./replace file old_string new_string\n\n";
		std::cout << "OLD_STRING will be replaced with NEW_STRING at every ocurrence in FILE\n";
		return 1;
	}
	replace(argv[1], argv[2], argv[3]);
	return 0;
}
