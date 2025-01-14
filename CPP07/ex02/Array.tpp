/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 17:18:04 by tpaesch           #+#    #+#             */
/*   Updated: 2025/01/13 17:29:03 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
#define ARRAY_TPP

#include "Array.hpp"

template <typename T>
Array<T>::Array() : array_(nullptr), size_(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : array_(new T[n]()), size_(n) {
// Default-initializes n elements.
}

template <typename T>
Array<T>::Array(const Array& src) : array_(nullptr), size_(0) {
*this = src;  // Call the assignment operator
}

template <typename T>
Array<T>::~Array() {
delete[] array_;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& rhs) {
if (this != &rhs) {
	delete[] array_;
	size_ = rhs.size_;
	// Allocate new array and copy elements
	array_ = new T[size_];
	for (unsigned int i = 0; i < size_; i++) {
	array_[i] = rhs.array_[i];
	}
}
return *this;
}

template <typename T>
T& Array<T>::operator[](unsigned int i) {
if (i >= size_) {
	throw OutOfRangeException();
}
return array_[i];
}

template <typename T>
const T& Array<T>::operator[](unsigned int i) const {
if (i >= size_) {
	throw OutOfRangeException();
}
return array_[i];
}

template <typename T>
unsigned int Array<T>::size() const {
return size_;
}

#endif
