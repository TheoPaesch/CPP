/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:42:46 by tpaesch           #+#    #+#             */
/*   Updated: 2024/11/07 20:34:53 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(int argc, char **argv) {
	PhoneBook		phoneBook;
	std::string		inputLine;

	void(argv);
	if (argc != 1)
	{
		std::cout << "This crappy PhoneBook takes no arguments!" << std::endl;
		return (1);
	}
	else {
		std::cout << "*****************************************" << std::endl;
		std::cout << "*                                       *" << std::endl;
		std::cout << "*    WELCOME TO MY AMAZING PHONEBOOK!   *" << std::endl;
		std::cout << "*                                       *" << std::endl;
		std::cout << "*****************************************" << std::endl;
	}

	while (true) {
		std::cout << "Enter one of the commands - ADD,SEARCH or EXIT: ";
		std::getline(std::cin, inputLine);
		if (inputLine == "ADD")
			phoneBook.addOption();
		else if (inputLine == "SEARCH")
			phoneBook.searchOption();
		else if (inputLine == "EXIT")
			return (0);
		else
			std::cout << "Wrong command! Try again..." << std::endl;
	}
	return (0);
}
