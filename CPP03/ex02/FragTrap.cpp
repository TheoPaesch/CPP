/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:25:38 by tpaesch           #+#    #+#             */
/*   Updated: 2024/12/04 18:41:08 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FR4G-TR4P " << _name << " was constructed!" << std::endl;
}

FragTrap::~FragTrap() {
	std::cout << "FR4G-TR4P " << _name << " was destructed!" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
	if (this != &other) {
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
	}
	return *this;
}

void FragTrap::highFivesGuys() {
	std::cout << "FR4G-TR4P " << _name << " IS ABSOLUTELY HYPED! High five the person to the right!" << std::endl;
}
