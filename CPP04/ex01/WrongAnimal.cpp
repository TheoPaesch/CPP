/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 17:44:57 by tpaesch           #+#    #+#             */
/*   Updated: 2024/12/15 20:43:16 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include "Colors.hpp"

WrongAnimal::WrongAnimal() : _type("WrongAnimal") {
	std::cout << BRIGHT_RED << "WrongAnimal default constructor" << RESET << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : _type(type) {
	std::cout << BRIGHT_RED << "WrongAnimal constructor with type" << RESET << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) {
	std::cout << BRIGHT_RED << "WrongAnimal copy constructor" << RESET << std::endl;
	*this = other;
}

WrongAnimal::~WrongAnimal() {
	std::cout << BRIGHT_RED << "WrongAnimal destructor" << RESET << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
	std::cout << BRIGHT_RED << "WrongAnimal assignation operator" << RESET << std::endl;
	if (this != &other)
		_type = other._type;
	return *this;
}

std::string WrongAnimal::getType() const {
	return _type;
}

void WrongAnimal::makeSound() const {
	std::cout << RED << "I do da Bork Bork. Trust me I'm an animal" << RESET << std::endl;
}
