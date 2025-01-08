/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 13:33:07 by tpaesch           #+#    #+#             */
/*   Updated: 2025/01/07 16:48:04 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include "Colors.hpp"

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