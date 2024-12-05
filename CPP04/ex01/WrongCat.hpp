/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 17:39:21 by tpaesch           #+#    #+#             */
/*   Updated: 2024/12/05 17:46:48 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include <iostream>
#include "WrongAnimal.hpp"


class WrongCat : public WrongAnimal {
protected:
	std::string _type;

public:
	WrongCat();
	WrongCat(std::string type);
	WrongCat(const WrongCat& other);
	virtual ~WrongCat();

	WrongCat& operator=(const WrongCat& other);
	std::string getType() const;
	void virtual makeSound() const;
};

#endif