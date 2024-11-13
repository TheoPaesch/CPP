/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:11:13 by tpaesch           #+#    #+#             */
/*   Updated: 2024/11/11 19:55:50 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <cctype>

/*Classes*/

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
		void setContact(const std::string& fn, const std::string& ln, const std::string& nn, const std::string& pn, const std::string& ds);
		void displayContactInfo();
		std::string& getFirstName();
		std::string& Contact::getLastName();
		std::string& Contact::getNickname();
		std::string& Contact::getPhoneNumber();
		std::string& Contact::getDarkestSecret();
};

class PhoneBook {
	private:
		Contact contacts[8];
		int currentIndex;
		int totalContacts;

	public:
		PhoneBook();
		~PhoneBook();
		void addContact(Contact& contact);
		void displayContacts();
		void ContactIndexCheck(const Contact& contact)
	};

#endif 