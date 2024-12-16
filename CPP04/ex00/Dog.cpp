/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 17:44:07 by tpaesch           #+#    #+#             */
/*   Updated: 2024/12/15 20:43:10 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Colors.hpp"

Dog::Dog() : Animal("Dog") {
	std::cout << BRIGHT_BLUE << "Dog default constructor" << RESET << std::endl;
}

Dog::Dog(const Dog& other) {
	std::cout << BRIGHT_BLUE << "Dog copy constructor" << RESET << std::endl;
	*this = other;
}

Dog::~Dog() {
	std::cout << BRIGHT_BLUE << "Dog destructor" << RESET << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
	std::cout << BRIGHT_BLUE << "Dog assignation operator" << RESET << std::endl;
	if (this != &other)
		_type = other._type;
	return *this;
}

void Dog::makeSound() const {
	std::cout << BLUE << "Bork Bork" << RESET << std::endl;
}
