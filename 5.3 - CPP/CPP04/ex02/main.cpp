/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 10:43:23 by brisly            #+#    #+#             */
/*   Updated: 2023/08/16 12:54:32 by lfabbian         ###   ########.fr       */
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

    // If you try this code, it won't be possible. It will tell you that you can create an object of abstract class :
    // const Animal* general = new Animal();
    // std::cout << "Animal : " << general->getType() << " " << std::endl;
    // std::cout << "Random animal: ";
    // general->makeSound();

}
