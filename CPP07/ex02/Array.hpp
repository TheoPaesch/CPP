/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 17:18:41 by tpaesch           #+#    #+#             */
/*   Updated: 2025/01/13 17:30:52 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstddef>  // for size_t
#include <exception>
#include <iostream>

/**
* @brief A template class representing a dynamically allocated array of type T.
*/
template <typename T>
class Array {
public:
/**
* @class OutOfRangeException
* @brief Exception thrown when accessing an index out of bounds.
*/
class OutOfRangeException : public std::exception {
public:
	/**
	* @brief Returns an explanatory error message.
	*/
	virtual const char* what() const throw() {
	return "Array: index out of range";
	}
};

/**
* @brief Default constructor: creates an empty array.
*/
Array();

/**
* @brief Creates an array with n default-initialized elements.
* @param n Number of elements to allocate.
*/
explicit Array(unsigned int n);

/**
* @brief Copy constructor. Performs a deep copy of src.
* @param src Another Array object to copy from.
*/
Array(const Array& src);

/**
* @brief Destructor. Releases memory.
*/
~Array();

/**
* @brief Assignment operator. Performs a deep copy.
* @param rhs Another Array object to assign from.
* @return Reference to this Array.
*/
Array& operator=(const Array& rhs);

/**
* @brief Subscript operator (non-const). Throws if index is out of range.
* @param i Index to access.
* @return Reference to the i-th element.
*/
T& operator[](unsigned int i);

/**
* @brief Subscript operator (const). Throws if index is out of range.
* @param i Index to access.
* @return Const reference to the i-th element.
*/
const T& operator[](unsigned int i) const;

/**
* @brief Returns the number of elements in the array.
* @return Current size of the array.
*/
unsigned int size() const;

private:
T* array_;           ///< Pointer to the dynamically allocated array of T.
unsigned int size_;  ///< Number of elements in the array.
};

#include "Array.tpp"

#endif