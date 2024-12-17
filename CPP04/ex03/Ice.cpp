/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 13:29:18 by tpaesch           #+#    #+#             */
/*   Updated: 2024/12/17 16:41:46 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "Colors.hpp"

Ice::Ice() : AMateria("ice") {
}

Ice::Ice(const Ice& other) : AMateria(other) {
	*this = other;
}

Ice::~Ice() {
}

Ice& Ice::operator=(const Ice& other) {
	if (this != &other)
		;
	return *this;
}

AMateria* Ice::clone() const {
	return new Ice();
}

void Ice::use(ICharacter& target) {
	std::cout << BRIGHT_BLUE << "* shoots an ice bolt at " << target.getName() << " *" << RESET << std::endl;
}
