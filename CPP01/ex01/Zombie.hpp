/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 20:17:56 by tpaesch           #+#    #+#             */
/*   Updated: 2024/11/23 17:30:24 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie {
public:
	Zombie(std::string name);
	Zombie();
	~Zombie();
	void	announce();
	void	setName(std::string name) { this->_name = name; }
	static Zombie*	zombieHorde(int N, std::string name);

private:
	std::string	_name;
};

#endif