/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 20:53:52 by tpaesch           #+#    #+#             */
/*   Updated: 2024/12/15 20:43:41 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Colors.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

# define COUNT 3

int main() {
	// Testing with array of pointers
	Animal* animals[COUNT];

	for (int i = 0; i < COUNT; ++i) {
		if (i % 2 == 0) {
			animals[i] = new Dog();
		}
		else if (i % 3 == 0) {
			animals[i] = new Cat();
		}
		else {
			animals[i] = new Animal();
		}
	}

	for (int i = 0; i < COUNT; ++i) {
		std::cout << animals[i]->getType() << ": ";
		animals[i]->makeSound();
	}

	// Clean up
	for (int i = 0; i < COUNT; ++i) {
		delete animals[i];
	}

	// Testing dynamic casting (C++ style casting can be used in C++98)
	Animal* animal = new Dog();
	Dog* dog = dynamic_cast<Dog*>(animal);
	if (dog != NULL) {
		std::cout << "Dynamic cast to Dog successful." << std::endl;
	}

	Cat* cat = dynamic_cast<Cat*>(animal);
	if (cat == NULL) {
		std::cout << "Dynamic cast to Cat failed, as expected." << std::endl;
	}

	delete animal;

	// Testing WrongAnimal and WrongCat
	WrongAnimal* wrongAnimals[COUNT];
	wrongAnimals[0] = new WrongCat();
	wrongAnimals[1] = new WrongAnimal();
	wrongAnimals[2] = new WrongCat();

	for (int i = 0; i < COUNT; ++i) {
		std::cout << wrongAnimals[i]->getType() << ": ";
		wrongAnimals[i]->makeSound();
	}

	// Clean up
	for (int i = 0; i < COUNT; ++i) {
		delete wrongAnimals[i];
	}

	return 0;
}

