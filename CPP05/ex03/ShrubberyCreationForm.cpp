/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 02:07:32 by tpaesch           #+#    #+#             */
/*   Updated: 2025/01/04 02:32:15 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include "Colors.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _executed(false), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src) : AForm(src), _executed(src._executed), _target(src._target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const & rhs)
{
	if (this != &rhs)
	{
		this->_executed = rhs._executed;
	}
	return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (executor.getBureaucratGrade() > this->getExecutionGrade())
		throw Bureaucrat::GradeTooLowException();
	else if (!this->getSignatureStatus())
		throw AForm::FormIsSignedException();
	else if (_executed)
		std::cout << RED << "Form has expired" << RESET << std::endl;
	else
	{
		std::ofstream file(_target + "_shrubbery");
		if (!file)
			throw std::ios_base::failure("File creation failed");
		if(!file.is_open())
			throw std::ios_base::failure("File opening failed");

		file << "       *       " << std::endl;
		file << "      ***      " << std::endl;
		file << "     *****     " << std::endl;
		file << "    *******    " << std::endl;
		file << "   *********   " << std::endl;
		file << "  ***********  " << std::endl;
		file << " ************* " << std::endl;
		file << "***************" << std::endl;
		file << "      |||      " << std::endl;
		file << "      |||      " << std::endl;
		file.close();
		std::cout << GREEN << "Shrubbery has been created" << RESET << std::endl;
		_executed = true;
	}
}
