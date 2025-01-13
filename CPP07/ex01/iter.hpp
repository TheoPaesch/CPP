/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:56:52 by tpaesch           #+#    #+#             */
/*   Updated: 2025/01/13 15:20:03 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

// Function to print an element
template <typename T>
void printElement(const T &element) {
	std::cout << element << " ";
}

// Function to increment an element
template <typename T>
void incrementElement(T &element) {
	++element;
}

// Non-const version of iter for functions that modify elements
template <typename T>
void iter(T* array, size_t size, void (*f)(T &)) {
	for (size_t i = 0; i < size; ++i)
		f(array[i]);
}

// Const version of iter for functions that don't modify elements
template <typename T>
void iter(const T* array, size_t size, void (*f)(const T &)) {
	for (size_t i = 0; i < size; ++i)
		f(array[i]);
}

#endif