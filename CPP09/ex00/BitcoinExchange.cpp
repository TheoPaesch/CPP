/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 16:00:28 by tpaesch           #+#    #+#             */
/*   Updated: 2025/01/24 16:35:39 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctime>

#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

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
			dataMap[key] = value;
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
