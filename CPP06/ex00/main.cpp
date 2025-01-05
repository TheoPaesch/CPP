/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 13:33:07 by tpaesch           #+#    #+#             */
/*   Updated: 2025/01/05 13:37:05 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << RED << "Usage: ./convert [value]" << RESET << std::endl;
		return 1;
	}
	ScalarConverter sc(av[1]);
	sc.convert(av[1]);
	return 0;
}