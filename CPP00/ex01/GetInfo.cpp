/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GetInfo.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:38:27 by tpaesch           #+#    #+#             */
/*   Updated: 2024/11/14 12:39:33 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

bool InputCheck(std::string input, int switchCase);

// Getter methods
std::string& Contact::getFirstName() {
    while (true) {
        std::cout << "Enter first name: ";
		if (std::cin.eof()) 
		{
		std::cout << "EOF detected. Exiting program." << std::endl;
		break;
		}
        std::cin >> firstName;

       	bool isValid = InputCheck(firstName, 1);
        if (isValid) 
            break;
    }
    return firstName;
}

std::string& Contact::getLastName() {
	while (true) {
		std::cout << "Enter last name: ";
		if (std::cin.eof()) 
		{
		std::cout << "EOF detected. Exiting program." << std::endl;
		break;
		}
		std::cin >> lastName;

		bool isValid = InputCheck(lastName, 1);
		if (isValid) 
			break;
	}
    return lastName;
}

std::string& Contact::getNickname() {
	while (true) {
		std::cout << "Enter nickname: ";
		if (std::cin.eof()) 
		{
		std::cout << "EOF detected. Exiting program." << std::endl;
		break;
		}
		std::cin >> nickname;

		bool isValid = InputCheck(nickname, 1);
		if (isValid) 
			break;
	}
    return nickname;
}

std::string& Contact::getPhoneNumber() {
	while(true) {
		std::cout << "Enter phone number: ";
		if (std::cin.eof()) 
		{
		std::cout << "EOF detected. Exiting program." << std::endl;
		break;
		}
		std::cin >> phoneNumber;

		bool isValid = InputCheck(phoneNumber, 2);
		if (isValid) 
			break;
	}
    return phoneNumber;
}

std::string& Contact::getDarkestSecret() {
	while(true) {
		std::cout << "Enter darkest secret: ";
		if (std::cin.eof()) 
		{
		std::cout << "EOF detected. Exiting program." << std::endl;
		break;
		}
		std::cin >> darkestSecret;

		bool isValid = InputCheck(darkestSecret, 1);
		if (isValid)
			break;
	}
    return darkestSecret;
}
