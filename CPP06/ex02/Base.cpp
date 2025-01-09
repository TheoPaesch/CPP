/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 19:43:01 by tpaesch           #+#    #+#             */
/*   Updated: 2025/01/09 19:52:01 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "Colors.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>  // for rand


Base* generate() {
	int randValue = rand() % 3;
	if (randValue == 0)
		return new A();
	else if (randValue == 1)
		return new B();
	else
		return new C();
}

void identify(Base* p) {
	if (dynamic_cast<A*>(p))
		std::cout << GREEN << "A" << RESET << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << GREEN << "B" << RESET << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << GREEN << "C" << RESET << std::endl;
}

void identify(Base& p) {
	try {
		A& a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << GREEN << "A" << RESET << std::endl;
	} catch (std::bad_cast &bc) {
		try {
			B& b = dynamic_cast<B&>(p);
			(void)b;
			std::cout << GREEN << "B" << RESET << std::endl;
		} catch (std::bad_cast &bc) {
			try {
				C& c = dynamic_cast<C&>(p);
				(void)c;
				std::cout << GREEN << "C" << RESET << std::endl;
			} catch (std::bad_cast &bc) {
				std::cout << RED << "Unknown" << RESET << std::endl;
			}
		}
	}
}