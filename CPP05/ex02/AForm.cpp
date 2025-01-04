/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 21:58:05 by tpaesch           #+#    #+#             */
/*   Updated: 2025/01/04 04:58:10 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("default"), _signed(false), _gradeRequiredToSign(150), _gradeRequiredToExecute(150) {}

AForm::AForm(std::string name, int gradeRequiredToSign, int gradeRequiredToExecute) : _name(name), _signed(false), _gradeRequiredToSign(gradeRequiredToSign), _gradeRequiredToExecute(gradeRequiredToExecute)
{
	if (gradeRequiredToSign < 1 || gradeRequiredToExecute < 1)
		throw AForm::GradeTooHighException();
	else if (gradeRequiredToSign > 150 || gradeRequiredToExecute > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(AForm const & src) : _name(src._name), _signed(src._signed), _gradeRequiredToSign(src._gradeRequiredToSign), _gradeRequiredToExecute(src._gradeRequiredToExecute) {}

AForm::~AForm() {}

AForm & AForm::operator=(AForm const & rhs)
{
	if (this != &rhs)
	{
		this->_signed = rhs._signed;
	}
	return *this;
}

std::string AForm::getName() const
{
	return this->_name;
}

bool AForm::getSignatureStatus() const
{
	return this->_signed;
}

int AForm::getExecutionGrade() const
{
	return this->_gradeRequiredToExecute;
}

int AForm::getSignatureGrade() const
{
	return this->_gradeRequiredToSign;
}

void AForm::beSigned(Bureaucrat & b)
{
	if (b.getBureaucratGrade() > this->_gradeRequiredToSign)
		throw AForm::GradeTooLowException();
	else if (this->_signed == true)
		throw AForm::FormIsSignedException();
	else
		this->_signed = true;
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}

const char* AForm::FormIsSignedException::what() const throw()
{
	return "Form is already signed";
}

std::ostream & operator<<(std::ostream & ostr, AForm const & rhs)
{
	ostr << "Form " << rhs.getName() << " is ";
	if (rhs.getSignatureStatus() == false)
		ostr << "not ";
	ostr << "signed";
	return ostr;
}
