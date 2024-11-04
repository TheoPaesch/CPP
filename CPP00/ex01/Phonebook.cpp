/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:11:15 by tpaesch           #+#    #+#             */
/*   Updated: 2024/11/04 17:28:38 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

PhoneBook() : currentIndex(0), totalContacts(0) {}

void addContact(const Contact& contact) {
	contacts[currentIndex] = contact;
	currentIndex = (currentIndex + 1) % 8;
	if (totalContacts < 8) {
		totalContacts++;
	}
}

void displayContacts() const {
	for (int i = 0; i < totalContacts; i++) {
		std::cout << "Contact " << i + 1 << ":" << std::endl;
		contacts[i].displayContact();
		std::cout << std::endl;
	}
}

void setContact(std::string fn, std::string ln, std::string nn, std::string pn, std::string ds) {
	firstName = fn;
	lastName = ln;
	nickname = nn;
	phoneNumber = pn;
	darkestSecret = ds;
}

void displayContact() const {
	std::cout << "First Name: " << firstName << std::endl;
	std::cout << "Last Name: " << lastName << std::endl;
	std::cout << "Nickname: " << nickname << std::endl;
	std::cout << "Phone Number: " << phoneNumber << std::endl;
	std::cout << "Darkest Secret: " << darkestSecret << std::endl;
}

void addContact(PhoneBook &phoneBook) {
	std::string firstName = getFirstName();
	std::string lastName = getLastName();
	std::string nickname = getNickname();
	std::string phoneNumber = getPhoneNumber();
	std::string darkestSecret = getDarkestSecret();

	Contact newContact;
	newContact.setContact(firstName, lastName, nickname, phoneNumber, darkestSecret);
	phoneBook.addContact(newContact);
}

void displayContacts(const PhoneBook &phoneBook) {
	phoneBook.displayContacts();
}

void handleUserInput(PhoneBook &phoneBook) {
	char choice;

	while (true) {
		std::cout << "Enter 'ADD' to add a contact, 'SEARCH' to display contacts, 'EXIT' to quit: ";
		std::cin >> choice;

		if (choice == 'a') {
			addContact(phoneBook);
		} else if (choice == 'd') {
			displayContacts(phoneBook);
		} else if (choice == 'q') {
			break;
		} else {
			std::cout << "Invalid choice. Please try again." << std::endl;
		}
	}
}
