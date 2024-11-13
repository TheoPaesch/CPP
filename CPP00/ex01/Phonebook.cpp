/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:11:15 by tpaesch           #+#    #+#             */
/*   Updated: 2024/11/11 19:55:42 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

/*Constructor Destructor*/
PhoneBook::PhoneBook() {
	// std::cout << "Constuctor - PhoneBook" << std::endl;
}
PhoneBook::~PhoneBook() {
	// std::cout << "Destructor - PhoneBook" << std::endl;
}

/*Constructor Destructor*/
Contact::Contact(){
// std::cout << "Constuctor - Contact" << std::endl;
}
Contact::~Contact(){
// std::cout << "Destructor - Contact" << std::endl;
}

void PhoneBook::displayContacts() {
	for (int i = 0; i < totalContacts; i++) {
		std::cout << "Contact " << i + 1 << ":" << std::endl;
		contacts[i].displayContact();
		std::cout << std::endl;
	}
}

void Contact::setContact(const std::string& fn,const std::string& ln,const std::string& nn,const std::string &pn,const std::string& ds) {
	firstName = fn;
	lastName = ln;
	nickname = nn;
	phoneNumber = pn;
	darkestSecret = ds;
}

void Contact::displayContact() {
	std::cout << "First Name: " << firstName << std::endl;
	std::cout << "Last Name: " << lastName << std::endl;
	std::cout << "Nickname: " << nickname << std::endl;
	std::cout << "Phone Number: " << phoneNumber << std::endl;
	std::cout << "Darkest Secret: " << darkestSecret << std::endl;
}

void PhoneBook::addContact(Contact& contact) {
	std::string firstName = contact.getFirstName();
	std::string lastName = contact.getLastName();
	std::string nickname = contact.getNickname();
	std::string phoneNumber = contact.getPhoneNumber();
	std::string darkestSecret = contact.getDarkestSecret();

	Contact newContact;
	newContact.setContact(firstName, lastName, nickname, phoneNumber, darkestSecret);
	addContact(newContact);
}

// Display contact information
void Contact::displayContactInfo() {
    std::cout << "First Name: " << firstName << std::endl;
    std::cout << "Last Name: " << lastName << std::endl;
    std::cout << "Nickname: " << nickname << std::endl;
    std::cout << "Phone Number: " << phoneNumber << std::endl;
    std::cout << "Darkest Secret: " << darkestSecret << std::endl;
}
