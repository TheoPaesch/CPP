/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:11:13 by tpaesch           #+#    #+#             */
/*   Updated: 2024/11/07 20:49:22 by tpaesch          ###   ########.fr       */
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
	Contact();
	~Contact();
	std::string&	getFirstName();
	std::string&	getLastName();
	std::string&	getNickname();
	std::string&	getPhoneNumber();
	std::string&	getDarkestSecret();
};

class PhoneBook {
private:
	Contact contacts[8];
	int currentIndex;
	int totalContacts;

public:
	PhoneBook();
	~PhoneBook();
	void addContact(Contact& contact, PhoneBook& phonebook) ;
};

#endif