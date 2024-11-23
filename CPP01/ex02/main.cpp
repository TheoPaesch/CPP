/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 19:56:54 by tpaesch           #+#    #+#             */
/*   Updated: 2024/11/23 20:00:29 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string *ptr = &str;
	std::string &ref = str;

	std::cout << "Address of string: " << &str << std::endl;
	std::cout << "Address of pointer: " << ptr << std::endl;
	std::cout << "Address of reference: " << &ref << std::endl;
	
	std::cout << "Value String: " << str << std::endl;
	std::cout << "Value Pointer: " << *ptr << std::endl;
	std::cout << "Value Reference: " << ref << std::endl;
	return (0);
}
