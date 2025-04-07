/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 15:42:13 by pmarkaid          #+#    #+#             */
/*   Updated: 2025/04/07 11:04:14 by pmarkaid         ###   ########.fr       */
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

void printSpecialValues(SpecialType specialType, const std::string& input) {
	switch (specialType) {
		case SpecialType::NOT_A_NUMBER:
		{
			double d_value = std::stod(input);
			float f_value = static_cast<float>(std::stod(input));

			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: " << f_value << "f" << std::endl;
			std::cout << "double: " << d_value << std::endl;
		}
		break;

		case SpecialType::INF_POS:
		{
			double d_value = std::stod(input);
			float f_value = static_cast<float>(std::stod(input));

			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: " << f_value << "f" << std::endl;
			std::cout << "double: " << d_value << std::endl;
		}
		break;

		case SpecialType::INF_NEG:
		{
			double d_value = std::stod(input);
			float f_value = static_cast<float>(std::stod(input));

			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: " << f_value << "f" << std::endl;
			std::cout << "double: " << d_value << std::endl;
		}
		break;

		case SpecialType::NOT_SPECIAL:
			break;
	}
}

enum class LiteralType {
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	INVALID
};

bool isValidNumber(const std::string& input) {
	bool hasDecimalPoint = false;

	for (size_t i = 0; i < input.length(); i++) {
		if (i == 0 && (input[i] == '+' || input[i] == '-')) {
			continue;
		}
		if (input[i] == '.' && !hasDecimalPoint) {
			hasDecimalPoint = true;
			continue;
		}
		if (!std::isdigit(input[i])) {
			return false;
		}
	}
	return true;
}

LiteralType detectType(const std::string& input) {

	// Char
	if (input.length() == 1 && !std::isdigit(input[0])) {
		return LiteralType::CHAR;
	}

	// Float
	if (input.length() > 1 && input[input.length() - 1] == 'f') {
		std::string floatPart = input.substr(0, input.length() - 1);
		if (isValidNumber(floatPart)) {
			return LiteralType::FLOAT;
		}
	}

	// Double
	if (isValidNumber(input)) {
		return input.find('.') != std::string::npos ? LiteralType::DOUBLE : LiteralType::INT;
	}

	return LiteralType::INVALID;
}

void print_char(double value){
	if (value < 0 || value > 127) {
		std::cout << "char: impossible" << std::endl;
	} else if (value < 32 || value == 127) {
		std::cout << "char: Non displayable" << std::endl;
	} else {
		std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
	}
}

void print_int(double value){
	if (value > std::numeric_limits<int>::max() || value < std::numeric_limits<int>::min()) {
		std::cout << "int: impossible" << std::endl;
	} else {
		std::cout << "int: " << static_cast<int>(value) << std::endl;
	}
}

void print_float(double value){

	float f_value = static_cast<float>(value);
	
	// Check if the number has a fractional part
	double intPart;
	double fracPart = std::modf(value, &intPart);

	if (fracPart == 0.0) {
		std::cout << "float: " << f_value << ".0f" << std::endl;
	} else {
		std::cout << "float: " << f_value << "f" << std::endl;
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
		printSpecialValues(specialType, input);
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
