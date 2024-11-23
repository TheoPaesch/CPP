/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 21:09:05 by tpaesch           #+#    #+#             */
/*   Updated: 2024/11/23 21:13:02 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {
}

Harl::~Harl() {
}

void Harl::complain(std::string level) {
	if (level == "DEBUG")
		complainDebug();
	else if (level == "INFO")
		complainInfo();
	else if (level == "WARNING")
		complainWarning();
	else if (level == "ERROR")
		complainError();
	else if (level == "FATAL")
		complainFatal();
}

void Harl::complainDebug() {
	std::cout << "DEBUG: This is a debug message." << std::endl;
}

void Harl::complainInfo() {
	std::cout << "INFO: This is an info message." << std::endl;
}

void Harl::complainWarning() {
	std::cout << "WARNING: This is a warning message." << std::endl;
}

void Harl::complainError() {
	std::cout << "ERROR: This is an error message." << std::endl;
}

void Harl::complainFatal() {
	std::cout << "FATAL: This is a fatal message." << std::endl;
}

