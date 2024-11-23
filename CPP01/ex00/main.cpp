/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 19:20:45 by tpaesch           #+#    #+#             */
/*   Updated: 2024/11/16 20:21:25 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main() {
	Zombie	*zombie1 = newZombie("Zombie1");
	Zombie	*zombie2 = newZombie("Zombie2");

	Zombie first("stack Zombie");
	Zombie *second = newZombie("Heap Zombie");

	zombie1->announce();
	zombie2->announce();
	delete zombie1;
	delete zombie2;

	first.announce();
	second->announce();
	delete second;
	return (0);
}