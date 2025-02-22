/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 15:58:49 by tpaesch           #+#    #+#             */
/*   Updated: 2025/02/11 13:13:33 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include "Colors.hpp"

int main(int argc, char* argv[]) {
	if (argc != 2) {
		std::cerr << RED << "Error: invalid arguments" << RESET << std::endl;
		return 1;
	}

	RPN rpn;
	rpn.processInput(argv[1]);
	return 0;
}