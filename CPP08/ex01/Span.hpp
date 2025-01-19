/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 10:10:00 by tpaesch           #+#    #+#             */
/*   Updated: 2025/01/19 18:17:57 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <exception>
#include <climits>

/**
* @class Span
* @brief A class that can store a maximum of N integers and find the shortest and longest spans.
*/
class Span {
public:
	/**
	* @class SpanFullException
	* @brief Exception thrown when attempting to add a number beyond the Span's capacity.
	*/
	class SpanFullException : public std::exception {
	public:
		/**
		* @brief Provides an explanatory string.
		* @return C-style string describing the exception.
		*/
		virtual const char* what() const noexcept override {
			return "Span is already full. Cannot add more numbers.";
		}
	};

	/**
	* @class NoSpanFoundException
	* @brief Exception thrown when there are not enough numbers to find a span.
	*/
	class NoSpanFoundException : public std::exception {
	public:
		/**
		* @brief Provides an explanatory string.
		* @return C-style string describing the exception.
		*/
		virtual const char* what() const noexcept override {
			return "Not enough numbers to find a span.";
		}
	};

	/**
	* @brief Constructor that initializes the Span with a maximum capacity.
	* @param N The maximum number of integers the Span can hold.
	*/
	Span(unsigned int N);

	/**
	* @brief Copy constructor. Creates a deep copy of another Span instance.
	* @param other The Span instance to copy from.
	*/
	Span(const Span& other);

	/**
	* @brief Destructor. Cleans up any allocated resources.
	*/
	~Span();

	/**
	* @brief Assignment operator. Performs a deep copy.
	* @param other The Span instance to assign from.
	* @return Reference to the current Span instance.
	*/
	Span& operator=(const Span& other);

	/**
	* @brief Adds a single integer to the Span.
	* @param number The integer to add.
	* @throws SpanFullException If the Span is already full.
	*/
	void addNumber(int number);

	/**
	* @brief Adds multiple integers to the Span using iterators.
	* @tparam InputIterator The type of input iterators.
	* @param begin Iterator to the beginning of the range.
	* @param end Iterator to the end of the range.
	* @throws SpanFullException If adding the range exceeds the Span's capacity.
	*/
	template <typename InputIterator>
	void addNumbers(InputIterator begin, InputIterator end) {
		if (std::distance(begin, end) + _numbers.size() > _maxSize) {
			throw SpanFullException();
		}
		_numbers.insert(_numbers.end(), begin, end);
	}

	/**
	* @brief Finds the shortest span between any two numbers in the Span.
	* @return The shortest span as an integer.
	* @throws NoSpanFoundException If there are fewer than two numbers.
	*/
	int shortestSpan() const;

	/**
	* @brief Finds the longest span between any two numbers in the Span.
	* @return The longest span as an integer.
	* @throws NoSpanFoundException If there are fewer than two numbers.
	*/
	int longestSpan() const;

private:
	unsigned int _maxSize;      ///< Maximum number of integers the Span can hold.
	std::vector<int> _numbers;   ///< Container to store the integers.

	/**
	* @brief Private default constructor to prevent instantiation without a size.
	*/
	Span();

};

#endif // SPAN_HPP