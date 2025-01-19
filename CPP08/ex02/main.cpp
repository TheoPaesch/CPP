/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 10:00:00 by user              #+#    #+#             */
/*   Updated: 2025/01/19 20:02:51 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include "MutantStack.hpp"
#include "Colors.hpp"

int main()
{
	std::cout << BRIGHT_BLUE << "=== MutantStack Class Tests ===" << RESET << std::endl;

	// Test 1: Basic Operations
	{
		std::cout << BRIGHT_YELLOW << "\n[Test 1] Basic Operations" << RESET << std::endl;
		MutantStack<int> mstack;

		mstack.push(10);
		mstack.push(20);
		mstack.push(30);

		std::cout << GREEN << "Top element: " << RESET << mstack.top() << std::endl; // Should be 30
		mstack.pop();
		std::cout << GREEN << "Size after pop: " << RESET << mstack.size() << std::endl; // Should be 2
	}

	// Test 2: Iteration Over the Stack
	{
		std::cout << BRIGHT_YELLOW << "\n[Test 2] Iteration Over the Stack" << RESET << std::endl;
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);

		std::cout << BRIGHT_CYAN << "Iterating through MutantStack:" << RESET << std::endl;
		for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
			std::cout << *it << std::endl;
	}

	// Test 3: Reverse Iteration
	{
		std::cout << BRIGHT_YELLOW << "\n[Test 3] Reverse Iteration" << RESET << std::endl;
		MutantStack<int> mstack;
		for(int i = 1; i <= 5; ++i)
			mstack.push(i * 10); // Pushes 10, 20, 30, 40, 50

		std::cout << BRIGHT_CYAN << "Reverse Iterating through MutantStack:" << RESET << std::endl;
		for(MutantStack<int>::reverse_iterator rit = mstack.rbegin(); rit != mstack.rend(); ++rit)
			std::cout << *rit << std::endl;
	}

	// Test 4: Copy Construction and Assignment
	{
		std::cout << BRIGHT_YELLOW << "\n[Test 4] Copy Construction and Assignment" << RESET << std::endl;
		MutantStack<int> original;
		original.push(100);
		original.push(200);
		original.push(300);

		// Copy Constructor
		MutantStack<int> copy = original;
		std::cout << BRIGHT_GREEN << "Elements in copy (after copy construction):" << RESET << std::endl;
		for(auto it = copy.begin(); it != copy.end(); ++it)
			std::cout << *it << std::endl;

		// Assignment Operator
		MutantStack<int> assigned;
		assigned = original;
		std::cout << BRIGHT_GREEN << "Elements in assigned stack (after assignment):" << RESET << std::endl;
		for(auto it = assigned.begin(); it != assigned.end(); ++it)
			std::cout << *it << std::endl;
	}

	// Test 5: Using MutantStack with Different Data Types
	{
		std::cout << BRIGHT_YELLOW << "\n[Test 5] Different Data Types (std::string)" << RESET << std::endl;
		MutantStack<std::string> mstack;
		mstack.push("Hello");
		mstack.push("World");
		mstack.push("MutantStack");
		mstack.push("C++");

		std::cout << BRIGHT_CYAN << "Iterating through MutantStack<string>:" << RESET << std::endl;
		for(auto it = mstack.begin(); it != mstack.end(); ++it)
			std::cout << *it << std::endl;
	}

	// Test 6: Stress Testing with Large Data Sets
	{
		std::cout << BRIGHT_YELLOW << "\n[Test 6] Stress Testing with Large Data Sets" << RESET << std::endl;
		MutantStack<int> mstack;
		const int large_size = 10000;

		std::cout << BRIGHT_GREEN << "Pushing " << large_size << " elements..." << RESET << std::endl;
		for(int i = 0; i < large_size; ++i)
			mstack.push(i);

		std::cout << BRIGHT_GREEN << "Size after pushing: " << RESET << mstack.size() << std::endl;

		// Verify top element
		std::cout << BRIGHT_GREEN << "Top element: " << RESET << mstack.top() << std::endl;

		// Iterate through first 5 elements
		std::cout << BRIGHT_CYAN << "First 5 elements:" << RESET << std::endl;
		MutantStack<int>::iterator it = mstack.begin();
		for(int i = 0; i < 5 && it != mstack.end(); ++i, ++it)
			std::cout << *it << std::endl;
	}

	// Test 7: Comparing MutantStack with std::deque
	{
		std::cout << BRIGHT_YELLOW << "\n[Test 7] Comparing MutantStack with std::deque" << RESET << std::endl;
		MutantStack<int, std::deque<int>> mstack_deque;
		std::deque<int> d;

		// Populate both containers
		for(int i = 1; i <= 5; ++i) {
			mstack_deque.push(i * 10);
			d.push_back(i * 10);
		}

		std::cout << BRIGHT_GREEN << "Elements in MutantStack<std::deque>:" << RESET << std::endl;
		for(auto it = mstack_deque.begin(); it != mstack_deque.end(); ++it)
			std::cout << *it << " ";
		std::cout << std::endl;

		std::cout << BRIGHT_GREEN << "Elements in std::deque:" << RESET << std::endl;
		for(auto it = d.begin(); it != d.end(); ++it)
			std::cout << *it << " ";
		std::cout << std::endl;
	}

	// Test 8: Exception Handling (Accessing Top on Empty Stack)
	{
		std::cout << BRIGHT_YELLOW << "\n[Test 8] Exception Handling (Accessing Top on Empty Stack)" << RESET << std::endl;
		MutantStack<int> empty_stack;
		try {
			std::cout << "Attempting to access top element of empty stack..." << std::endl;
			std::cout << empty_stack.top() << std::endl; // Undefined behavior, but std::stack::top() does not throw
		}
		catch(const std::exception& e) {
			std::cout << RED << "Exception caught: " << e.what() << RESET << std::endl;
		}

		// To safely handle, we can check if stack is empty before accessing top
		if(!empty_stack.empty())
			std::cout << "Top element: " << empty_stack.top() << std::endl;
		else
			std::cout << YELLOW << "Stack is empty. Cannot access top element." << RESET << std::endl;
	}

	std::cout << BRIGHT_BLUE << "\n=== All Tests Completed ===" << RESET << std::endl;

	return 0;
}

// //  main from the subject:

// int main()
// {
// MutantStack<int> mstack;
// mstack.push(5);
// mstack.push(17);
// std::cout << mstack.top() << std::endl;
// mstack.pop();
// std::cout << mstack.size() << std::endl;
// mstack.push(3);
// mstack.push(5);
// mstack.push(737);
// //[...]
// mstack.push(0);
// MutantStack<int>::iterator it = mstack.begin();
// MutantStack<int>::iterator ite = mstack.end();
// ++it;
// --it;
// while (it != ite)
// {
// std::cout << *it << std::endl;
// ++it;
// }
// std::stack<int> s(mstack);
// return 0;
// }
