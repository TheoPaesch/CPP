/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 11:38:38 by tpaesch           #+#    #+#             */
/*   Updated: 2025/01/09 16:05:03 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

class ScalarConverter {
public:
    ScalarConverter(std::string const &str);
    ScalarConverter(ScalarConverter const &src);
    ~ScalarConverter();

    ScalarConverter &operator=(ScalarConverter const &);

    void convert(std::string const &input);

private:
    std::string _str;

    enum ConversionType {
        CHAR,
        INT,
        FLOAT,
        DOUBLE,
        INVALID
    };

    ConversionType identifyYourself(std::string const &input);
    void convertFromChar(const std::string& input);
    void convertFromInt(const std::string& input);
    void convertFromFloat(const std::string& input);
    void convertFromDouble(const std::string& input);
    int checkSpecialCases(const std::string& input);
    void handleSpecialCases(int index);

    typedef void (ScalarConverter::*ConversionFunction)(const std::string& input);
    static ConversionFunction conversionFunctions[4];
};

#endif // SCALARCONVERTER_HPP