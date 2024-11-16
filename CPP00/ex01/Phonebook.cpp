/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:11:15 by tpaesch           #+#    #+#             */
/*   Updated: 2024/11/14 16:16:22 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

/*Constructor Destructor*/
PhoneBook::PhoneBook() : currentIndex(0), totalContacts(0) {
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
		contacts[i].displayContactInfo();
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

void PhoneBook::addContact() {
	std::string firstName = contacts[currentIndex].getFirstName();
	if (std::cin.eof()) 
		return ;
	std::string lastName = contacts[currentIndex].getLastName();
	if (std::cin.eof()) 
		return ;
	std::string nickname = contacts[currentIndex].getNickname();
	if (std::cin.eof()) 
		return ;
	std::string phoneNumber = contacts[currentIndex].getPhoneNumber();
	if (std::cin.eof()) 
		return ;
	std::string darkestSecret = contacts[currentIndex].getDarkestSecret();

	Contact newContact;
	newContact.setContact(firstName, lastName, nickname, phoneNumber, darkestSecret);
	ContactIndexCheck(newContact);
}

// Display contact information
void Contact::displayContactInfo() {
    std::cout << "First Name: " << firstName << std::endl;
    std::cout << "Last Name: " << lastName << std::endl;
    std::cout << "Nickname: " << nickname << std::endl;
    std::cout << "Phone Number: " << phoneNumber << std::endl;
    std::cout << "Darkest Secret: " << darkestSecret << std::endl;
}

// Display contact summary for search
void Contact::displaySummary(int index) {
	std::cout << std::setw(10) << index << "|";
	std::cout << std::setw(10) << (firstName.length() > 10 ? firstName.substr(0, 9) + "." : firstName) << "|";
	std::cout << std::setw(10) << (lastName.length() > 10 ? lastName.substr(0, 9) + "." : lastName) << "|";
	std::cout << std::setw(10) << (nickname.length() > 10 ? nickname.substr(0, 9) + "." : nickname) << std::endl;
}

// Search and display contacts in PhoneBook
void PhoneBook::searchContacts() {
    std::cout << std::setw(10) << "Index" << "|";
    std::cout << std::setw(10) << "First Name" << "|";
    std::cout << std::setw(10) << "Last Name" << "|";
    std::cout << std::setw(10) << "Nickname" << std::endl;
    std::cout << "-------------------------------------------" << std::endl;

    for (int i = 0; i < totalContacts; i++) {
        contacts[i].displaySummary(i + 1);
    }

    int index;
    std::cout << "Enter the index of the contact to display: ";
    std::cin >> index;

	if (std::cin.eof()) {
		std::cout << "EOF detected. Returning to main menu." << std::endl;
		std::cin.clear();
		return;
	}
	else if (std::cin.fail() || index < 1 || index > totalContacts) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Invalid index. Back to the lobby." << std::endl;
		return;
	} else
		contacts[index - 1].displayContactInfo();
	std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
