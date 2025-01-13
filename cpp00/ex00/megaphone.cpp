/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 11:02:50 by pmarkaid          #+#    #+#             */
/*   Updated: 2025/01/13 13:26:44 by pmarkaid         ###   ########.fr       */
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
			str += argv[i];
		for (char& c : str)
			c = std::toupper(c);
		if(str.empty()){
			std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
			return 0;
		}else
			std::cout << str << std::endl;
	}
	return 0;
}
