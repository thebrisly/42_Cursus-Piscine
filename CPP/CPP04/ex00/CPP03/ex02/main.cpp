/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brisly <brisly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 21:27:36 by brisly            #+#    #+#             */
/*   Updated: 2023/06/09 21:56:26 by brisly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
    ClapTrap    First("Ben");
    ClapTrap    Second("John");
    ScavTrap   Third("Laura");
    FragTrap    Fourth("Ann");


    std::cout << "\n(ง •_•)ง The Fight can start (ง •_•)ง\n" << std::endl;

    First.status();
    Second.status();
    Third.status();
    Fourth.status();
    
    std::cout << "\n";
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
    std::cout << "\n";
    Fourth.attack(Third.getName());
    Third.takeDamage(Fourth.getDamage());
    // First.guardGate();   if you want to test this to see that it doesn't work.
    std::cout << "\n";
    Fourth.highFivesGuys();
    //Third.highFivesGuys(); will not work

    First.status();
    Second.status();
    Third.status();
    Fourth.status();

    std::cout << "\nᴛʜᴇ fight ᴇɴᴅᴇᴅ\n" << std::endl;
}