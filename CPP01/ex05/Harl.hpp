/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 21:09:19 by tpaesch           #+#    #+#             */
/*   Updated: 2024/11/23 21:12:12 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>
#include <string>
#include <fstream>

class Harl {
public:
	Harl();
	~Harl();
	void complain(std::string level);

private:
	void complainDebug();
	void complainInfo();
	void complainWarning();
	void complainError();
	void complainFatal();
};

#endif