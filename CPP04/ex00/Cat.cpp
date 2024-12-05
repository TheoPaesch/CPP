/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 17:43:45 by tpaesch           #+#    #+#             */
/*   Updated: 2024/12/05 17:44:05 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() {
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat& other) {
	std::cout << "Cat copy constructor called" << std::endl;
	*this = other;
}

Cat::~Cat() {
	std::cout << "Cat destructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
	std::cout << "Cat assignation operator called" << std::endl;
	if (this != &other)
		;
	return *this;
}

void Cat::makeSound() const {
	std::
	cout << "Meow Meow" << std::endl;
}

