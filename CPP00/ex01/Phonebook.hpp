/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:11:13 by tpaesch           #+#    #+#             */
/*   Updated: 2024/11/04 13:21:14 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>

class Contact {
private:
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string darkestSecret;

public:
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

	std::string getFirstName() const {
		return firstName;
	}

	std::string getLastName() const {
		return lastName;
	}

	std::string getNickname() const {
		return nickname;
	}

	std::string getPhoneNumber() const {
		return phoneNumber;
	}

	std::string getDarkestSecret() const {
		return darkestSecret;
	}
};

class PhoneBook {
private:
	Contact contacts[8];
	int currentIndex;
	int totalContacts;

public:
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
};

#endif