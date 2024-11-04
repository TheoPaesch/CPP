/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GetInfo.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:38:27 by tpaesch           #+#    #+#             */
/*   Updated: 2024/11/04 16:46:48 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

std::string getFirstName() {
	std::string firstName;
	std::cout << "Enter first name: ";
	std::cin >> firstName;
	return firstName;
}

std::string getLastName() {
	std::string lastName;
	std::cout << "Enter last name: ";
	std::cin >> lastName;
	return lastName;
}

std::string getNickname() {
	std::string nickname;
	std::cout << "Enter nickname: ";
	std::cin >> nickname;
	return nickname;
}

std::string getPhoneNumber() {
	std::string phoneNumber;
	std::cout << "Enter phone number: ";
	std::cin >> phoneNumber;
	return phoneNumber;
}

std::string getDarkestSecret() {
	std::string darkestSecret;
	std::cout << "Enter darkest secret: ";
	std::cin >> darkestSecret;
	return darkestSecret;
}
