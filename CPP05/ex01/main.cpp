/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 17:35:54 by tpaesch           #+#    #+#             */
/*   Updated: 2025/01/03 21:57:26 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "Colors.hpp"


int main()
{
	std::cout << YELLOW << "Test 1: Bureaucrat with highest grade signing form with highest grade required" << RESET << "\n";
	try
	{
		Bureaucrat bob("Bob", 1);
		Form form1("Existential Crisis Evaluation", 1, 1);

		bob.signForm(form1);
		std::cout << GREEN << "Expected: OK, Actual: OK" << RESET << "\n";
	}
	catch (std::exception& e)
	{
		std::cerr << RED << "Expected: OK, Actual: FAIL. Test 1 failed: " << e.what() << RESET << "\n";
	}

	std::cout << YELLOW << "Test 2: Bureaucrat with highest grade signing form with lower grade required" << RESET << "\n";
	try
	{
		Bureaucrat bob("Bob", 1);
		Form form1("Mood Swing Documentation Sheet", 2, 2);

		bob.signForm(form1);
		std::cout << GREEN << "Expected: OK, Actual: OK" << RESET << "\n";
	}
	catch (std::exception& e)
	{
		std::cerr << RED << "Expected: OK, Actual: FAIL. Test 2 failed: " << e.what() << RESET << "\n";
	}

	std::cout << YELLOW << "Test 3: Bureaucrat with lowest grade signing form with lowest grade required" << RESET << "\n";
	try
	{
		Bureaucrat bob("Bob", 150);
		Form form1("Sarcastic Satisfaction Survey", 150, 150);

		bob.signForm(form1);
		std::cout << GREEN << "Expected: OK, Actual: OK" << RESET << "\n";
	}
	catch (std::exception& e)
	{
		std::cerr << RED << "Expected: OK, Actual: FAIL. Test 3 failed: " << e.what() << RESET << "\n";
	}

	std::cout << YELLOW << "Test 4: Bureaucrat with lowest grade signing form with higher grade required" << RESET << "\n";
	try
	{
		Bureaucrat bob("Bob", 150);
		Form form1("The 'Why Bother?' Questionnaire", 149, 149);

		bob.signForm(form1);
	}
	catch (std::exception& e)
	{
		std::cerr << GREEN << "Expected: FAIL, Actual: FAIL. Test 4 passed as expected: " << e.what() << RESET << "\n";
	}

	std::cout << YELLOW << "Test 5: Bureaucrat with middle grade signing form with middle grade required" << RESET << "\n";
	try
	{
		Bureaucrat bob("Bob", 75);
		Form form1("Daily Despair Diary", 75, 75);

		bob.signForm(form1);
		std::cout << GREEN << "Expected: OK, Actual: OK" << RESET << "\n";
	}
	catch (std::exception& e)
	{
		std::cerr << RED << "Expected: OK, Actual: FAIL. Test 5 failed: " << e.what() << RESET << "\n";
	}
		std::cout << YELLOW << "Test 6: Creating a form with grade too high" << RESET << '\n';
	try
	{
		Form form1("Hopeless Task Tracker", 0, 0);
		std::cerr << RED << "Expected: FAIL, Actual: OK. Test 6 failed: Form created with grade too high" << RESET << '\n';
	}
	catch (Form::GradeTooHighException& e)
	{
		std::cout << GREEN << "Expected: FAIL, Actual: FAIL. Test 6 passed as expected: " << e.what() << RESET << '\n';
	}

	std::cout << YELLOW << "Test 7: Creating a form with grade too low" << RESET << '\n';
	try
	{
		Form form1("Gloomy Goals Assessment", 151, 151);
		std::cerr << RED << "Expected: FAIL, Actual: OK. Test 7 failed: Form created with grade too low" << RESET << '\n';
	}
	catch (Form::GradeTooLowException& e)
	{
		std::cout << GREEN << "Expected: FAIL, Actual: FAIL. Test 7 passed as expected: " << e.what() << RESET << '\n';
	}

	std::cout << YELLOW << "Test 8: Signing an already signed form" << RESET << '\n';
	try
	{
		Bureaucrat bob("Bob", 1);
		Form form1("Procrastination Progress Report", 1, 1);
		bob.signForm(form1);
		bob.signForm(form1);
		std::cerr << RED << "Test 8 failed: Form not signed twice as expected" << RESET << '\n';
	}
	catch (Form::FormIsSignedException& e)
	{
		std::cout << GREEN << "Expected: FAIL, Actual: FAIL. Test 8 passed as expected: " << e.what() << RESET << '\n';
	}

	return 0;
}
