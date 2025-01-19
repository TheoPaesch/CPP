/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 13:40:30 by tpaesch           #+#    #+#             */
/*   Updated: 2025/01/19 16:52:00 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_TPP
#define EASYFIND_TPP

#include "easyfind.hpp"

/**
* @brief Implementation of the easyfind function template.
*
* Searches for the first occurrence of `value` in the `container`. Utilizes
* the `std::find` algorithm to perform the search. If the value is not found,
* throws a `NotFoundException`.
*
* @tparam T The type of the container.
* @param container The container to search within.
* @param value The integer value to search for.
* @return typename T::iterator An iterator pointing to the found element.
* @throws NotFoundException If `value` is not present in `container`.
*/
template <typename T>
typename T::iterator easyfind(T& container, int value) {
	typename T::iterator it = std::find(container.begin(), container.end(), value);
	if (it == container.end()) {
		throw NotFoundException();
	}
	return it;
}

#endif // EASYFIND_TPP