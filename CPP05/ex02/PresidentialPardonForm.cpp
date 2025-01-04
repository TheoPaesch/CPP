/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 00:02:12 by tpaesch           #+#    #+#             */
/*   Updated: 2025/01/04 04:29:26 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include "Colors.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), _executed(false), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & src) : AForm(src), _executed(src._executed), _target(src._target) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm const & rhs)
{
	if (this != &rhs)
	{
		this->_executed = rhs._executed;
	}
	return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (executor.getBureaucratGrade() > this->getExecutionGrade())
		throw Bureaucrat::GradeTooLowException();
	else if (!this->getSignatureStatus())
		throw AForm::FormIsSignedException();
	else if (_executed)
		std::cout << RED << "Form has expired" << RESET << std::endl;
	else
	{
		std::cout << GREEN << _target << " has been pardoned by Zafod Beeblebrox" << RESET << std::endl;
		_executed = true;
	}
}
