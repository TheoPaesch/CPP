/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 20:10:47 by tpaesch           #+#    #+#             */
/*   Updated: 2024/11/23 20:11:20 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _weapon(weapon) {
}

HumanA::~HumanA() {
}

void	HumanA::attack() {
	std::cout << this->_name << " attacks with his " << this->_weapon.getType() << std::endl;
}

void	HumanA::setWeapon(Weapon &weapon) {
	this->_weapon = weapon;
}

std::string	HumanA::getName() {
	return this->_name;
}

Weapon	&HumanA::getWeapon() {
	return this->_weapon;
}

