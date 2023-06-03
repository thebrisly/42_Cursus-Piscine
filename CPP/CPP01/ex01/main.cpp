/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brisly <brisly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 21:36:10 by brisly            #+#    #+#             */
/*   Updated: 2023/06/03 21:17:07 by brisly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>
#include <string>

Zombie* zombieHorde(int N, std::string name);

int main()
{
    int i = 0;
    int n = 10;
    std::cout << "Creating " << n << " zombies..." << std::endl;
    Zombie *group;
    group = zombieHorde(n, "Laura");
    
    std::cout << "\n-------------------------------\n" << std::endl;
    Zombie *current = group;

    std::cout << "Making them announce theirself" << std::endl;
    while (i < n)
    {
        std::cout << i + 1 << " ";
        current->announce();
        i++;
        current++;
    }
    i = 0;
    
    std::cout << "\n-------------------------------\n" << std::endl;

    std::cout << "Deleting all the zombies in one line" << std::endl;
    delete [] group;
}  