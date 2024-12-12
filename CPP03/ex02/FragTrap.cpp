/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:25:38 by tpaesch           #+#    #+#             */
/*   Updated: 2024/12/12 15:29:35 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("DefaultFrag") {
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "\033[33mFR4G-TR4P " << _name << " was constructed!\033[0m" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "\033[34mFR4G-TR4P " << _name << " was constructed!\033[0m" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
	*this = other;
	std::cout << "\033[96mFR4G-TR4P " << _name << " was copied!\033[0m" << std::endl;
}

FragTrap::~FragTrap() {
	std::cout << "\033[31mFR4G-TR4P " << _name << " was destructed!\033[0m" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
	if (this != &other) {
		ClapTrap::operator=(other);
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
	}
	return *this;
}

void FragTrap::highFivesGuys() {
	std::cout << "\033[32mFR4G-TR4P " << _name << " IS ABSOLUTELY HYPED! High five the person to the right!\033[0m" << std::endl;
}
