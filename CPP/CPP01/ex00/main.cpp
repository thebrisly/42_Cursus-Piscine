/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brisly <brisly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 21:36:10 by brisly            #+#    #+#             */
/*   Updated: 2023/06/03 21:12:18 by brisly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>
#include <string>

Zombie *newZombie(std::string name);
void randomChump(std::string name);

int main()
{
    std::cout << "> Creating a zombie on the stack" << std::endl; //what will disappear once we quit the program
    Zombie new_zombie1 = Zombie("Purple");
    new_zombie1.announce();
    std::cout << "\n-------------------------------\n" << std::endl;

    std::cout << "> Creating a zombie on the heap" << std::endl;
    Zombie *new_zombie2 = newZombie("Red");
    new_zombie2->announce();

    std::cout << "\n-------------------------------\n" << std::endl;

    std::cout << "Creating a third zombie using the function randomChump" << std::endl;
    randomChump("Green");

    std::cout << "\n-------------------------------\n" << std::endl;
    std::cout << "> Killing the zombie on the heap with delete" << std::endl;
    delete new_zombie2;
    std::cout << "> No need to kill zombie 1 as it is on stack (the end of the program will do it itself)" << std::endl;
    return 0; //when stack will be deleted zombie1 will die
}