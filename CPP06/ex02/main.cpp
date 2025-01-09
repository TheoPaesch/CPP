/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 19:47:43 by tpaesch           #+#    #+#             */
/*   Updated: 2025/01/09 19:51:15 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "Colors.hpp"
#include <cstdlib>  // for srand, rand
#include <ctime>    // for time

int main()
{
	srand(static_cast<unsigned>(time(NULL)));

	// Single test
	std::cout << BLUE << "[TEST] Single object" << RESET << std::endl;
	Base* base = generate();
	std::cout << YELLOW << "Identifying by pointer: " << RESET;
	identify(base);
	std::cout << YELLOW << "Identifying by reference: " << RESET;
	identify(*base);
	delete base;

	// Multiple tests in a loop
	std::cout << BLUE << "[TEST] Multiple objects" << RESET << std::endl;
	for (int i = 0; i < 5; ++i) {
		Base* temp = generate();
		std::cout << YELLOW << "Identifying by pointer: " << RESET;
		identify(temp);
		std::cout << YELLOW << "Identifying by reference: " << RESET;
		identify(*temp);
		delete temp;
	}
	return 0;
}
