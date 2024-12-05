/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 20:53:52 by tpaesch           #+#    #+#             */
/*   Updated: 2024/12/05 17:48:17 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {

	Animal* animals[2];

	animals[0] = new Dog();
	animals[1] = new Cat();

	for (int i = 0; i < 2; i++)
		animals[i]->makeSound();

	for (int i = 0; i < 2; i++)
		delete animals[i];


	WrongAnimal* wrongAnimals[2];

	wrongAnimals[0] = new WrongCat();
	wrongAnimals[1] = new WrongAnimal();

	for (int i = 0; i < 2; i++)
		wrongAnimals[i]->makeSound();

	for (int i = 0; i < 2; i++)
		delete wrongAnimals[i];

	
	return 0;
}

