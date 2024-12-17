/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 12:50:36 by tpaesch           #+#    #+#             */
/*   Updated: 2024/12/17 16:16:43 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Colors.hpp"

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
	std::cout << YELLOW << "* proceedes to roundhousekick " << target.getName() << " with full force *" << RESET << std::endl;
}

// AMateria* AMateria::clone() const {
// 	return 0;
// }