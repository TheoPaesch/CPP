/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 06:46:25 by tpaesch           #+#    #+#             */
/*   Updated: 2025/01/05 15:43:56 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(Intern const & src)
{
	*this = src;
}

Intern::~Intern() {}

Intern & Intern::operator=(Intern const & rhs)
{
	if (this != &rhs)
	{
	}
	return *this;
}

AForm * Intern::makeForm(std::string form, std::string target)
{
	std::string forms[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};
	for(int i = 0; i < 3; i++)
		if (form.compare(forms[i]) == 0)
			break;
	switch (i)
	{
		case 0:
			return new PresidentialPardonForm(target);
		case 1:
			return new RobotomyRequestForm(target);
		case 2:
			return new ShrubberyCreationForm(target);
		default:
		{
			throw Intern::FormNotFoundException();
			return NULL;
		}
	}
}

const char* Intern::FormNotFoundException::what() const throw()
{
	return "Form not found";
}

