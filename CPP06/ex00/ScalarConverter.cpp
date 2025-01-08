/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 11:38:18 by tpaesch           #+#    #+#             */
/*   Updated: 2025/01/07 16:53:28 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include "Colors.hpp"

ScalarConverter::ScalarConverter(std::string const &str) : _str(str)
{
}

ScalarConverter::ScalarConverter(ScalarConverter const &src) : _str(src._str)
{
}

ScalarConverter::~ScalarConverter()
{
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &)
{
	return *this;
}

bool isInt(std::string const &input)
{
	// Special check for single char that's not a digit
	if (input.size() == 1 && !std::isdigit(input[0])) {
		return false;
	}
	char *endPtr = NULL;
	errno = 0;
	long out = std::strtol(input.c_str(), &endPtr, 10);
	// If endPtr is not at the end of the string or conversion overflowed, return false
	if (*endPtr != '\0' || errno == ERANGE || out > std::numeric_limits<int>::max() || out < std::numeric_limits<int>::min()) {
		return false;
	}
	return true;
}

bool isDouble(std::string const &input)
{
	// Special check for single char that's not a digit
	if (input.size() == 1 && !std::isdigit(input[0])) {
		return false;
	}
	char *endPtr = NULL;
	errno = 0;
	double out = std::strtod(input.c_str(), &endPtr);
	// If endPtr is not at the end of the string or conversion overflowed, return false
	if (*endPtr != '\0' || errno == ERANGE || out > std::numeric_limits<double>::max() || out < std::numeric_limits<double>::min()) {
		return false;
	}
	return true;
}

bool isFloat(std::string const &input)
{
	// Special check for single char that's not a digit
	if (input.size() == 1 && !std::isdigit(input[0])) {
		return false;
	}
	char *endPtr = NULL;
	errno = 0;
	float out = std::strtof(input.c_str(), &endPtr);
	// If endPtr is not at the end of the string or conversion overflowed, return false
	if (*endPtr != 'f' || errno == ERANGE || out > std::numeric_limits<float>::max() || out < std::numeric_limits<float>::min()) {
		return false;
	}
	return true;
}



int identifyYourself(std::string const &input)
{
	static const std::string exceptions[7] = {"nan", "-inff", "+inff", "-infd", "+infd", "-inf", "+inf"};
	for (int i = 0; i < 7; i++) {
		if (input == exceptions[i]) {
			return i; // returns whichever exception index matched
		}
	}

	// Check for a single-character non-digit: char
	if (input.size() == 1 && !std::isdigit(input[0])) {
		return 7;
	}
	// Check for int
	else if (isInt(input)) {
		return 8;
	}
	// Check for float
	else if (isFloat(input)) {
		return 9;
	}
	// Check for double
	else if (isDouble(input)) {
		return 10;
	}

	return 0; // unknown
}

void ScalarConverter::convert(std::string const &input)
{
	int identifyer = identifyYourself(input);



}

void ScalarConverter::convertFromChar(const std::string& input) {
	char character = input[0];
	std::cout << BRIGHT_BLUE << "char: '" << character << "'" << RESET << '\n'
			<< BRIGHT_GREEN << "int: " << static_cast<int>(character) << RESET << '\n'
			<< BRIGHT_YELLOW << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(character) << 'f' << RESET << '\n'
			<< BRIGHT_CYAN << "double: " << static_cast<double>(character) << RESET << std::endl;
}

void ScalarConverter::convertFromDouble(const std::string& input) {
	double dbl = std::strtod(input.c_str(), NULL);
	std::cout << BRIGHT_BLUE << "char: " << RESET;
	if (dbl >= 0 && dbl < 128 && std::isprint(static_cast<int>(dbl))) {
		std::cout << "'" << static_cast<char>(dbl) << "'";
	} else {
		std::cout << "impossible";
	}
	std::cout << '\n';

	std::cout << BRIGHT_GREEN << "int: " << RESET;
	if (dbl > INT_MAX || dbl < INT_MIN) {
		std::cout << "impossible";
	} else {
		std::cout << static_cast<int>(dbl);
	}
	std::cout << '\n';

	std::cout << std::fixed << std::setprecision(1)
			<< BRIGHT_YELLOW << "float: " << static_cast<float>(dbl) << 'f' << RESET << '\n'
			<< BRIGHT_CYAN << "double: " << dbl << RESET << std::endl;
}

void ScalarConverter::convertFromInt(const std::string& input) {
	int dec = std::atoi(input.c_str());
	std::cout << BRIGHT_BLUE << "char: " << RESET;
	if (dec >= 0 && dec < 128 && std::isprint(dec)) {
		std::cout << "'" << static_cast<char>(dec) << "'";
	} else {
		std::cout << "impossible";
	}
	std::cout << '\n';

	std::cout << BRIGHT_GREEN << "int: " << dec << RESET << '\n';

	std::cout << std::fixed << std::setprecision(1)
			<< BRIGHT_YELLOW << "float: " << static_cast<float>(dec) << 'f' << RESET << '\n'
			<< BRIGHT_CYAN << "double: " << static_cast<double>(dec) << RESET << std::endl;
}

void ScalarConverter::convertFromFloat(const std::string& input) {
	float flt = static_cast<float>(std::strtod(input.c_str(), NULL));
	std::cout << BRIGHT_BLUE << "char: " << RESET;
	if (flt >= 0 && flt < 128 && std::isprint(static_cast<int>(flt))) {
		std::cout << "'" << static_cast<char>(flt) << "'";
	} else {
		std::cout << "impossible";
	}
	std::cout << '\n';

	std::cout << BRIGHT_GREEN << "int: " << RESET;
	if (flt > INT_MAX || flt < INT_MIN) {
		std::cout << "impossible";
	} else {
		std::cout << static_cast<int>(flt);
	}
	std::cout << '\n';

	std::cout << std::fixed << std::setprecision(1)
			<< BRIGHT_YELLOW << "float: " << flt << 'f' << RESET << '\n'
			<< BRIGHT_CYAN << "double: " << static_cast<double>(flt) << RESET << std::endl;
}
