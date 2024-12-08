/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 13:44:30 by tpaesch           #+#    #+#             */
/*   Updated: 2024/12/06 13:45:04 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
# include "ICharacter.hpp"

class Character : public ICharacter {
private:
	std::string _name;
	int _idx;
	AMateria* _m;

public:
	Character();
	Character(const Character& other);
	~Character();

	Character& operator=(const Character& other);
	Character(std::string name);
	Character(std::string name, int idx);
	Character(std::string name, int idx, AMateria* m);

	std::string const & getName() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);
	void setMateria(AMateria* m);
};

#endif
