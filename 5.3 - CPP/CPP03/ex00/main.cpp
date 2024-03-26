/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 21:27:36 by brisly            #+#    #+#             */
/*   Updated: 2023/06/30 09:29:39 by lfabbian         ###   ########.fr       */
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
    First.beRepaired(5);

    First.status();
    Second.status();

    std::cout << "\nᴛʜᴇ fight ᴇɴᴅᴇᴅ\n" << std::endl;
}
