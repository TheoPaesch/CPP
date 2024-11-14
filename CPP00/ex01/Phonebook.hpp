/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:11:13 by tpaesch           #+#    #+#             */
/*   Updated: 2024/11/14 10:29:05 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <iomanip>
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
		void displaySummary(int index);
		std::string& getFirstName();
		std::string& getLastName();
		std::string& getNickname();
		std::string& getPhoneNumber();
		std::string& getDarkestSecret();
};

class PhoneBook {
	private:
		Contact contacts[8];
		int currentIndex;
		int totalContacts;

	public:
		PhoneBook();
		~PhoneBook();
		void searchContacts();
		void ContactIndexCheck(const Contact& contact);
		void addContact();
		void displayContacts();
};


/*Functions*/

void ContactIndexCheck(const Contact& contact);


#endif 