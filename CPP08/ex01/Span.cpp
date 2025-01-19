/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 10:20:00 by tpaesch           #+#    #+#             */
/*   Updated: 2025/01/19 18:17:38 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

/**
* @brief Constructor that initializes the Span with a maximum capacity.
* @param N The maximum number of integers the Span can hold.
*/
Span::Span(unsigned int N) : _maxSize(N) {
	_numbers.reserve(N);
}

/**
* @brief Copy constructor. Creates a deep copy of another Span instance.
* @param other The Span instance to copy from.
*/
Span::Span(const Span& other) : _maxSize(other._maxSize), _numbers(other._numbers) {
}

/**
* @brief Destructor. Cleans up any allocated resources.
*/
Span::~Span() {
	// No dynamic memory to clean up since std::vector handles its own memory
}

/**
* @brief Assignment operator. Performs a deep copy.
* @param other The Span instance to assign from.
* @return Reference to the current Span instance.
*/
Span& Span::operator=(const Span& other) {
	if (this != &other) {
		_maxSize = other._maxSize;
		_numbers = other._numbers;
	}
	return *this;
}

/**
* @brief Adds a single integer to the Span.
* @param number The integer to add.
* @throws SpanFullException If the Span is already full.
*/
void Span::addNumber(int number) {
	if (_numbers.size() >= _maxSize) {
		throw SpanFullException();
	}
	_numbers.push_back(number);
}

/**
* @brief Finds the shortest span between any two numbers in the Span.
* @return The shortest span as an integer.
* @throws NoSpanFoundException If there are fewer than two numbers.
*/
int Span::shortestSpan() const {
	if (_numbers.size() < 2) {
		throw NoSpanFoundException();
	}

	// Create a copy of the numbers and sort them
	std::vector<int> sorted = _numbers;
	std::sort(sorted.begin(), sorted.end());

	// Find the minimum span
	int minSpan = INT_MAX;
	for (size_t i = 0; i < sorted.size() - 1; ++i) {
		int span = sorted[i + 1] - sorted[i];
		if (span < minSpan) {
			minSpan = span;
		}
	}
	return minSpan;
}

/**
* @brief Finds the longest span between any two numbers in the Span.
* @return The longest span as an integer.
* @throws NoSpanFoundException If there are fewer than two numbers.
*/
int Span::longestSpan() const {
	if (_numbers.size() < 2) {
		throw NoSpanFoundException();
	}

	// Find the minimum and maximum elements
	int min = *std::min_element(_numbers.begin(), _numbers.end());
	int max = *std::max_element(_numbers.begin(), _numbers.end());

	return max - min;
}