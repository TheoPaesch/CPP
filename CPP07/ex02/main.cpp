/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 17:16:15 by tpaesch           #+#    #+#             */
/*   Updated: 2025/01/13 17:29:30 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"
#include "Colors.hpp"

/**
* @struct Data
* @brief Example struct to demonstrate arrays of user-defined types.
*/
struct Data {
bool is_useless;
int present;
long sandwich;
std::string str;
};

int main() {
std::cout << BRIGHT_BLUE << "=== Array of int ===" << RESET << std::endl;
Array<int> array_int(5);
for (unsigned int i = 0; i < array_int.size(); i++) {
	array_int[i] = static_cast<int>(i * 10);
}
for (unsigned int i = 0; i < array_int.size(); i++) {
	std::cout << "array_int[" << i << "] = " << array_int[i] << "  ";
}
std::cout << std::endl << std::endl;

std::cout << BRIGHT_BLUE << "=== Array of std::string ===" << RESET << std::endl;
Array<std::string> array_str(3);
array_str[0] = "Hello";
array_str[1] = "Array";
array_str[2] = "World";
for (unsigned int i = 0; i < array_str.size(); i++) {
	std::cout << "array_str[" << i << "] = " << array_str[i] << "  ";
}
std::cout << std::endl << std::endl;

std::cout << BRIGHT_BLUE << "=== Array of Data ===" << RESET << std::endl;
Array<Data> array_data(3);
for (unsigned int i = 0; i < array_data.size(); i++) {
	array_data[i].is_useless = (i % 2 == 0);
	array_data[i].present = static_cast<int>(i);
	array_data[i].sandwich = i * 100;
	array_data[i].str = std::string("Data #") + std::to_string(i);
}
for (unsigned int i = 0; i < array_data.size(); i++) {
	std::cout << "array_data[" << i << "]: "
			<< "is_useless=" << array_data[i].is_useless << ", "
			<< "present=" << array_data[i].present << ", "
			<< "sandwich=" << array_data[i].sandwich << ", "
			<< "str=" << array_data[i].str << std::endl;
}
std::cout << std::endl;

std::cout << BRIGHT_BLUE << "=== Testing Copy Constructor ===" << RESET << std::endl;
Array<int> copy_int(array_int);
copy_int[0] = 999;
std::cout << "copy_int[0] = " << copy_int[0]
			<< ", array_int[0] = " << array_int[0] << std::endl << std::endl;

std::cout << BRIGHT_BLUE << "=== Testing Assignment Operator ===" << RESET << std::endl;
Array<std::string> copy_str;
copy_str = array_str;  // Assign
copy_str[0] = "Changed";
std::cout << "copy_str[0] = " << copy_str[0]
			<< ", array_str[0] = " << array_str[0] << std::endl << std::endl;

std::cout << BRIGHT_BLUE << "=== Testing Exception Throw ===" << RESET << std::endl;
try {
	std::cout << "array_int[100] = " << array_int[100] << std::endl;
} catch (const std::exception &e) {
	std::cout << BRIGHT_RED << "[Exception Caught]: " << e.what() << RESET << std::endl;
}

return 0;
}
