/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 06:46:25 by tpaesch           #+#    #+#             */
/*   Updated: 2025/01/04 06:50:43 by tpaesch          ###   ########.fr       */
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

Form * Intern::makeForm(std::string form, std::string target)
{
	std::string forms[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};
	for(int i = 0; i < 3; i++)
	{
		if (form.compare(forms[i]) == 0)
		{
			if (i == 0)
				return new PresidentialPardonForm(target);
			else if (i == 1)
				return new RobotomyRequestForm(target);
			else if (i == 2)
				return new ShrubberyCreationForm(target);
		}
	}
	throw Intern::FormNotFoundException();
	return NULL;
}

const char* Intern::FormNotFoundException::what() const throw()
{
	return "Form not found";
}

