/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 16:52:38 by tpaesch           #+#    #+#             */
/*   Updated: 2024/12/17 16:52:40 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include <iostream>
# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
private:
	AMateria* _m[MAX_MATERIA];

	void deleteMaterias();

public:
	MateriaSource();
	MateriaSource(const MateriaSource& other);
	virtual ~MateriaSource();

	MateriaSource& operator=(const MateriaSource& other);

	virtual void learnMateria(AMateria* m);
	virtual AMateria* createMateria(std::string const & type);
	
};

#endif