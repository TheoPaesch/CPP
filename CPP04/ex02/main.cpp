/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 20:53:52 by tpaesch           #+#    #+#             */
/*   Updated: 2024/12/05 18:28:21 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int main() {
    int amount = 4;
    int current = 0;

    if (amount % 2 != 0) {
        std::cout << "Please enter an even number" << std::endl;
        return 1;
    }

    const Animal* a = new Dog();
    const Animal* b = new Cat();

    delete a; // should not create a leak
    delete b;

    const Animal* dogs[amount / 2];
    const Animal* cats[amount / 2];

    // Create Dog objects
    while (current != (amount / 2)) {
        dogs[current] = new Dog();
        dogs[current]->makeSound();
        current++;
    }

    // Create Cat objects
    current = 0; // Reset current for cats array
    while (current != (amount / 2)) {
        cats[current] = new Cat();
        cats[current]->makeSound();
        current++;
    }

    // Delete Cat objects
    current = amount / 2 - 1; // Set current to the last index of cats array
    while (current >= 0) {
        delete cats[current];
        current--;
    }

    // Delete Dog objects
    current = amount / 2 - 1; // Set current to the last index of dogs array
    while (current >= 0) {
        delete dogs[current];
        current--;
    }

    return 0;
}

// int main() {

// 	Animal* animals[2];

// 	animals[0] = new Dog();
// 	animals[1] = new Cat();

// 	for (int i = 0; i < 2; i++)
// 		animals[i]->makeSound();

// 	for (int i = 0; i < 2; i++)
// 		delete animals[i];


// 	WrongAnimal* wrongAnimals[2];

// 	wrongAnimals[0] = new WrongCat();
// 	wrongAnimals[1] = new WrongAnimal();

// 	for (int i = 0; i < 2; i++)
// 		wrongAnimals[i]->makeSound();

// 	for (int i = 0; i < 2; i++)
// 		delete wrongAnimals[i];

	
// 	return 0;
// }

