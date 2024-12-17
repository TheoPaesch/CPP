/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 13:44:30 by tpaesch           #+#    #+#             */
/*   Updated: 2024/12/17 16:50:24 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
# include "ICharacter.hpp"
# include "AMateria.hpp"

class Character : public ICharacter {
private:
	std::string _name;
	AMateria* _Inventory[MAX_MATERIA];
	int _idx;

	void deleteMaterias();

public:
	Character();
	Character(const std::string& name);
	Character(const Character& other);
	~Character();

	Character& operator=(const Character& other);

	Character(std::string _name, int idx, AMateria* m);

	std::string const & getName() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);
};

#endif
