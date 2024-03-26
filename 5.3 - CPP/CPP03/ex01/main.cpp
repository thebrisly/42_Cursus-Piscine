/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 21:27:36 by brisly            #+#    #+#             */
/*   Updated: 2023/06/30 09:34:27 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    ClapTrap    First("Ben");
    ClapTrap    Second("John");
    ScavTrap   Third("Laura");

    std::cout << "\n(ง •_•)ง The Fight can start (ง •_•)ง\n" << std::endl;

    First.status();
    Second.status();
    Third.status();

    First.attack(Second.getName());
    Second.takeDamage(First.getDamage());
    std::cout << "\n";
    First.attack(Second.getName());
    Second.takeDamage(First.getDamage());
    std::cout << "\n";
    Second.attack(First.getName());
    First.takeDamage(Second.getDamage());
    std::cout << "\n";
    First.beRepaired(5);
    std::cout << "\n";
    Third.attack(First.getName());
    First.takeDamage(Third.getDamage());
    std::cout << "\n";
    First.attack(Third.getName());
    std::cout << "\n";
    Third.guardGate();
    // First.guardGate();   //if you want to test this to see that it doesn't work.
    std::cout << "\n";

    First.status();
    Second.status();
    Third.status();

    std::cout << "\nᴛʜᴇ fight ᴇɴᴅᴇᴅ\n" << std::endl;
}
