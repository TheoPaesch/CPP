/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 20:21:22 by tpaesch           #+#    #+#             */
/*   Updated: 2024/12/12 15:28:00 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("DefaultScav") {
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "\033[33mAAAALAARRMM " << _name << " was constructed!\033[0m" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "\033[34mAAAALAARRMM " << _name << " was constructed!\033[0m" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
	*this = other;
	std::cout << "\033[96mAAAALAARRMM " << _name << " was copied!\033[0m" << std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << "\033[31mAAAALAARRMM " << _name << " was destructed!\033[0m" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
	if (this != &other) {
		ClapTrap::operator=(other);
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
	}
	return *this;
}

void ScavTrap::guardGate() {
	std::cout << "\033[32mBleepBloop " << _name << " has switched to Gate keeper mode.\033[0m" << std::endl;
}
