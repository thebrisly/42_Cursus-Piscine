/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 10:43:23 by brisly            #+#    #+#             */
/*   Updated: 2023/08/16 12:47:21 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

/* polymorphic pointer = a pointer from the base class to a derived object */
int main()
{
    ///*
    int number_animals = 5;
    int i = 0;

    Animal* animals_tab[number_animals];

    while (i < number_animals / 2) {
        animals_tab[i] = new Dog();
        i++;
    }

    std::cout << std::endl;
    while (i < number_animals){
        animals_tab[i] = new Cat();
        i++;
    }

    std::cout << std::endl;
    i = 0;
    while (i < number_animals)
    {
        std::cout << animals_tab[i]->getType() << " " << (i + 1) << " does this sound : ";
        animals_tab[i]->makeSound();
        i++;
    }

    i = 0;
    std::cout << "\nAnd now we destroy every object... \n " << std::endl;
    while (i < number_animals){
        delete animals_tab[i];
        i++;
    }
    //*/

    // -------------------------------------------------------------------
    /* Proof that the copies are not superficial */
    // -------------------------------------------------------------------
    /* Shallow copy: If the value inside the address is modified at any point, the value will be
    modified both in A and B since they both point to the same location in memory.
    This is not desirable. If any variables were allocated on the heap -> deep copy!

    Deep copy: Despite having the same values, each object has its
    own allocated memory for its member variables. */


    std::cout << "Creating one normal dog and one normal cat: " << std::endl;
    Dog dog;
    Cat cat;

    Dog & dog_address = dog;
    Cat & cat_address = cat;
    std::cout << std::endl;

    std::cout << "Creating the brain of the originals" << std::endl;
    dog_address.getBrain()->setIdea(0, "ORIGINAL IDEA DOG");
    cat_address.getBrain()->setIdea(0, "ORIGINAL IDEA CAT");
    std::cout << std::endl;

    std::cout << "Creating a copy of the normal dog and a copy of the normal cat: " << std::endl;
    Dog dog_copy(dog_address);
    Cat cat_copy(cat_address);

    Dog & dog_copy_address = dog_copy;
    Cat & cat_copy_address = cat_copy;
    std::cout << std::endl;


    std::cout << "Modifying the brain of the copies" << std::endl;
    dog_copy_address.getBrain()->setIdea(0, "FAKE IDEA DOG");
    cat_copy_address.getBrain()->setIdea(0, "FAKE IDEA CAT");
    std::cout << std::endl;


    std::cout << "Check if original brains have been modified" << std::endl;
    std::cout << "Original dog's brain idea: " << dog.getBrain()->getIdea(0) << std::endl;
    std::cout << "Original cat's brain idea: " << cat.getBrain()->getIdea(0) << std::endl;
    std::cout << std::endl;

    Cat foo;
    Cat bar;

    Dog a;
    Dog b;

    a = b;

    foo = bar;
}
