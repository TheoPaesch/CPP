/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 16:00:26 by tpaesch           #+#    #+#             */
/*   Updated: 2025/01/27 18:35:29 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <unordered_map>
#include <string>
#include <map>

struct DateValue {
	std::string date;
	double value;
};

class BitcoinExchange {
public:
	BitcoinExchange();
	~BitcoinExchange();

	// Loads the Bitcoin price database from a CSV file
	bool loadData(const std::string& filename);

	// Processes the input file and prints the results
	void processInput(const std::string& inputFile);

private:
	std::map<std::string, double> _rates; // Ordered map for easy lookup

	// Validates the date format and logical correctness
	bool DateValidation(int year, int month, int day);

	// Splits a "YYYY-MM-DD" string into year, month, day
	bool splitDate(const std::string& date, int& year, int& month, int& day);

	// Validates that the value is between 0 and 1000
	bool isValidValue(const std::string& value);

	// Finds the appropriate exchange rate for a given date
	double getRateForDate(const std::string& date);
};

#endif