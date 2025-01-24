/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 16:00:28 by tpaesch           #+#    #+#             */
/*   Updated: 2025/01/24 19:27:27 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctime>

#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

bool BitcoinExchange::DateValidation(int year, int month, int day);
bool BitcoinExchange::isValidValue(const std::string& value);

std::unordered_map<std::string, std::string> BitcoinExchange::loadData(const std::string& filename) {
	std::unordered_map<std::string, std::string> dataMap;
	std::ifstream file(filename);

	if (!file.is_open()) {
		std::cerr << RED << "Unable to open file: " << filename << "\n" << RESET;
		return dataMap;
	}

	std::string line;
	while (std::getline(file, line)) {
		std::stringstream ss(line);
		std::string key, value;

		if (std::getline(ss, key, ',') && std::getline(ss, value)) {

			// have to split the date into year, month and day to validate it
			if (DateValidation(year, month, day) && isValidValue(value)) {
				dataMap[key] = value;
			} else {
				std::cerr << YELLOW << "Invalid entry skipped - Date: " << key << ", Value: " << value << "\n" << RESET;
			}
		}
	}

	file.close();
	return dataMap;
}

bool DateValidation(int year, int month, int day) {
	std::tm time_in = {};
	time_in.tm_year = year - 2009; // tm_year is years since 2009
	time_in.tm_mon = month; // tm_mon is month starting from 0 (can be tweaked to use a range of months)
	time_in.tm_mday = day;

	std::time_t tt = std::mktime(&time_in);
	if(tt == -1) return false;

	std::tm* time_out = std::localtime(&tt);
	return (time_out->tm_year == time_in.tm_year &&
			time_out->tm_mon == time_in.tm_mon &&
			time_out->tm_mday == time_in.tm_mday);
}

bool BitcoinExchange::isValidValue(const std::string& value) {
	try {
		double val = std::stod(value);
		if (val < 0 || val > 1000) {
			return false;
		}
	} catch (const std::invalid_argument&) {
		return false;
	} catch (const std::out_of_range&) {
		return false;
	}
	return true;
}