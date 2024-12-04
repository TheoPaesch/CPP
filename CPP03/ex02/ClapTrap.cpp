/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 20:22:49 by tpaesch           #+#    #+#             */
/*   Updated: 2024/12/04 17:05:50 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : _hitPoints(10), _energyPoints(10), _attackDamage(0), _name(name) {
	std::cout << "*Mashine and metal noises* " << _name << " was constructed!" << std::endl;
}

ClapTrap::~ClapTrap() {
	std::cout << "*Mashine and metal noises* " << _name << " was destructed!" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
	if (this != &other) {
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
	}
	return *this;
}

bool ClapTrap::isDead() {
	return _hitPoints <= 0;
}	

void ClapTrap::attack(std::string const& target) {
	_energyPoints--;
	std::cout << "BeepBoop " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
	if (isDead())
		std::cout << "BeepBoop " << _name << " is dead!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	_energyPoints--;
	_hitPoints -= amount;
	std::cout << "BeepBoop " << _name << " takes " << amount << " points of damage!" << std::endl;
	if (isDead())
		std::cout << "BeepBoop " << _name << " is dead!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	bool alive = 1;

	_energyPoints--;
	if (_hitPoints <= 0)
		alive = 0;
	_hitPoints += amount;
	if (_hitPoints > 0 && !alive)
		std::cout << "BeepBoop " << _name << " is resurrected!" << std::endl;
	std::cout << "BeepBoop " << _name << " is repaired for " << amount << " points!" << std::endl;
}

// Getter functions
std::string ClapTrap::getName() const {
	return _name;
}

int ClapTrap::getHitPoints() const {
	return _hitPoints;
}

int ClapTrap::getEnergyPoints() const {
	return _energyPoints;
}

int ClapTrap::getAttackDamage() const {
	return _attackDamage;
}
