/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 13:31:05 by tpaesch           #+#    #+#             */
/*   Updated: 2024/12/06 15:09:04 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMateriaSource.hpp"

IMateriaSource::IMateriaSource() {
}

IMateriaSource::IMateriaSource(const IMateriaSource& other) {
	*this = other;
}

IMateriaSource::~IMateriaSource() {
}

IMateriaSource& IMateriaSource::operator=(const IMateriaSource& other) {
	if (this != &other)
		;
	return *this;
}

void IMateriaSource::learnMateria(AMateria* m) {
	(void)m;
}

AMateria* IMateriaSource::createMateria(std::string const & type) {
	(void)type;
	return 0;
}

