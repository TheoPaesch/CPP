/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 22:59:46 by tpaesch           #+#    #+#             */
/*   Updated: 2025/01/03 23:00:17 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <string>
# include "Form.hpp"

class Intern
{
public:

	Intern();
	Intern(Intern const & src);
	~Intern();
	Intern & operator=(Intern const & other);

	Form * makeForm(std::string form, std::string target);

	class FormNotFoundException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};

};

#endif