/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 11:38:18 by tpaesch           #+#    #+#             */
/*   Updated: 2025/01/05 15:53:29 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(std::string const &str) : _str(str)
{
}

ScalarConverter::ScalarConverter(ScalarConverter const &src) : _str(src._str)
{
}

ScalarConverter::~ScalarConverter()
{
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &rhs)
{
	if (this != &rhs)
	{
	}
	return *this;
}

int identifyYourself(std::string const &input)
{
	static const std::string exeptions[7] = {"nan", "-inff", "+inff", "-infd", "+infd", "-inf", "+inf"};
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

