/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 12:50:36 by tpaesch           #+#    #+#             */
/*   Updated: 2024/12/06 13:49:02 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(std::string const & type) : _type(type) {
}

AMateria::AMateria(const AMateria& other) {
	*this = other;
}

AMateria::~AMateria() {
}

AMateria& AMateria::operator=(const AMateria& other) {
	if (this != &other)
		_type = other._type;
	return *this;
}

std::string const & AMateria::getType() const {
	return _type;
}

void AMateria::use(ICharacter& target) {
	(void)target;
}

AMateria* AMateria::clone() const {
	return 0;
}