/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 22:00:22 by tpaesch           #+#    #+#             */
/*   Updated: 2024/12/30 22:50:42 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>

class Bureaucrat;

class Form
{
private:
	Form();

	std::string const _name;
	bool _signed;
	int const _gradeRequiredToSign;
	int const _gradeRequiredToExecute;

public:
	Form(std::string name, int gradeSign, int gradeExec);
	Form(Form const & src);
	~Form();

	Form & operator=(Form const & rhs);

	std::string getName() const;
	bool getSignatureStatus() const;
	int getSignatureGrade() const;

	void beSigned(Bureaucrat & b);

	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};

	class FormIsSignedException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};
};

std::ostream & operator<<(std::ostream & o, Form const & rhs);

#endif