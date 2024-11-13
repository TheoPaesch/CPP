/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parsing.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 19:21:11 by tpaesch           #+#    #+#             */
/*   Updated: 2024/11/11 19:27:47 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

bool InputCheck(std::string input, int switchCase) {
	if (input.empty()) {
		std::cout << "Error: Input cannot be empty. Please try again." << std::endl;
		return false;
	}
	if (switchCase == 1) {
		for (char c : input) {
			if (!std::isalpha(static_cast<unsigned char>(c))) {
				std::cout << "Error: Your input must contain only alphabetic characters. Please try again." << std::endl;
				return false;
			}
		}
	} else if (switchCase == 2) {
		for (char c : input) {
			if (!std::isdigit(static_cast<unsigned char>(c))) {
				std::cout << "Error: Your input must contain only numeric characters. Please try again." << std::endl;
				return false;
			}
		}
	} else if (switchCase == 3) {
		for (char c : input) {
			if (!std::isalnum(static_cast<unsigned char>(c))) {
				std::cout << "Error: Your input must contain only alphanumeric characters. Please try again." << std::endl;
				return false;
			}
		}
	}
	return true;
}

void PhoneBook::ContactIndexCheck(const Contact& contact) {
	contacts[currentIndex] = contact;
	currentIndex = (currentIndex + 1) % 8;
	if (totalContacts < 8) {
		totalContacts++;
	}
}
