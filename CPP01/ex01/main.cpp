/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 20:16:36 by tpaesch           #+#    #+#             */
/*   Updated: 2024/11/23 17:06:09 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
    //create horde
    Zombie *horde = Zombie::zombieHorde(5, "Zombie");
    for (int i = 0; i < 5; i++)
    {
        horde[i].announce();
    }
    delete[] horde;
    return (0);
}
