/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brisly <brisly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 21:27:36 by brisly            #+#    #+#             */
/*   Updated: 2023/06/09 14:13:55 by brisly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
    ClapTrap    First("Ben");
    ClapTrap    Second("John");
    ClapTrap    Third(First);

    std::cout << "\n(ง •_•)ง The Fight can start (ง •_•)ง\n" << std::endl;

    First.status();
    Second.status();
    
    First.attack(Second.getName());
    Second.takeDamage(First.getDamage());
    std::cout << "\n";
    First.attack(Second.getName());
    Second.takeDamage(First.getDamage());
    std::cout << "\n";
    Second.attack(First.getName());
    First.takeDamage(Second.getDamage());
    std::cout << "\n";
    std::cout << "It's such a shame for the best fighter (aka " << First.getName() << ") to have taken a blow. He will take a little break." << std::endl;
    First.beRepaired(5);

    First.status();
    Second.status();

    std::cout << "\nᴛʜᴇ fight ᴇɴᴅᴇᴅ\n" << std::endl;
}