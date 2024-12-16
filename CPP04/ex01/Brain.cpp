/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 20:48:36 by tpaesch           #+#    #+#             */
/*   Updated: 2024/12/15 21:54:42 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include "Colors.hpp"

Brain::Brain() {
	std::cout << BRIGHT_WHITE << "Brain default constructor" << RESET << std::endl;
}

Brain::Brain(const Brain& other) {
	std::cout << BRIGHT_WHITE << "Brain copy constructor" << RESET << std::endl;
	*this = other;
}

Brain::~Brain() {
	std::cout << BRIGHT_WHITE << "Brain destructor" << RESET << std::endl;
}

Brain& Brain::operator=(const Brain& other) {
	std::cout << BRIGHT_WHITE << "Brain assignation operator" << RESET << std::endl;
	if (this != &other) {
		for (int i = 0; i < 100; i++) {
			ideas[i] = other.ideas[i];
		}
	}
	return *this;
}
