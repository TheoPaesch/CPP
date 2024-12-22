/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 17:35:54 by tpaesch           #+#    #+#             */
/*   Updated: 2024/12/21 17:52:02 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Colors.hpp"

int main()
{
	try
	{
		Bureaucrat b("Bomboclat", 1);
		std::cout << BRIGHT_GREEN << b;
		b.incrementGrade();
		std::cout << BRIGHT_GREEN << b;
		b.incrementGrade();
		std::cout << BRIGHT_GREEN << b;
		b.incrementGrade();
		std::cout << BRIGHT_GREEN << b;
		b.incrementGrade();
		std::cout << BRIGHT_GREEN << b;
		b.incrementGrade();
		std::cout << BRIGHT_GREEN << b;
	}
	catch (std::exception & e)
	{
		std::cout << BRIGHT_RED << e.what() << std::endl;
	}
	try
	{
		Bureaucrat b("bloodclat", 150);
		std::cout << BRIGHT_GREEN << b;
		b.decrementGrade();
		std::cout << BRIGHT_GREEN << b;
		b.decrementGrade();
		std::cout << BRIGHT_GREEN << b;
		b.decrementGrade();
		std::cout << BRIGHT_GREEN << b;
		b.decrementGrade();
		std::cout << BRIGHT_GREEN << b;
		b.decrementGrade();
		std::cout << BRIGHT_GREEN << b;
	}
	catch (std::exception & e)
	{
		std::cout << BRIGHT_RED << e.what() << std::endl;
	}
	return 0;
}

