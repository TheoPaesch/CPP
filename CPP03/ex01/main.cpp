/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 20:21:29 by tpaesch           #+#    #+#             */
/*   Updated: 2024/12/12 15:23:04 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main() {

	ClapTrap clapTrap("ClapTrap");
	ScavTrap scavTrap("ScavTrap");


	clapTrap.attack(scavTrap._name);
	clapTrap.takeDamage(10);
	clapTrap.beRepaired(5);

	scavTrap.attack(clapTrap._name);
	scavTrap.takeDamage(5);
	scavTrap.beRepaired(5);
	scavTrap.guardGate();

	std::cout << "ClapTrap " << clapTrap.getName() << " has "
			<< "\033[32m" << clapTrap.getHitPoints() << "\033[0m hit points, "
			<< "\033[34m" << clapTrap.getEnergyPoints() << "\033[0m energy points, and "
			<< "\033[31m" << clapTrap.getAttackDamage() << "\033[0m attack damage." << std::endl;

	std::cout << "ScavTrap " << scavTrap.getName() << " has "
			<< "\033[32m" << scavTrap.getHitPoints() << "\033[0m hit points, "
			<< "\033[34m" << scavTrap.getEnergyPoints() << "\033[0m energy points, and "
			<< "\033[31m" << scavTrap.getAttackDamage() << "\033[0m attack damage." << std::endl;
	return 0;
}