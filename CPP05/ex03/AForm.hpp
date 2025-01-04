/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 22:00:22 by tpaesch           #+#    #+#             */
/*   Updated: 2025/01/04 00:29:56 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>

class Bureaucrat;

class AForm
{
private:
	AForm();

	std::string const _name;
	bool _signed;
	int const _gradeRequiredToSign;
	int const _gradeRequiredToExecute;

public:
	AForm(std::string name, int gradeRequiredToSign, int gradeRequiredToExecute);
	AForm(AForm const & src);
	virtual ~AForm();

	AForm & operator=(AForm const & rhs);

	std::string getName() const;
	bool getSignatureStatus() const;
	int getExecutionGrade() const;
	int getSignatureGrade() const;

	void beSigned(class Bureaucrat& b);

	virtual void execute(Bureaucrat const & executor) const = 0;
	
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

std::ostream & operator<<(std::ostream & o, AForm const & rhs);

#endif