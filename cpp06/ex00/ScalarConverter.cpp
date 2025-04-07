/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 15:42:13 by pmarkaid          #+#    #+#             */
/*   Updated: 2025/04/07 14:28:00 by pmarkaid         ###   ########.fr       */
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

	if(specialType == SpecialType::NOT_SPECIAL)
		return;

	double d_value = std::stod(input);
	float f_value = std::stof(input);

	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << f_value << "f" << std::endl;
	std::cout << "double: " << d_value << std::endl;
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

void printChar(double value){
	if (value < 0 || value > 127) {
		std::cout << "char: impossible" << std::endl;
	} else if (value <= 32 || value == 127) {
		std::cout << "char: Non displayable" << std::endl;
	} else {
		std::cout << "char: " << static_cast<char>(value) << std::endl;
	}
}

void printInt(double value){
	if (value > std::numeric_limits<int>::max() || value < std::numeric_limits<int>::min()) {
		std::cout << "int: impossible" << std::endl;
	} else {
		std::cout << "int: " << static_cast<int>(value) << std::endl;
	}
}

void printFloat(double value) {
	float f_value = static_cast<float>(value);

	if (value > std::numeric_limits<float>::max() || value < -std::numeric_limits<float>::max()) {
		std::cout << "float: impossible" << std::endl;
		return;
	}

	if (std::floor(value) == value) {
		std::cout << std::fixed << std::setprecision(1);
	} else {
		std::cout.unsetf(std::ios::fixed);
		std::cout << std::setprecision(std::numeric_limits<float>::digits10 + 1);
	}
	std::cout << "float: " << f_value << "f" << std::endl;
}

void printDouble(double value) {
	if (value > std::numeric_limits<double>::max() || value < -std::numeric_limits<double>::max()) {
		std::cout << "double: impossible" << std::endl;
		return;
	}

	if (std::floor(value) == value) {
		std::cout << std::fixed << std::setprecision(1);
	} else {
		std::cout.unsetf(std::ios::fixed);
		std::cout << std::setprecision(std::numeric_limits<double>::digits10 + 1);
	}
	std::cout << "double: " << value << std::endl;
}

void ScalarConverter::convert(const std::string &input) {
	SpecialType specialType = checkSpecialValue(input);
	if (specialType != SpecialType::NOT_SPECIAL) {
		printSpecialValues(specialType, input);
		return;
	}

	LiteralType type = detectType(input);
	double d_value = 0.0;

	try {
		switch (type) {
			case LiteralType::CHAR:
				d_value = static_cast<double>(input[0]);
				break;

			case LiteralType::INT:
				d_value = std::stod(input);
				break;

			case LiteralType::FLOAT:
				{
					std::string floatStr = input;
					if (floatStr[floatStr.length() - 1] == 'f')
						floatStr = floatStr.substr(0, floatStr.length() - 1);
					d_value = std::stod(floatStr);
				}
				break;
				
			case LiteralType::DOUBLE:
				d_value = std::stod(input);
				break;

			case LiteralType::INVALID:
			default:
				throw std::invalid_argument("Invalid input format");
		}

		printChar(d_value);
		printInt(d_value);
		printFloat(d_value);
		printDouble(d_value);

	} catch (const std::exception &e) {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
	}
}
