/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 16:52:26 by tpaesch           #+#    #+#             */
/*   Updated: 2024/12/17 16:52:32 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "MateriaSource.hpp"
#include "Colors.hpp"

MateriaSource::MateriaSource() {
    std::fill_n(_m, MAX_MATERIA, static_cast<AMateria*>(NULL));
}

// Copy Constructor
MateriaSource::MateriaSource(const MateriaSource& other) {
    std::fill_n(_m, MAX_MATERIA, static_cast<AMateria*>(NULL));
    *this = other;
}


// Copy Assignment Operator
MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
    if (this != &other) {
        deleteMaterias();
        for (int i = 0; i < MAX_MATERIA; ++i) {
            _m[i] = other._m[i] ? other._m[i]->clone() : NULL;
        }
    }
    return *this;
}

MateriaSource::~MateriaSource() {
    deleteMaterias();
}

void MateriaSource::deleteMaterias() {
    for (int i = 0; i < MAX_MATERIA; ++i) {
        delete _m[i];
        _m[i] = NULL;
    }
}

void MateriaSource::learnMateria(AMateria* m) {
    for (int i = 0; i < MAX_MATERIA; ++i) {
        if (!_m[i]) {
            _m[i] = m;
            std::cout << GREEN << "Materia learned successfully." << RESET << std::endl;
            return;
        }
    }
    std::cout << RED << "Materia limit reached." << RESET << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const& type) {
    for (int i = 0; i < MAX_MATERIA; ++i) {
        if (_m[i] && _m[i]->getType() == type) {
            return _m[i]->clone();
        }
    }
    std::cout << RED << "No matching type found for creation." << RESET << std::endl;
    return NULL;
}
