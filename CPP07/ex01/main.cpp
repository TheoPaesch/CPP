/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:57:52 by tpaesch           #+#    #+#             */
/*   Updated: 2025/01/14 14:20:41 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include "Colors.hpp"
#include <iostream>

/**
* @brief Demonstrates the usage of the iter template function with various data types.
*
* @return int Exit code.
*/
int main() {
	// Test with an array of integers
	int intArray[] = {1, 2, 3, 4, 5};
	std::cout << BLUE << "Original int array: " << RESET;
	iter(intArray, 5, printElement);
	std::cout << std::endl;

	iter(intArray, 5, incrementElement);
	std::cout << BLUE << "Incremented int array: " << RESET;
	iter(intArray, 5, printElement);
	std::cout << std::endl;

	// Test with an array of doubles
	double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
	std::cout << BLUE << "Original double array: " << RESET;
	iter(doubleArray, 5, printElement);
	std::cout << std::endl;

	iter(doubleArray, 5, incrementElement);
	std::cout << BLUE << "Incremented double array: " << RESET;
	iter(doubleArray, 5, printElement);
	std::cout << std::endl;

	// Test with an array of strings
	std::string stringArray[] = {"Hello", "world", "this", "is", "C++"};
	std::cout << BLUE << "Original string array: " << RESET;
	iter(stringArray, 5, printElement);
	std::cout << std::endl;

	return 0;
}
