/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 12:50:03 by tpaesch           #+#    #+#             */
/*   Updated: 2024/12/06 12:50:29 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

#include <iostream>
#include "AMateria.hpp"

class Ice : public AMateria {
public:
	Ice();
	Ice(const Ice& other);
	~Ice();

	Ice& operator=(const Ice& other);
	AMateria* clone() const;
	void use(ICharacter& target);
};

#endif