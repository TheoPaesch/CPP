/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 17:43:45 by tpaesch           #+#    #+#             */
/*   Updated: 2024/12/15 20:43:04 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Colors.hpp"

Cat::Cat() : Animal("Cat") {
	std::cout << BRIGHT_BLUE << "Cat default constructor" << RESET << std::endl;
}

Cat::Cat(const Cat& other) {
	std::cout << BRIGHT_BLUE << "Cat copy constructor" << RESET << std::endl;
	*this = other;
}

Cat::~Cat() {
	std::cout << BRIGHT_BLUE << "Cat destructor" << RESET << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
	std::cout << BRIGHT_BLUE << "Cat assignation operator" << RESET << std::endl;
	if (this != &other)
		_type = other._type;
	return *this;
}

void Cat::makeSound() const {
	std::cout << BLUE << "Meow meow" << RESET << std::endl;
}
