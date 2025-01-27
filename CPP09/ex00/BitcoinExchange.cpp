/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 16:00:28 by tpaesch           #+#    #+#             */
/*   Updated: 2025/01/27 19:12:00 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include "Colors.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <ctime>

// Constructor
BitcoinExchange::BitcoinExchange() {}

// Destructor
BitcoinExchange::~BitcoinExchange() {}

// Loads the Bitcoin price database from a CSV file
bool BitcoinExchange::loadData(const std::string& filename) {
	std::ifstream file(filename);
	if (!file.is_open()) {
		std::cerr << RED << "Error: Unable to open database file: " << filename << RESET << std::endl;
		return false;
	}

	std::string line;
	// Skip header if present
	if (std::getline(file, line)) {
		// Check if the first line contains non-numeric characters (header)
		if (line.find("date") != std::string::npos && line.find("value") != std::string::npos) {
			// It's a header, skip
		}
		else {
			// Not a header, process this line
			std::stringstream ss(line);
			std::string date, rateStr;
			if (std::getline(ss, date, ',') && std::getline(ss, rateStr)) {
				try {
					double rate = std::stod(rateStr);
					_rates[date] = rate;
				}
				catch (...) {
					// Invalid rate, skip
				}
			}
		}
	}

	// Read the rest of the file
	while (std::getline(file, line)) {
		if (line.empty()) continue;

		std::stringstream ss(line);
		std::string date, rateStr;
		if (std::getline(ss, date, ',') && std::getline(ss, rateStr)) {
			try {
				double rate = std::stod(rateStr);
				_rates[date] = rate;
			}
			catch (...) {
				// Invalid rate, skip
			}
		}
	}

	file.close();
	return true;
}

// Splits a "YYYY-MM-DD" string into year, month, day
bool BitcoinExchange::splitDate(const std::string& date, int& year, int& month, int& day) {
	char dash1, dash2;
	std::istringstream iss(date);
	if (!(iss >> year >> dash1 >> month >> dash2 >> day))
		return false;
	return (dash1 == '-' && dash2 == '-');
}

// Validates the date format and logical correctness
bool BitcoinExchange::DateValidation(int year, int month, int day) {
	// Basic range checks
	if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31)
		return false;

	// Check for correct number of days in month
	bool isLeap = false;
	if (year % 4 == 0) {
		if (year % 100 != 0 || year % 400 == 0)
			isLeap = true;
	}

	int daysInMonth[] = { 31, (isLeap ? 29 : 28), 31, 30, 31, 30,
						31, 31, 30, 31, 30, 31 };

	if (day > daysInMonth[month - 1])
		return false;

	return true;
}

// Validates that the value is between 0 and 1000
bool BitcoinExchange::isValidValue(const std::string& value) {
	try {
		double val = std::stod(value);
		if (val < 0 || val > 1000)
			return false;
	}
	catch (const std::invalid_argument&) {
		return false;
	}
	catch (const std::out_of_range&) {
		return false;
	}
	return true;
}

// Finds the appropriate exchange rate for a given date
double BitcoinExchange::getRateForDate(const std::string& date) {
	if (_rates.empty())
		return -1.0;

	// Exact date found
	std::map<std::string, double>::iterator it = _rates.find(date);
	if (it != _rates.end())
		return it->second;

	// Find the closest previous date
	it = _rates.lower_bound(date);
	if (it == _rates.begin()) {
		// No previous date
		return -1.0;
	}
	if (it == _rates.end() || it->first > date)
		--it;

	return it->second;
}

// Processes the input file and prints the results
void BitcoinExchange::processInput(const std::string& inputFile) {
	std::ifstream file(inputFile);
	if (!file.is_open()) {
		std::cerr << RED << "Error: Could not open file." << RESET << std::endl;
		return;
	}

	std::string line;
	// Skip header if present
	if (std::getline(file, line)) {
		if (line.find("date") != std::string::npos && line.find("value") != std::string::npos) {
			// It's a header, skip
		}
		else {
			// Not a header, process this line
			// Fall through to processing
		}
	}

	while (std::getline(file, line)) {
		if (line.empty())
			continue;

		std::stringstream ss(line);
		std::string dateStr, sep, valueStr;

		// Parsing format: "date | value"
		if (!(ss >> dateStr)) {
			std::cerr << YELLOW << "Error: bad input => " << line << "\n" << RESET;
			continue;
		}
		if (!(ss >> sep)) {
			std::cerr << YELLOW << "Error: bad input => " << line << "\n" << RESET;
			continue;
		}
		if (sep != "|") {
			std::cerr << YELLOW << "Error: bad input => " << line << "\n" << RESET;
			continue;
		}
		if (!(ss >> valueStr)) {
			std::cerr << YELLOW << "Error: bad input => " << line << "\n" << RESET;
			continue;
		}

		// Validate date
		int year, month, day;
		if (!splitDate(dateStr, year, month, day) || !DateValidation(year, month, day)) {
			std::cerr << "Error: bad input => " << dateStr << "\n";
			continue;
		}

		// Validate value
		if (!isValidValue(valueStr)) {
			try {
				double val = std::stod(valueStr);
				if (val < 0)
					std::cerr << "Error: not a positive number.\n";
				else
					std::cerr << "Error: too large a number.\n";
			}
			catch (...) {
				std::cerr << "Error: bad input => " << valueStr << "\n";
			}
			continue;
		}

		double value = std::stod(valueStr);
		double rate = getRateForDate(dateStr);
		if (rate < 0.0) {
			std::cerr << "Error: no exchange rate available for date => " << dateStr << "\n";
			continue;
		}

		double result = value * rate;

		// Create struct with valid data
		DateValue entry;
		entry.date = dateStr;
		entry.value = value;

		// Print the entry
		std::cout << entry.date << " => " << entry.value << " = " << result << "\n";

		// Clear the struct (optional, as it's going out of scope)
		entry = DateValue();
	}

	file.close();
}