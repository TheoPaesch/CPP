/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 21:58:05 by tpaesch           #+#    #+#             */
/*   Updated: 2025/01/03 20:31:52 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("default"), _signed(false), _gradeSign(150), _gradeExec(150) {}

Form::Form(std::string name, int gradeSign, int gradeExec) : _name(name), _signed(false), _gradeSign(gradeSign), _gradeExec(gradeExec)
{
	if (gradeSign < 1 || gradeExec < 1)
		throw Form::GradeTooHighException();
	else if (gradeSign > 150 || gradeExec > 150)
		throw Form::GradeTooLowException();
}

Form::Form(Form const & src) : _name(src._name), _signed(src._signed), _gradeSign(src._gradeSign), _gradeExec(src._gradeExec) {}

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


int Form::getSignatureGrade() const
{
	return this->_gradeSign;
}


void Form::beSigned(Bureaucrat & b)
{
	if (b.getGrade() > this->_gradeSign)
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

