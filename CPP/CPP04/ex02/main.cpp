/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brisly <brisly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 10:43:23 by brisly            #+#    #+#             */
/*   Updated: 2023/06/12 21:01:07 by brisly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

// a class is abstract if it contains at least one abstract method; 
// it cannot be instantiated, but its non-abstract subclasses can.

int main()
{
    ///*
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();
    
    std::cout << "\033[34mGetting the type of each animal :\033[0m" << std::endl;
    std::cout << "Cat : " << cat->getType() << " " << std::endl;
    std::cout << "Dog : " << dog->getType() << " " << std::endl;
    std::cout << "\n";

    std::cout << "\033[34mLet's ask these animals to speak... \033[0m" << std::endl;
    std::cout << dog->getType() << " : ";
    dog->makeSound(); //will output the dog sound!
    std::cout << cat->getType() << " : ";
    cat->makeSound(); //will output the cat sound
    delete dog;
    delete cat;
    //*/
    
    // ----------------------------------------------------------------

    //If you try this code, it won't be possible. It will tell you that you can create an object of abstract class :
    //const Animal* general = new Animal();
    //std::cout << "Animal : " << general->getType() << " " << std::endl;
    //std::cout << "Random animal: ";
    //general->makeSound();

    // ----------------------------------------------------------------

    // This will continue to work normally.
    /*
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
    */

    // -------------------------------------------------------------------
    /* Proof that the copies are not superficial */
    // -------------------------------------------------------------------
    /* Shallow copy: If the value inside the address is modified at any point, the value will be
    modified both in A and B since they both point to the same location in memory.
    This is not desirable. If any variables were allocated on the heap -> deep copy!

    Deep copy: Despite having the same values, each object has its 
    own allocated memory for its member variables. */

    /*
    std::cout << "Creating one normal dog and one normal cat: " << std::endl;
    Dog dog;
    Cat cat;

    Dog & dog_address = dog;
    Cat & cat_address = cat;
    std::cout << std::endl;

    std::cout << "Creating a copy of the normal dog and a copy of the normal cat: " << std::endl;
    Dog dog_copy(dog_address);
    Cat cat_copy(cat_address);

    Dog & dog_copy_address = dog_copy;
    Cat & cat_copy_address = cat_copy;
    std::cout << std::endl;

    std::cout << "Modifying the type of the copies" << std::endl;
    dog_copy_address.setType("FAKE !");
    cat_copy_address.setType("FAKE !");
    std::cout << std::endl;

    std::cout << "Check if original dogs and cats have been modified" << std::endl;
    std::cout << "Original dog: " << dog.getType() << std::endl;
    std::cout << "Original cat: " << cat.getType() << std::endl;
    std::cout << std::endl;
    */
}