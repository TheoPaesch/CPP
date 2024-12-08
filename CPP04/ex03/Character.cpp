/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 13:43:46 by tpaesch           #+#    #+#             */
/*   Updated: 2024/12/06 13:44:29 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() {
}

Character::Character(const Character& other) {
	*this = other;
}

Character::~Character() {
}

Character& Character::operator=(const Character& other) {
	if (this != &other)
		;
	return *this;
}

Character::Character(std::string name) : _name(name) {
}

Character::Character(std::string name, int idx) : _name(name), _idx(idx) {
}

Character::Character(std::string name, int idx, AMateria* m) : _name(name), _idx(idx), _m(m) {
}

std::string const & Character::getName() const {
	return _name;
}

void Character::equip(AMateria* m) {
	(void)m;
}

void Character::unequip(int idx) {
	(void)idx;
}

void Character::use(int idx, ICharacter& target) {
	(void)idx;
	(void)target;
}

void Character::setMateria(AMateria* m) {
	_m = m;
}

void Character::setIdx(int idx) {
	_idx = idx;
}

void Character::setName(std::string name) {
	_name = name;
}

AMateria* Character::getMateria() const {
	return _m;
}

int Character::getIdx() const {
	return _idx;
}

std::string Character::getName() const {
	return _name;
}

void Character::use(int idx, ICharacter& target) {
	(void)idx;
	(void)target;
}

void Character::equip(AMateria* m) {
	(void)m;
}

void Character::unequip(int idx) {
	(void)idx;
}

void Character::setMateria(AMateria* m) {
	_m = m;
}

