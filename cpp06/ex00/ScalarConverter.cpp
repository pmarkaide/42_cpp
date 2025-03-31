/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 15:42:13 by pmarkaid          #+#    #+#             */
/*   Updated: 2025/03/31 13:36:06 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ScalarConverter.hpp"

void print_char(const std::string &input){
	std::cout << "char: " << input[0] << std::endl;
}

void print_int(const std::string &input){
	std::cout << "int: " << std::stoi(input) << std::endl;
}

void print_float(const std::string &input){
	std::cout << "float: " << std::stof(input) << std::endl;
}

void print_double(const std::string &input){
	std::cout << "double: " << std::stod(input) << std::endl;
}

void ScalarConverter::convert(const std::string &input){
	
	print_char(input);
	print_int(input);
	print_float(input);
	print_double(input);	
}
