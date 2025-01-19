/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 10:30:00 by tpaesch           #+#    #+#             */
/*   Updated: 2025/01/19 18:22:59 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include "Span.hpp"
#include "Colors.hpp"

/* here is the main from the subject and the expected output if you want to test that
Running this code:
int main()
{
Span sp = Span(5);
sp.addNumber(6);
sp.addNumber(3);
sp.addNumber(17);
sp.addNumber(9);
sp.addNumber(11);
std::cout << sp.shortestSpan() << std::endl;
std::cout << sp.longestSpan() << std::endl;
return 0;
}
Should output:
$> ./ex01
2
14
$>

*/


/**
* @brief Tests adding numbers to the Span and handling exceptions.
*
* @param s Reference to a Span object.
*/
void testAddNumbers(Span& s) {
	try {
		std::cout << GREEN << "Adding numbers to Span..." << RESET << std::endl;
		for (int i = 1; i <= 5; ++i) {
			s.addNumber(i * 10);
			std::cout << "Added: " << i * 10 << std::endl;
		}
		// Attempt to add one more number beyond capacity
		s.addNumber(60);
	}
	catch (const std::exception& e) {
		std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
	}
}

/**
* @brief Tests finding the shortest and longest spans in the Span.
*
* @param s Reference to a Span object.
*/
void testFindSpans(const Span& s) {
	try {
		std::cout << GREEN << "Calculating shortest span..." << RESET << std::endl;
		int shortest = s.shortestSpan();
		std::cout << "Shortest Span: " << shortest << std::endl;

		std::cout << GREEN << "Calculating longest span..." << RESET << std::endl;
		int longest = s.longestSpan();
		std::cout << "Longest Span: " << longest << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
	}
}

/**
* @brief Main function that runs various tests on the Span class.
*
* @return int Exit status code.
*/
int main() {
	std::cout << BRIGHT_BLUE << "=== Span Class Tests ===" << RESET << std::endl;

	// Test 1: Basic Functionality
	{
		std::cout << BRIGHT_YELLOW << "\nTest 1: Basic Functionality" << RESET << std::endl;
		Span sp = Span(5);
		testAddNumbers(sp);
		testFindSpans(sp);
	}

	// Test 2: Empty Span
	{
		std::cout << BRIGHT_YELLOW << "\nTest 2: Empty Span" << RESET << std::endl;
		Span sp = Span(5);
		testFindSpans(sp);
	}

	// Test 3: Span with One Element
	{
		std::cout << BRIGHT_YELLOW << "\nTest 3: Span with One Element" << RESET << std::endl;
		Span sp = Span(5);
		sp.addNumber(100);
		testFindSpans(sp);
	}

	// Test 4: Large Span
	{
		std::cout << BRIGHT_YELLOW << "\nTest 4: Large Span" << RESET << std::endl;
		Span sp = Span(10000);
		std::vector<int> largeNumbers;
		for (int i = 0; i < 10000; ++i) {
			largeNumbers.push_back(i);
		}
		// Using addNumbers with iterators
		sp.addNumbers(largeNumbers.begin(), largeNumbers.end());
		testFindSpans(sp);
	}

	// Test 5: Using Different Containers
	{
		std::cout << BRIGHT_YELLOW << "\nTest 5: Using Different Containers" << RESET << std::endl;
		Span sp = Span(10);
		std::list<int> numbers = {5, 3, 9, 1, 4};
		try {
			sp.addNumbers(numbers.begin(), numbers.end());
			std::cout << GREEN << "Added numbers from std::list<int>." << RESET << std::endl;
		}
		catch (const std::exception& e) {
			std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
		}
		testFindSpans(sp);
	}

	// Test 6: Edge Case with Maximum and Minimum Values
	{
		std::cout << BRIGHT_YELLOW << "\nTest 6: Edge Case with Maximum and Minimum Values" << RESET << std::endl;
		Span sp = Span(2);
		try {
			sp.addNumber(INT_MIN);
			sp.addNumber(INT_MAX);
			testFindSpans(sp);
		}
		catch (const std::exception& e) {
			std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
		}
	}

	// Test 7: Adding Numbers from a Deque
	{
		std::cout << BRIGHT_YELLOW << "\nTest 7: Adding Numbers from a Deque" << RESET << std::endl;
		Span sp = Span(5);
		std::deque<int> numbers = {10, 20, 30, 40, 50};
		try {
			sp.addNumbers(numbers.begin(), numbers.end());
			std::cout << GREEN << "Added numbers from std::deque<int>." << RESET << std::endl;
		}
		catch (const std::exception& e) {
			std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
		}
		testFindSpans(sp);
	}

	// Test 8: Attempting to Add Numbers Beyond Capacity
	{
		std::cout << BRIGHT_YELLOW << "\nTest 8: Attempting to Add Numbers Beyond Capacity" << RESET << std::endl;
		Span sp = Span(3);
		try {
			sp.addNumber(1);
			sp.addNumber(2);
			sp.addNumber(3);
			sp.addNumber(4); // This should throw an exception
		}
		catch (const std::exception& e) {
			std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
		}
		testFindSpans(sp);
	}

	std::cout << BRIGHT_BLUE << "\n=== All Tests Completed ===" << RESET << std::endl;

	return 0;
}