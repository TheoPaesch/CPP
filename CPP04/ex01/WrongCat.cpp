/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 17:46:02 by tpaesch           #+#    #+#             */
/*   Updated: 2024/12/15 20:43:21 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include "Colors.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat") {
	std::cout << BRIGHT_RED << "WrongCat default constructor" << RESET << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) {
	std::cout << BRIGHT_RED << "WrongCat copy constructor" << RESET << std::endl;
	*this = other;
}

WrongCat::~WrongCat() {
	std::cout << BRIGHT_RED << "WrongCat destructor" << RESET << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
	std::cout << BRIGHT_RED << "WrongCat assignation operator" << RESET << std::endl;
	if (this != &other)
		_type = other._type;
	return *this;
}

void WrongCat::makeSound() const {
	std::cout << RED << "Kaka Kaka. I'm a bird" << RESET << std::endl;
}
