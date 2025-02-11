/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 17:21:02 by tpaesch           #+#    #+#             */
/*   Updated: 2025/02/11 13:39:00 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <iomanip>
#include <cmath>

class RPN {
public:
	RPN();
	~RPN();

	bool processInput(const std::string& input);

private:
	std::stack<double> stack_;

	bool processToken(const std::string& token);
	void printError(const std::string& msg);

};

#endif
