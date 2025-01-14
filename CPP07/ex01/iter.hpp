/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:57:52 by tpaesch           #+#    #+#             */
/*   Updated: 2025/01/14 14:20:18 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

/**
* @brief Prints the provided element to standard output followed by a space.
*
* @tparam T Type of element.
* @param element Element to print.
*/
template <typename T>
void printElement(const T &element) {
	std::cout << element << " ";
}

/**
* @brief Increments the provided element by one.
*
* @tparam T Type of element.
* @param element Element to increment.
*/
template <typename T>
void incrementElement(T &element) {
	++element;
}

/**
* @brief Calls a function on every element of a non-const array.
*
* @tparam T Type of the array elements.
* @param array Pointer to a non-const array of T.
* @param size Number of elements in the array.
* @param f Function pointer that accepts a non-const reference to T.
*/
template <typename T>
void iter(T* array, size_t size, void (*f)(T &)) {
	for (size_t i = 0; i < size; ++i) {
		f(array[i]);
	}
}

/**
* @brief Calls a function on every element of a const array.
*
* @tparam T Type of the array elements.
* @param array Pointer to a const array of T.
* @param size Number of elements in the array.
* @param f Function pointer that accepts a const reference to T.
*/
template <typename T>
void iter(const T* array, size_t size, void (*f)(const T &)) {
	for (size_t i = 0; i < size; ++i) {
		f(array[i]);
	}
}

#endif // ITER_HPP