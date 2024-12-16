/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 20:53:52 by tpaesch           #+#    #+#             */
/*   Updated: 2024/12/15 21:52:06 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Colors.hpp"
#include "Dog.hpp"

# define COUNT 10

int main() {
    // Test creating individual animals
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();
    
    // Test sounds
    dog->makeSound(); // Should output "WOOF!"
    cat->makeSound(); // Should output "MEOW!"

    // Test destructor (should not create a leak)
    delete dog;
    delete cat;

    // Test array of Animal objects (half dogs, half cats)
    Animal* animals[COUNT];

    for (int i = 0; i < COUNT; i++) {
        if (i % 2) {
            animals[i] = new Dog();
        } else {
            animals[i] = new Cat();
        }
    }

    // Test sounds in array
    for (int i = 0; i < COUNT; i++) {
        animals[i]->makeSound();
    }

    // Delete animals
    for (int i = 0; i < COUNT; i++) {
        delete animals[i];
    }

    // Test deep copy
    Dog originalDog;
    Dog copyDog(originalDog); // Using copy constructor

    Cat originalCat;
    Cat copyCat = originalCat; // Using assignment operator
    return 0;
}
