/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 15:42:13 by pmarkaid          #+#    #+#             */
/*   Updated: 2025/03/31 14:11:12 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ScalarConverter.hpp"

void print_char(double value){
	std::cout << "char: " << static_cast<char>(value) << std::endl;
}

void print_int(double value){
	std::cout << "int: " << static_cast<int>(value) << std::endl;
}

void print_float(double value){
	// Check if the number has a fractional part
	double intPart;
	double fracPart = std::modf(value, &intPart);

	if (fracPart == 0.0) {
		std::cout << "float: " << value << ".0f" << std::endl;
	} else {
		std::cout << "float: " << value << "f" << std::endl;
	}
}

void print_double(double value){

	// Check if the number has a fractional part
	double intPart;
	double fracPart = std::modf(value, &intPart);

	if (fracPart == 0.0) {
		std::cout << "double: " << value << ".0" << std::endl;
	} else {
		std::cout << "double: " << value << std::endl;
	}
}

void ScalarConverter::convert(const std::string &input){
	
	try{
		double value = std::stod(input);

		print_char(value);
		print_int(value);
		print_float(value);
		print_double(value);

	}catch(std::exception &e){
		std::cout << "double: impossible" << std::endl;
		return;
	}
}
