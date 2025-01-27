/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 15:58:49 by tpaesch           #+#    #+#             */
/*   Updated: 2025/01/27 19:01:07 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Colors.hpp"
#include "BitcoinExchange.hpp"


int main(int argc, char* argv[]) {
	if (argc != 2) {
		std::cerr << RED << "Error: could not open file." << RESET << std::endl;
		return 1;
	}

	std::string inputFile = argv[1];
	// Optional: Validate input file type
	// You can implement validateFileType if necessary

	BitcoinExchange btc;
	if (!btc.loadData("data.csv")) {
		return 1;
	}

	btc.processInput(inputFile);

	return 0;
}