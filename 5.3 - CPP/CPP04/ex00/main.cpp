/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brisly <brisly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 10:43:23 by brisly            #+#    #+#             */
/*   Updated: 2023/06/12 09:19:02 by brisly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

/* polymorphic pointer = a pointer from the base class to a derived object */
int main()
{
    const Animal* general = new Animal();
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();
    
    std::cout << "\033[34mGetting the type of each animal :\033[0m" << std::endl;
    std::cout << "Animal : " << general->getType() << " " << std::endl;
    std::cout << "Cat : " << cat->getType() << " " << std::endl;
    std::cout << "Dog : " << dog->getType() << " " << std::endl;
    std::cout << "\n";

    std::cout << "\033[34mLet's ask these animals to speak... \033[0m" << std::endl;
    std::cout << dog->getType() << " : ";
    dog->makeSound(); //will output the dog sound!
    std::cout << cat->getType() << " : ";
    cat->makeSound(); //will output the cat sound
    std::cout << "Random animal: ";
    general->makeSound();
    delete dog;
    delete cat;
    delete general;
    std::cout << "\n";

    std::cout << "\033[31m-----------------------------------\n" << std::endl;

    std::cout << "Now - let's add some fun (or not). We are going to create some fake animals.\033[0m" << std::endl;
    const WrongAnimal* fakegeneral = new WrongAnimal();
    const WrongAnimal* fakecat = new WrongCat();

    std::cout << "\033[31mLet's ask these animals to speak... \033[0m" << std::endl;
    std::cout << fakecat->getType() << " : ";
    fakecat->makeSound(); 
    std::cout << "Random animal: ";
    fakegeneral->makeSound();
    std::cout << "\n \033[0m";
        
    delete fakecat;
    delete fakegeneral;
}