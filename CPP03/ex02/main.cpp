/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 20:21:29 by tpaesch           #+#    #+#             */
/*   Updated: 2024/12/12 15:32:07 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main() {

	ClapTrap clapTrap("ClapTrap");
	ScavTrap scavTrap("ScavTrap");
	FragTrap fragTrap("FragTrap");

	clapTrap.attack(scavTrap.getName());
	clapTrap.takeDamage(10);
	clapTrap.beRepaired(5);

	scavTrap.attack(clapTrap.getName());
	scavTrap.takeDamage(5);
	scavTrap.beRepaired(5);
	scavTrap.guardGate();

	fragTrap.highFivesGuys();

	std::cout << "ClapTrap " << clapTrap.getName() << " has "
			<< "\033[32m" << clapTrap.getHitPoints() << "\033[0m hit points, "
			<< "\033[34m" << clapTrap.getEnergyPoints() << "\033[0m energy points, and "
			<< "\033[31m" << clapTrap.getAttackDamage() << "\033[0m attack damage." << std::endl;

	std::cout << "ScavTrap " << scavTrap.getName() << " has "
			<< "\033[32m" << scavTrap.getHitPoints() << "\033[0m hit points, "
			<< "\033[34m" << scavTrap.getEnergyPoints() << "\033[0m energy points, and "
			<< "\033[31m" << scavTrap.getAttackDamage() << "\033[0m attack damage." << std::endl;

	std::cout << "FragTrap " << fragTrap.getName() << " has "
			<< "\033[32m" << fragTrap.getHitPoints() << "\033[0m hit points, "
			<< "\033[34m" << fragTrap.getEnergyPoints() << "\033[0m energy points, and "
			<< "\033[31m" << fragTrap.getAttackDamage() << "\033[0m attack damage. "
			<< "he didn't do too much here so he's just chillin" << std::endl;

	return 0;

}