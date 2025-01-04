/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 01:54:24 by tpaesch           #+#    #+#             */
/*   Updated: 2025/01/04 02:03:33 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include "Colors.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _executed(false), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & src) : AForm(src), _executed(src._executed), _target(src._target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm const & other)
{
	if (this != &rhs)
	{
		this->_target = other._target;
	}
	return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (executor.getBureaucratGrade() > this->getExecutionGrade())
		throw Bureaucrat::GradeTooLowException();
	else if (!this->getSignatureStatus())
		throw AForm::FormIsSignedException();
	else if (_executed)
		std::cout << RED << "Form has expired." << RESET << std::endl;
	else
	{
		std::cout << BLUE << "Drilling noises" << RESET << std::endl;
		if (rand() % 2)
			std::cout << GREEN << _target << " has been robotomized" << RESET << std::endl;
		else
			std::cout << RED << _target << " robotomization failed" << RESET << std::endl;
		_executed = true;
	}
}
