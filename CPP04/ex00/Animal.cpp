/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 17:43:20 by tpaesch           #+#    #+#             */
/*   Updated: 2024/12/15 20:42:58 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Colors.hpp"

Animal::Animal() : _type("Animal") {
	std::cout << BRIGHT_BLUE << "Animal default constructor" << RESET << std::endl;
}

Animal::Animal(std::string type) : _type(type) {
	std::cout << BRIGHT_BLUE << "Animal constructor with type" << RESET << std::endl;
}

Animal::Animal(const Animal& other) {
	std::cout << BRIGHT_BLUE << "Animal copy constructor" << RESET << std::endl;
	*this = other;
}

Animal::~Animal() {
	std::cout << BRIGHT_BLUE << "Animal destructor" << RESET << std::endl;
}

Animal& Animal::operator=(const Animal& other) {
	std::cout << BRIGHT_BLUE << "Animal assignation operator" << RESET << std::endl;
	if (this != &other)
		_type = other._type;
	return *this;
}

std::string Animal::getType() const {
	return _type;
}

void Animal::makeSound() const {
	std::cout << BLUE << "Animal sound" << RESET << std::endl;
}

