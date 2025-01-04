/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 17:35:54 by tpaesch           #+#    #+#             */
/*   Updated: 2025/01/04 06:54:17 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main() {
    // Create an intern and a bureaucrat
    Intern someRandomIntern;
    Bureaucrat boss("Boss", 1); // Assuming grade 1 is the highest

    try {
        // Attempt to create each form and have it signed and executed
        AForm* form1 = someRandomIntern.makeForm("robotomy request", "Bender");
        std::cout << *form1 << std::endl;
        boss.signForm(*form1);
        boss.executeForm(*form1);

        AForm* form2 = someRandomIntern.makeForm("presidential pardon", "Leela");
        std::cout << *form2 << std::endl;
        boss.signForm(*form2);
        boss.executeForm(*form2);

        AForm* form3 = someRandomIntern.makeForm("shrubbery creation", "Fry's House");
        std::cout << *form3 << std::endl;
        boss.signForm(*form3);
        boss.executeForm(*form3);

        // Attempt to create a form with an unknown name to test error handling
        AForm* unknownForm = someRandomIntern.makeForm("unknown form", "Nowhere");
        if (unknownForm) {
            boss.signForm(*unknownForm);
            boss.executeForm(*unknownForm);
        }
        if (form1) delete form1;
        if (form2) delete form2;
        if (form3) delete form3;
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
