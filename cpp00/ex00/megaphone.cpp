/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 11:02:50 by pmarkaid          #+#    #+#             */
/*   Updated: 2024/11/26 11:51:35 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(int argc, char **argv) {
	if(argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		std::string str;

		for (int i = 1; i < argc; i++)
		{
			str += argv[i];
			if (i < argc - 1)
				str += " ";
		}
		for (char& c : str)
			c = std::toupper(c);

		std::cout << str << std::endl;
	}
	return 0;
}
