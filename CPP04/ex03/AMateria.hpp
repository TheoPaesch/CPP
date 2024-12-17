/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 12:36:02 by tpaesch           #+#    #+#             */
/*   Updated: 2024/12/17 16:53:31 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <iostream>
#include "ICharacter.hpp"

#define MAX_MATERIA 4

class ICharacter;

class AMateria
{
protected:
	std::string _type;

public:
	AMateria(std::string const & type);
	AMateria(const AMateria& other);
	virtual ~AMateria();

	AMateria& operator=(const AMateria& other);
	std::string const & getType() const;
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
};


#endif