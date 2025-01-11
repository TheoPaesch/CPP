/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 15:38:47 by tpaesch           #+#    #+#             */
/*   Updated: 2025/01/11 15:39:31 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#include <iostream>

template <typename T>
T	min(T& prm1, T& prm2) {
	return ((prm1 < prm2) ? prm1 : prm2);
}

template <typename T>
T	max(T& prm1, T& prm2) {
	return ((prm1 > prm2) ? prm1 : prm2);
}

template <typename T>
void	swap(T& prm1, T& prm2) {
	T tmp;

	tmp = prm1;
	prm1 = prm2;
	prm2 = tmp;
}

#endif