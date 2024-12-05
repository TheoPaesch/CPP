/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 17:32:13 by tpaesch           #+#    #+#             */
/*   Updated: 2024/12/05 17:51:25 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class Brain {
protected:
	std::string _ideas[100];
public:
	Brain();
	Brain(const Brain& other);
	~Brain();

	Brain& operator=(const Brain& other);
};

#endif