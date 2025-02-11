/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 17:20:45 by tpaesch           #+#    #+#             */
/*   Updated: 2025/02/11 13:38:37 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include "Colors.hpp"

RPN::RPN() {}
RPN::~RPN() {}

bool RPN::processInput(const std::string& input) {
	std::istringstream iss(input);
	std::string token;
	while (iss >> token) {
		if (!processToken(token))
			return false; // Error occurred, stop execution
	}
	if (stack_.size() != 1) {
		printError("Final stack size is not 1.");
		return false;
	}
	std::cout << GREEN << stack_.top() << RESET << std::endl;
	return true;
}

bool RPN::processToken(const std::string& token) {
	// Operators
	if (token == "+" || token == "-" || token == "*" || token == "/") {
		if (stack_.size() < 2) {
			printError("Insufficient operands for operator '" + token + "'");
			return false;
		}
		double b = stack_.top(); stack_.pop();
		double a = stack_.top(); stack_.pop();
		if (token == "/" && b == 0) {
			printError("Division by zero");
			return false;
		}
		double res = 0;
		if      (token == "+") res = a + b;
		else if (token == "-") res = a - b;
		else if (token == "*") res = a * b;
		else if (token == "/") res = a / b;
		stack_.push(res);
	}
	// Single-digit number
	else {
		if (token.size() == 1 && std::isdigit(token[0])) {
			stack_.push(token[0] - '0');
		} else {
			printError("Invalid token '" + token + "'");
			return false;
		}
	}
	return true;
}

void RPN::printError(const std::string& msg) {
	std::cerr << RED << "Error: " << msg << RESET << std::endl;
}