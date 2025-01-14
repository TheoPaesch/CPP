/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 15:38:47 by tpaesch           #+#    #+#             */
/*   Updated: 2025/01/14 14:24:21 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#include <iostream>

/**
* @brief Returns the minimum of two values.
*
* @tparam T The type of the parameters.
* @param prm1 First value.
* @param prm2 Second value.
* @return The smaller of prm1 and prm2.
*/
template <typename T>
T min(T& prm1, T& prm2) {
	return ((prm1 < prm2) ? prm1 : prm2);
}

/**
* @brief Returns the maximum of two values.
*
* @tparam T The type of the parameters.
* @param prm1 First value.
* @param prm2 Second value.
* @return The larger of prm1 and prm2.
*/
template <typename T>
T max(T& prm1, T& prm2) {
	return ((prm1 > prm2) ? prm1 : prm2);
}

/**
* @brief Swaps the values of prm1 and prm2.
*
* @tparam T The type of the parameters to swap.
* @param prm1 First value, becomes second.
* @param prm2 Second value, becomes first.
*/
template <typename T>
void swap(T& prm1, T& prm2) {
	T tmp = prm1;
	prm1 = prm2;
	prm2 = tmp;
}

#endif