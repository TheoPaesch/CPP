/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:11:15 by tpaesch           #+#    #+#             */
/*   Updated: 2024/11/04 13:17:57 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"


int main() {
	PhoneBook phoneBook;
	std::string firstName, lastName, nickname, phoneNumber, darkestSecret;
	char choice;

	while (true) {
		std::cout << "Enter 'a' to add a contact, 'd' to display contacts, 'q' to quit: ";
		std::cin >> choice;

		if (choice == 'a') {
			std::cout << "Enter first name: ";
			std::cin >> firstName;
			std::cout << "Enter last name: ";
			std::cin >> lastName;
			std::cout << "Enter nickname: ";
			std::cin >> nickname;
			std::cout << "Enter phone number: ";
			std::cin >> phoneNumber;
			std::cout << "Enter darkest secret: ";
			std::cin >> darkestSecret;

			Contact newContact;
			newContact.setContact(firstName, lastName, nickname, phoneNumber, darkestSecret);
			phoneBook.addContact(newContact);
		} else if (choice == 'd') {
			phoneBook.displayContacts();
		} else if (choice == 'q') {
			break;
		} else {
			std::cout << "Invalid choice. Please try again." << std::endl;
		}
	}

	return 0;
}