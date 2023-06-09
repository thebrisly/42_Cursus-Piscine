/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScravTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brisly <brisly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 15:08:12 by brisly            #+#    #+#             */
/*   Updated: 2023/06/09 21:38:18 by brisly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScravTrap.hpp"

ScravTrap::ScravTrap(std::string name) : ClapTrap(name) {
    std::cout << "\033[90mConstructor for ScravTrap " << this->_name << " called\033[0m" << std::endl;
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
}

ScravTrap::~ScravTrap() {
    std::cout << "\033[90mDestructor for ScravTrap " << this->_name << " called\033[0m" << std::endl;
} 

ScravTrap::ScravTrap(const ScravTrap &source) : ClapTrap(source) {
    std::cout << "\033[90mCopy constructor ScravTrap called\033[0m" << std::endl;
    *this = source;
}

ScravTrap& ScravTrap::operator=(ScravTrap const &src) {
    std::cout << "\033[90mAssignment operator called\033[0m" << std::endl;
    
    ClapTrap::operator=(src);

    this->_name = src._name;
    this->_hitPoints = src._hitPoints;
    this->_energyPoints = src._energyPoints;
    this->_attackDamage = src._attackDamage;

    return (*this);
}

void ScravTrap::attack(const std::string &target) {
        if (this->_energyPoints - 1 < 0)
    {
        std::cout << "\033[31mScravTrap " << this->_name << " seems not having any energy points left... He can't attack !\033[0m" << std::endl;
        this->_attackDamage = -1;
    }
    else if (this->_hitPoints <= 0)
    {
        std::cout << "\033[31mScravTrap " << this->_name << " seems dead... Obviously, he can't attack !\033[0m" << std::endl;
        this->_attackDamage = -1;
    }
    else if (this->_attackDamage == 0)
        std::cout << "\033[31mScravTrap " << this->_name << " will do no damage, since the damage inflicted by attacking is 0!\033[0m" << std::endl;
    else
    {
        std::cout << "\033[34m The big and only ScravTrap " << this->_name << " attacks " << target << " causing " << this->_attackDamage << " points of damage !  ( ◞•̀д•́)◞⚔◟(•̀д•́◟ )\033[m" << std::endl; 
        this->_energyPoints -= 1;
        std::cout << "\033[36m                  Remaining energy points for " << this->_name << " : " << this->_energyPoints << "\033[0m" << std::endl;
    }
}

void ScravTrap::guardGate()
{
    std::cout << "WARNING ! The big ScravTrap " << this->_name << " is now garding the gate... be careful" << std::endl;
}