/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScravTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brisly <brisly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 15:08:12 by brisly            #+#    #+#             */
/*   Updated: 2023/06/09 21:29:27 by brisly           ###   ########.fr       */
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

void ScravTrap::guardGate()
{
    std::cout << "WARNING ! The big ScravTrap " << this->_name << " is now garding the gate... be careful" << std::endl;
}