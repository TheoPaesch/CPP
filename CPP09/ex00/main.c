/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 15:58:49 by tpaesch           #+#    #+#             */
/*   Updated: 2025/01/24 16:36:25 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Colors.hpp"
#include "BitcoinExchange.hpp"

int main() {
	BitcoinExchange loader;
	std::unordered_map<std::string, std::string> data = loader.loadData("data.csv");

	for (const auto& pair : data) {
		std::cout << pair.first << ": " << pair.second << "\n";
	}

	return 0;
}
