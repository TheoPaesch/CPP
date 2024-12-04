/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 20:21:29 by tpaesch           #+#    #+#             */
/*   Updated: 2024/12/04 17:37:19 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main() {

	ClapTrap clapTrap("ClapTrap");
	ScavTrap scavTrap("ScavTrap");
	FragTrap fragTrap("FragTrap");


	clapTrap.attack(scavTrap._name);
	clapTrap.takeDamage(10);
	clapTrap.beRepaired(5);

	scavTrap.attack(clapTrap._name);
	scavTrap.takeDamage(5);
	scavTrap.beRepaired(5);
	scavTrap.guardGate();

	fragTrap.highFivesGuys();

	std::cout << "ClapTrap " << clapTrap._name << " has "
			<< clapTrap.getHitPoints() << " hit points, "
			<< clapTrap.getEnergyPoints() << " energy points, and "
			<< clapTrap.getAttackDamage() << " attack damage." << std::endl;

	std::cout << "ScavTrap " << scavTrap.getName() << " has "
			<< scavTrap.getHitPoints() << " hit points, "
			<< scavTrap.getEnergyPoints() << " energy points, and "
			<< scavTrap.getAttackDamage() << " attack damage." << std::endl;

	std::cout << "FragTrap " << fragTrap.getName() << " has "
			<< fragTrap.getHitPoints() << " hit points, "
			<< fragTrap.getEnergyPoints() << " energy points, and "
			<< fragTrap.getAttackDamage() << " attack damage." 
			<< "he didn't do too much here so he's just chillin" << std::endl;
	return 0;
}