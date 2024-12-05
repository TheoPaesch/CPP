/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 17:44:07 by tpaesch           #+#    #+#             */
/*   Updated: 2024/12/05 17:44:20 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() {
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog& other) {
	std::cout << "Dog copy constructor called" << std::endl;
	*this = other;
}

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
	std::cout << "Dog assignation operator called" << std::endl;
	if (this != &other)
		;
	return *this;
}

void Dog::makeSound() const {
	std::cout << "Woof Woof" << std::endl;
}

