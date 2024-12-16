/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 17:36:14 by tpaesch           #+#    #+#             */
/*   Updated: 2024/12/16 02:38:26 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Animal {
protected:
	std::string _type;

public:
	Animal();
	Animal(std::string type);
	Animal(const Animal& other);
	virtual ~Animal();

	Animal& operator=(const Animal& other);
	std::string getType() const;
	virtual void makeSound() const = 0; // Pure virtual function
};

#endif