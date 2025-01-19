/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 13:38:58 by tpaesch           #+#    #+#             */
/*   Updated: 2025/01/19 16:51:34 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "easyfind.hpp"

/**
* @brief Entry point of the program.
*
* Demonstrates the usage of the `easyfind` function template with a `std::vector<int>`.
* Attempts to find both existing and non-existing values within the vector, handling
* exceptions appropriately and displaying results with colored output.
*
* @return int Exit status code.
*/
int main()
{
	// Initialize a vector of integers
	std::vector<int> v = {1, 2, 3, 4, 5};

	// Attempt to find the value 3 in the vector
	try
	{
		int value = 3;
		std::cout << GREEN << "Trying to find " << value << " in the vector..." << RESET << std::endl;
		std::vector<int>::iterator it = easyfind(v, value);
		std::cout << GREEN << "Value found: " << RESET << *it << " at position "
				<< std::distance(v.begin(), it) << "." << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << RED << "Error: " << e.what() << RESET << std::endl;
	}

	// Attempt to find the value 42 in the vector (which does not exist)
	try
	{
		int value = 42;
		std::cout << GREEN << "Trying to find " << value << " in the vector..." << RESET << std::endl;
		std::vector<int>::iterator it = easyfind(v, value);
		std::cout << GREEN << "Value found: " << RESET << *it << " at position "
				<< std::distance(v.begin(), it) << "." << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << RED << "Error: " << e.what() << RESET << std::endl;
	}

	return 0;
}