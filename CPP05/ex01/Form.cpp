/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 21:58:05 by tpaesch           #+#    #+#             */
/*   Updated: 2025/01/03 22:14:26 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("default"), _signed(false), _gradeRequiredToSign(150), _gradeRequiredToExecute(150) {}

Form::Form(std::string name, int gradeRequiredToSign, int gradeRequiredToExecute) : _name(name), _signed(false), _gradeRequiredToSign(gradeRequiredToSign), _gradeRequiredToExecute(gradeRequiredToExecute)
{
	if (gradeRequiredToSign < 1 || gradeRequiredToExecute < 1)
		throw Form::GradeTooHighException();
	else if (gradeRequiredToSign > 150 || gradeRequiredToExecute > 150)
		throw Form::GradeTooLowException();
}

Form::Form(Form const & src) : _name(src._name), _signed(src._signed), _gradeRequiredToSign(src._gradeRequiredToSign), _gradeRequiredToExecute(src._gradeRequiredToExecute) {}

Form::~Form() {}

Form & Form::operator=(Form const & rhs)
{
	if (this != &rhs)
	{
		this->_signed = rhs._signed;
	}
	return *this;
}

std::string Form::getName() const
{
	return this->_name;
}

bool Form::getSignatureStatus() const
{
	return this->_signed;
}

int Form::getExecutionGrade() const
{
	return this->_gradeRequiredToExecute;
}

int Form::getSignatureGrade() const
{
	return this->_gradeRequiredToSign;
}

void Form::beSigned(Bureaucrat & b)
{
	if (b.getBureaucratGrade() > this->_gradeRequiredToSign)
		throw Form::GradeTooLowException();
	else if (this->_signed == true)
		throw Form::FormIsSignedException();
	else
		this->_signed = true;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}

const char* Form::FormIsSignedException::what() const throw()
{
	return "Form is already signed";
}

std::ostream & operator<<(std::ostream & o, Form const & rhs)
{
	o << "Form " << rhs.getName() << " is ";
	if (rhs.getSignatureStatus() == false)
		o << "not ";
	o << "signed";
	return o;
}

