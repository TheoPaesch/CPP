/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 17:44:07 by tpaesch           #+#    #+#             */
/*   Updated: 2024/12/15 21:39:22 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Colors.hpp"

Dog::Dog() : Animal("Dog") {
	std::cout << BRIGHT_GREEN << "Dog default constructor" << RESET << std::endl;
	_brain = new Brain();
}

Dog::Dog(const Dog& other) {
	std::cout << BRIGHT_GREEN << "Dog copy constructor" << RESET << std::endl;
	_brain = new Brain(*other._brain);
	*this = other;
}

Dog::~Dog() {
	std::cout << BRIGHT_GREEN << "Dog destructor" << RESET << std::endl;
	delete _brain;
}

Dog& Dog::operator=(const Dog& other) {
	std::cout << BRIGHT_GREEN << "Dog assignation operator" << RESET << std::endl;
	if (this != &other) {
		_type = other._type;
		delete _brain;
		_brain = new Brain(*other._brain);
	}
	return *this;
}

void Dog::makeSound() const {
	std::cout << GREEN << "Bork Bork" << RESET << std::endl;
}

