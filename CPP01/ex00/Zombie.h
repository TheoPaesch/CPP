/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 19:21:38 by tpaesch           #+#    #+#             */
/*   Updated: 2024/11/16 19:22:32 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

class Zombie {
public:
	Zombie(std::string name);
	~Zombie();
	void	announce();

private:
	std::string	_name;
};

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);
