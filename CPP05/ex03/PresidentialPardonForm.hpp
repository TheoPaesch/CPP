/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 00:02:17 by tpaesch           #+#    #+#             */
/*   Updated: 2025/01/04 04:29:16 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
	PresidentialPardonForm();
	mutable bool _executed;
	std::string _target;

public:
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(PresidentialPardonForm const & src);
	~PresidentialPardonForm();

	PresidentialPardonForm & operator=(PresidentialPardonForm const & rhs);
	void execute(Bureaucrat const & executor) const;
};

#endif
