/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 19:52:06 by tpaesch           #+#    #+#             */
/*   Updated: 2025/01/19 19:55:15 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <iterator>
#include <iostream>


/**
* @class MutantStack
* @brief A stack that allows iteration through its elements.
*
* The MutantStack class inherits from std::stack and exposes iterators to iterate
* through the elements of the stack.
*
* @tparam T The type of elements stored in the stack.
* @tparam Container The underlying container type. Defaults to std::deque<T>.
*/
template <typename T, typename Container = std::deque<T>>
class MutantStack : public std::stack<T, Container> {
public:
	// Type definitions for iterator support
	typedef typename Container::iterator iterator;
	typedef typename Container::const_iterator const_iterator;
	typedef typename Container::reverse_iterator reverse_iterator;
	typedef typename Container::const_reverse_iterator const_reverse_iterator;

	// Constructors and Destructor
	MutantStack();
	MutantStack(const MutantStack& other);
	~MutantStack();

	// Assignment Operator
	MutantStack& operator=(const MutantStack& other);

	// Iterator functions
	iterator begin();
	iterator end();
	reverse_iterator rbegin();
	reverse_iterator rend();
};

#include "MutantStack.tpp"

#endif