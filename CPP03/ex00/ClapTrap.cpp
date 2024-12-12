/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 20:22:49 by tpaesch           #+#    #+#             */
/*   Updated: 2024/12/12 15:21:29 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _hitPoints(10), _energyPoints(10), _attackDamage(0), _name("DefaultClap") {
	std::cout << "\033[35m" << "*Mashine and metal noises* " << _name << " was constructed!" << "\033[0m" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _hitPoints(10), _energyPoints(10), _attackDamage(0), _name(name) {
	std::cout << "\033[36m" << "*Mashine and metal noises* " << _name << " was constructed!" << "\033[0m" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) {
	*this = other;
	std::cout << "\033[95m" << "*Mashine and metal noises* " << _name << " was copied!" << "\033[0m" << std::endl;
}

ClapTrap::~ClapTrap() {
	std::cout << "\033[31m" << "*Mashine and metal noises* " << _name << " was destructed!" << "\033[0m" << std::endl;
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
	if (_energyPoints > 0){
		_energyPoints--;
		std::cout << "\033[34mBeepBoop " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!\033[0m" << std::endl;
		if (isDead())
			std::cout << "\033[41mBeepBoop " << _name << " is dead!\033[0m" << std::endl;
	}
	else
		std::cout << "\033[90mBeepBoop " << _name << " is out of energy!\033[0m" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	_energyPoints--;
	_hitPoints -= amount;
	std::cout << "BeepBoop " << _name << " takes \033[91m" << amount << " points of damage!\033[0m" << std::endl;
	if (isDead())
		std::cout << "\033[41mBeepBoop " << _name << " is dead!\033[0m" << std::endl;
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
			std::cout << "\033[47mBeepBoop " << _name << " is resurrected!\033[0m" << std::endl;
		std::cout << "\033[32mBeepBoop " << _name << " is repaired for " << amount << " points!\033[0m" << std::endl;
	}
	else
		std::cout << "\033[90mBeepBoop " << _name << " is out of energy!\033[0m" << std::endl;
}
