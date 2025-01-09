/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 11:38:18 by tpaesch           #+#    #+#             */
/*   Updated: 2025/01/09 16:04:52 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include "Colors.hpp"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <climits>
#include <cctype>

ScalarConverter::ConversionFunction ScalarConverter::conversionFunctions[4] = {
    &ScalarConverter::convertFromChar,
    &ScalarConverter::convertFromInt,
    &ScalarConverter::convertFromFloat,
    &ScalarConverter::convertFromDouble
};

ScalarConverter::ScalarConverter(std::string const &str) : _str(str) {}

ScalarConverter::ScalarConverter(ScalarConverter const &src) : _str(src._str) {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &) {
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

int ScalarConverter::checkSpecialCases(const std::string& input) {
    static const std::string exceptions[5] = {"nan", "-inf", "+inf", "-inff", "+inff"};
    for (int i = 0; i < 5; i++) {
        if (input == exceptions[i]) {
            return i; // returns whichever exception index matched
        }
    }
    return -1; // no match found
}

void ScalarConverter::handleSpecialCases(int index) {
    static const std::string exceptions[5] = {"nan", "-inf", "+inf", "-inff", "+inff"};
    std::string exception = exceptions[index];

    std::cout << BRIGHT_BLUE << "char: " << RESET << "impossible\n";
    std::cout << BRIGHT_GREEN << "int: " << RESET << "impossible\n";

    if (exception == "-inff" || exception == "+inff") {
        std::cout << BRIGHT_YELLOW << "float: " << exception << RESET << '\n';
        std::cout << BRIGHT_CYAN << "double: " << exception.substr(0, exception.size() - 1) << RESET << std::endl;
    } else {
        std::cout << BRIGHT_YELLOW << "float: " << exception << 'f' << RESET << '\n';
        std::cout << BRIGHT_CYAN << "double: " << exception << RESET << std::endl;
    }
}

ScalarConverter::ConversionType ScalarConverter::identifyYourself(const std::string& input) {
    // Implement your logic to identify the type of input
    // Return CHAR, INT, FLOAT, DOUBLE, or INVALID based on the input
    // For example:
    if (input.size() == 1 && !std::isdigit(input[0])) {
        return CHAR;
    }
    if (isInt(input)) {
        return INT;
    }
    if (isFloat(input)) {
        return FLOAT;
    }
    if (isDouble(input)) {
        return DOUBLE;
    }
    return INVALID;
}

void ScalarConverter::convert(const std::string& input) {
    int specialCaseIndex = checkSpecialCases(input);
    if (specialCaseIndex != -1) {
        handleSpecialCases(specialCaseIndex);
        return;
    }

    ConversionType type = identifyYourself(input);
    if (type != INVALID) {
        (this->*conversionFunctions[type])(input);
    } else {
        std::cout << "Invalid input" << std::endl;
    }
}
