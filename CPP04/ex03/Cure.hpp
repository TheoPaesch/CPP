/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 12:49:34 by tpaesch           #+#    #+#             */
/*   Updated: 2024/12/06 13:26:24 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

#include <iostream>
#include "AMateria.hpp"

class Cure : public AMateria {
public:
	Cure();
	Cure(const Cure& other);
	~Cure();

	Cure& operator=(const Cure& other);
	AMateria* clone() const;
	void use(ICharacter& target);
};

#endif