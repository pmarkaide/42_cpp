/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 15:42:13 by pmarkaid          #+#    #+#             */
/*   Updated: 2025/03/31 14:40:31 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ScalarConverter.hpp"

enum class SpecialType {
	NOT_SPECIAL,
	NOT_A_NUMBER,
	INF_POS,
	INF_NEG
};

SpecialType checkSpecialValue(const std::string& input) {
	std::string lowerInput = input;
	std::transform(lowerInput.begin(), lowerInput.end(), lowerInput.begin(),
				[](unsigned char c){ return std::tolower(c); });

	if (lowerInput == "nan" || lowerInput == "nanf") {
		return SpecialType::NOT_A_NUMBER;
	}
	if (lowerInput == "+inf" || lowerInput == "inf" || lowerInput == "+inff" || lowerInput == "inff") {
		return SpecialType::INF_POS;
	}
	if (lowerInput == "-inf" || lowerInput == "-inff") {
		return SpecialType::INF_NEG;
	}
	return SpecialType::NOT_SPECIAL;
}

void printSpecialValues(SpecialType specialType) {
	switch (specialType) {
		case SpecialType::NOT_A_NUMBER:
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: nanf" << std::endl;
			std::cout << "double: nan" << std::endl;
			break;

		case SpecialType::INF_POS:
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: +inff" << std::endl;
			std::cout << "double: +inf" << std::endl;
			break;

		case SpecialType::INF_NEG:
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: -inff" << std::endl;
			std::cout << "double: -inf" << std::endl;
			break;

		case SpecialType::NOT_SPECIAL:
			break;
	}
}

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

	SpecialType specialType = checkSpecialValue(input);

	if (specialType != SpecialType::NOT_SPECIAL) {
		printSpecialValues(specialType);
		return;
	}

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
