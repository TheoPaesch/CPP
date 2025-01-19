/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 14:58:49 by tpaesch           #+#    #+#             */
/*   Updated: 2025/01/19 16:52:16 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <algorithm>  // for std::find
#include <exception>  // for std::exception
#include <iterator>   // for std::distance
#include <vector>     // for std::vector
#include "Colors.hpp" // For color output

/**
 * @class NotFoundException
* @brief Exception class thrown when a value is not found in the container.
*
* Inherits from std::exception to provide a descriptive error message.
*/
class NotFoundException : public std::exception {
public:
	/**
	* @brief Provides an explanatory string.
	* @return C-style string describing the exception.
	*/
	virtual const char* what() const noexcept override {
		return "404 Value was not found";
	}
};

/**
* @brief Finds the first occurrence of a specified integer in a container.
*
* This function template searches for the first occurrence of the integer `value`
* within the container `container`. If the value is found, an iterator to the
* element is returned. If the value is not found, a `NotFoundException` is thrown.
*
* @tparam T The type of the container (e.g., std::vector<int>, std::list<int>, etc.).
* @param container The container in which to search for the value.
* @param value The integer value to find within the container.
* @return typename T::iterator An iterator pointing to the first occurrence of `value`.
* @throws NotFoundException If `value` is not found in `container`.
*
* @note This function assumes that the container `T` holds elements of type `int`.
*/
template <typename T>
typename T::iterator easyfind(T& container, int value);

/**
* Include the template implementation.
* This ensures that the template definitions are available wherever easyfind.hpp is included.
 */
#include "easyfind.tpp"