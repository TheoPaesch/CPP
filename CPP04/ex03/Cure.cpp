/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 13:28:46 by tpaesch           #+#    #+#             */
/*   Updated: 2024/12/17 16:53:13 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "Colors.hpp"
#include "ICharacter.hpp"

Cure::Cure() : AMateria("cure") {
}

Cure::Cure(const Cure& other) : AMateria(other) {
	*this = other;
}

Cure::~Cure() {
}

Cure& Cure::operator=(const Cure& other) {
	if (this != &other)
		;
	return *this;
}

AMateria* Cure::clone() const {
	return new Cure(*this);
}

void Cure::use(ICharacter& target) {
	std::cout << BRIGHT_GREEN << "* heals " << target.getName() << "'s wounds *" << RESET << std::endl;
}

