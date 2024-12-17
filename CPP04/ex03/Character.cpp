/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 16:51:43 by tpaesch           #+#    #+#             */
/*   Updated: 2024/12/17 16:51:48 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "Colors.hpp"

Character::Character(const std::string& name) : _name(name), _idx(0) {
    std::fill_n(_Inventory, MAX_MATERIA, static_cast<AMateria*>(NULL));
}

Character::Character(const Character& other) : _name(other._name), _idx(other._idx) {
    for (int i = 0; i < MAX_MATERIA; ++i) {
        _Inventory[i] = other._Inventory[i] ? other._Inventory[i]->clone() : NULL;
    }
}


// Character Copy Assignment Operator
Character& Character::operator=(const Character& other) {
    if (this != &other) {
        _name = other._name;
        _idx = other._idx;
        deleteMaterias();
        for (int i = 0; i < MAX_MATERIA; ++i) {
            _Inventory[i] = other._Inventory[i] ? other._Inventory[i]->clone() : NULL;
        }
    }
    return *this;
}

Character::~Character() {
    deleteMaterias();
}

void Character::deleteMaterias() {
    for (int i = 0; i < MAX_MATERIA; ++i) {
        if (_Inventory[i])
       {
            delete _Inventory[i];
            _Inventory[i] = NULL;
       } 
    }
}


std::string const& Character::getName() const {
    return _name;
}

void Character::equip(AMateria* m) {
    for (int i = 0; i < MAX_MATERIA; ++i) {
        if (!_Inventory[i]) {
            _Inventory[i] = m;
            std::cout << GREEN << "Materia equipped" << RESET << std::endl;
            return;
        }
    }
    std::cout << YELLOW << "Character inventory is full!" << RESET << std::endl;
    delete m; // Delete the materia if it can't be equipped
}


void Character::unequip(int idx) {
    if (idx < 0 || idx >= MAX_MATERIA) {
        std::cout << RED << "Invalid inventory slot index" << RESET << std::endl;
        return;
    }
    if (!_Inventory[idx]) {
        std::cout << YELLOW << "This slot is empty and can't be unequipped" << RESET << std::endl;
        return;
    }
    _Inventory[idx] = NULL;
    std::cout << GREEN << "Materia unequipped" << RESET << std::endl;
}

void Character::use(int idx, ICharacter& target) {
    if (idx < 0 || idx >= MAX_MATERIA) {
        std::cout << RED << "Invalid inventory slot index" << RESET << std::endl;
        return;
    }
    
    if (!_Inventory[idx]) {
        std::cout << YELLOW << "This slot is empty and can't be used" << RESET << std::endl;
        return;
    }

    // Check if the _Inventory[idx] pointer is not null before calling use()
    if (_Inventory[idx]) {
        _Inventory[idx]->use(target);
    }
}
