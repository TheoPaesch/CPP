/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 22:00:22 by tpaesch           #+#    #+#             */
/*   Updated: 2025/01/03 22:24:14 by tpaesch          ###   ########.fr       */
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
	Form(std::string name, int gradeRequiredToSign, int gradeRequiredToExecute);
	Form(Form const & src);
	~Form();

	Form & operator=(Form const & rhs);

	std::string getName() const;
	bool getSignatureStatus() const;
	int getExecutionGrade() const;
	int getSignatureGrade() const;

	void beSigned(class Bureaucrat& b);

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