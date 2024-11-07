/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GetInfo.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:38:27 by tpaesch           #+#    #+#             */
/*   Updated: 2024/11/07 20:15:49 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

/*Constructor Destructor*/
Contact::Contact() {
	std::cout << "Constuctor - Contact" << std::endl;
}
Contact::~Contact() {
	std::cout << "Destructor - Contact" << std::endl;
}

std::string&	Contact::getFirstName() {
	std::string firstName;
	std::cout << "Enter first name: ";
	std::cin >> firstName;
	return firstName;
}

std::string&	Contact::getLastName() {
	std::string lastName;
	std::cout << "Enter last name: ";
	std::cin >> lastName;
	return lastName;
}

std::string&	Contact::getNickname() {
	std::string nickname;
	std::cout << "Enter nickname: ";
	std::cin >> nickname;
	return nickname;
}

std::string&	Contact::getPhoneNumber() {
	std::string phoneNumber;
	std::cout << "Enter phone number: ";
	std::cin >> phoneNumber;
	return phoneNumber;
}

std::string&	Contact::getDarkestSecret() {
	std::string darkestSecret;
	std::cout << "Enter darkest secret: ";
	std::cin >> darkestSecret;
	return darkestSecret;
}
