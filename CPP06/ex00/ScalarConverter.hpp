/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 11:38:38 by tpaesch           #+#    #+#             */
/*   Updated: 2025/01/07 16:05:13 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <iomanip>
# include <limits>
# include <cmath>

class ScalarConverter
{
public:
	ScalarConverter(std::string const &str);
	ScalarConverter(ScalarConverter const &src);
	~ScalarConverter();

	ScalarConverter &operator=(ScalarConverter const &rhs);

	int identifyYourself(std::string const &input);
	void convert(std::string const &input);
	bool isInt();
	bool isFloat();
	bool isDouble();
	void convertFromChar(const std::string& input);
	void convertFromDouble(const std::string& input);
	void convertFromInt(const std::string& input);
	void convertFromFloat(const std::string& input);


private:
	std::string const _str;
};
