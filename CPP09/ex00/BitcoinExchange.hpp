/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 16:00:26 by tpaesch           #+#    #+#             */
/*   Updated: 2025/01/24 16:47:54 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <unordered_map>
#include <string>

class BitcoinExchange {
public:
	BitcoinExchange();
	~BitcoinExchange();

	std::unordered_map<std::string, std::string> loadData(const std::string& filename);

private:
	bool DateValidation(int year, int month, int day);
	bool isValidValue(const std::string& value);
};

#endif