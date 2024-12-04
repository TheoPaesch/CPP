/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 20:22:49 by tpaesch           #+#    #+#             */
/*   Updated: 2024/12/03 19:35:52 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _hitPoints(10), _energyPoints(10), _attackDamage(0), _name("ClapTrap") {}

ClapTrap::ClapTrap(std::string name) : _hitPoints(10), _energyPoints(10), _attackDamage(0), _name(name) {}

ClapTrap::ClapTrap(const ClapTrap& other) {
	*this = other;
}

ClapTrap::~ClapTrap() {}

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
	if (_energyPoints > 0){
		_energyPoints--;
		std::cout << "BeepBoop " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
		if (isDead())
			std::cout << "BeepBoop " << _name << " is dead!" << std::endl;
	}
	else
		std::cout << "BeepBoop " << _name << " is out of energy!" << std::endl;
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

	if (_energyPoints > 0)
	{
		_energyPoints--;
		if (_hitPoints <= 0)
			alive = 0;
		_hitPoints += amount;
		if (_hitPoints > 0 && !alive)
			std::cout << "BeepBoop " << _name << " is resurrected!" << std::endl;
		std::cout << "BeepBoop " << _name << " is repaired for " << amount << " points!" << std::endl;
	}
	else
		std::cout << "BeepBoop " << _name << " is out of energy!" << std::endl;
}
