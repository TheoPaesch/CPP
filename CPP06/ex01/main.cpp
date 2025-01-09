/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 18:36:17 by tpaesch           #+#    #+#             */
/*   Updated: 2025/01/09 19:05:46 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Colors.hpp"

int main()
{
	std::cout << BLUE << "[TEST] Creating Data object" << RESET << std::endl;
	Data* original = new Data();
	original->present = 42;
	original->str = "Hello, Serialize!";

	std::cout << GREEN << "Original Address: " << RESET << original << std::endl;
	std::cout << YELLOW << "[INFO] original.present = " << original->present
			<< ", original.str = " << original->str << RESET << std::endl;

	std::cout << BLUE << "[TEST] Serializing Data object" << RESET << std::endl;
	uintptr_t raw = Serializer::serialize(original);

	std::cout << BLUE << "[TEST] Deserializing to new pointer" << RESET << std::endl;
	Data* clone = Serializer::deserialize(raw);

	std::cout << GREEN << "Clone Address   : " << RESET << clone << std::endl;
	std::cout << YELLOW << "[INFO] clone.present = " << clone->present
			<< ", clone.str = " << clone->str << RESET << std::endl;

	if (original == clone)
		std::cout << GREEN << "[OK] Deserialized pointer matches original" << RESET << std::endl;
	else
		std::cout << RED << "[FAIL] Addresses differ" << RESET << std::endl;

	std::cout << BLUE << "[TEST] Cleaning up" << RESET << std::endl;
	delete original;  // Same pointer as clone

	return 0;
}