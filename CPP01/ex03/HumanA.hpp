/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 20:11:22 by tpaesch           #+#    #+#             */
/*   Updated: 2024/11/23 20:11:55 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

class HumanA {
public:
	HumanA(std::string name, Weapon &weapon);
	~HumanA();
	void	attack();
	void	setWeapon(Weapon &weapon);
	std::string	getName();
	Weapon	&getWeapon();

private:
	std::string	_name;
	Weapon		&_weapon;
};

#endif