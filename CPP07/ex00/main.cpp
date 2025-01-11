/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 15:39:39 by tpaesch           #+#    #+#             */
/*   Updated: 2025/01/11 15:41:16 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"
#include "Colors.hpp"

int main() {
	int a = 2;
	int b = 3;

	std::cout << BRIGHT_GREEN << "a = " << a << ", b = " << b << RESET << std::endl;
	swap(a, b);
	std::cout << BRIGHT_GREEN << "a = " << a << ", b = " << b << RESET << std::endl;
	std::cout << BRIGHT_BLUE << "min(a, b) = " << min(a, b) << RESET << std::endl;
	std::cout << BRIGHT_BLUE << "max(a, b) = " << max(a, b) << RESET << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";

	std::cout << BRIGHT_GREEN << "c = " << c << ", d = " << d << RESET << std::endl;
	swap(c, d);
	std::cout << BRIGHT_GREEN << "c = " << c << ", d = " << d << RESET << std::endl;
	std::cout << BRIGHT_BLUE << "min(c, d) = " << min(c, d) << RESET << std::endl;
	std::cout << BRIGHT_BLUE << "max(c, d) = " << max(c, d) << RESET << std::endl;

	return 0;
}
