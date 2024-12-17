/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 12:35:07 by tpaesch           #+#    #+#             */
/*   Updated: 2024/12/17 16:44:11 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Colors.hpp"

void printTestTitle(const std::string& title) {
    std::cout << CYAN << "\n=== " << title << " ===" << RESET << std::endl;
}

void testAdvancedFunctionality() {
    printTestTitle("Testing Advanced Functionality");

    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter* protagonist = new Character("Hero");
    ICharacter* sidekick = new Character("Sidekick");

    // Equip and clone materias
    AMateria* ice = src->createMateria("ice");
    protagonist->equip(ice);
    protagonist->equip(src->createMateria("cure"));
    sidekick->equip(ice->clone());

    // Use materias
    protagonist->use(0, *sidekick);
    protagonist->use(1, *sidekick);
    sidekick->use(0, *protagonist);

    // Unequip and re-equip
    protagonist->unequip(0);
    protagonist->equip(src->createMateria("ice"));

    delete sidekick;
    delete protagonist;
    delete src;

    std::cout << GREEN << "Advanced Functionality Test Complete" << RESET << std::endl;
}

void testDeepCopy() {
    printTestTitle("Testing Deep Copy Functionality");

    Character original("Original");
    original.equip(new Ice());
    original.equip(new Cure());

    // Performing a deep copy
    Character copy = original;

    // Using materias to check if the copy has its own materias
    std::cout << YELLOW << "Using Materias on Original Character:" << RESET << std::endl;
    original.use(0, original);
    original.use(1, original);

    std::cout << YELLOW << "Using Materias on Copied Character:" << RESET << std::endl;
    copy.use(0, copy);
    copy.use(1, copy);

    std::cout << BRIGHT_RED << "Deep Copy Test Complete" << RESET << std::endl;
}

void testBasicFunctionality() {
    printTestTitle("Testing Functionality");

    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter* protagonist = new Character("Hero");
    AMateria* tmp;

    tmp = src->createMateria("ice");
    protagonist->equip(tmp);
    tmp = src->createMateria("cure");
    protagonist->equip(tmp);

    ICharacter* antagonist = new Character("Villain");
    protagonist->use(0, *antagonist);
    protagonist->use(1, *antagonist);

    delete antagonist;
    delete protagonist;
    delete src;

    std::cout << GREEN << "Basic Functionality Test Complete" << RESET << std::endl;
}

int main() {
    testBasicFunctionality();
	testAdvancedFunctionality();
    return 0;
}

