/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brisly <brisly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 21:32:26 by brisly            #+#    #+#             */
/*   Updated: 2023/06/09 15:14:49 by brisly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"


ClapTrap::ClapTrap(std::string name) : _name (name), _hitPoints (5), _energyPoints (10), _attackDamage (0) {
    std::cout << "\033[90mConstructor for ClapTrap " << this->_name << " called\033[0m" << std::endl;
}

ClapTrap::~ClapTrap() {
    std::cout << "\033[90mDestructor for ClapTrap " << this->_name << " called\033[0m" << std::endl;
} 

ClapTrap::ClapTrap(const ClapTrap &source) {
    std::cout << "\033[90mCopy constructor ClapTrap called\033[0m" << std::endl;
    *this = source;
}

ClapTrap& ClapTrap::operator=(ClapTrap const &src) {
    std::cout << "\033[90mAssignment operator called\033[0m" << std::endl;

    this->_name = src._name;
    this->_hitPoints = src._hitPoints;
    this->_energyPoints = src._energyPoints;
    this->_attackDamage = src._attackDamage;

    return (*this);
}

std::string ClapTrap::getName() {
    return (this->_name);
}

int ClapTrap::getDamage(){
    return (this->_attackDamage);
}

int ClapTrap::getEnergy(){
    return (this->_energyPoints);
}

int ClapTrap::getHit(){
    return (this->_hitPoints);
}


void ClapTrap::attack(const std::string &target){
    if (this->_energyPoints - 1 < 0)
    {
        std::cout << "\033[31mClapTrap " << this->_name << " seems not having any energy points left... He can't attack !\033[0m" << std::endl;
        this->_attackDamage = 0;
    }
    else if (this->_hitPoints <= 0)
    {
        std::cout << "\033[31mClapTrap " << this->_name << " seems dead... Obviously, he can't attack !\033[0m" << std::endl;
        this->_attackDamage = 0;
    }
    else
    {
        std::cout << "\033[34m Claptrap " << this->_name << " attacks " << target << " causing " << this->_attackDamage << " points of damage !  ( ◞•̀д•́)◞⚔◟(•̀д•́◟ )\033[m" << std::endl; 
        this->_energyPoints -= 1;
        std::cout << "\033[36m                  Remaining energy points for " << this->_name << " : " << this->_energyPoints << "\033[0m" << std::endl;
    }
}

void ClapTrap::takeDamage(unsigned int amount){
    if (this->_hitPoints > 0 && amount > 0)
    {
        std::cout << "\033[34m ︵‿︵‿ヽ(°□° )ノ︵‿︵ OH OH " << this->_name << " just took " << amount << " points of damage\033[0m" << std::endl;
        this->_hitPoints -= amount;
        if (this->_hitPoints < 0)
            std::cout << "\033[31m (×_×;） OMG ! " << this->_name << " just died after this attack !!!!\033[0m" << std::endl;
        else
            std::cout << "\033[36m                  Remaining hit points for " << this->_name << " : " << this->_hitPoints << "\033[0m" << std::endl;
    }
    else if (this->_hitPoints <= 0)
        std::cout << "\033[31mYou can't kill someone that is already dead. bruh.\033[0m" << std::endl;
    else if (amount <= 0)
        std::cout << "\033[31mThe person that tried to kill " << this->_name << "is less powerful... he can't attack.\033[0m" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (this->_energyPoints - 1 < 0)
        std::cout << "\033[31mClapTrap " << this->_name << " seems not having any energy points left... He can't repair himself !\033[0m" << std::endl;
    else {
        std::cout << "\033[34m Our dear friend " << this->_name << " has found a magic potion that brought him " << amount << " of hit points..." << std::endl;
        this->_hitPoints += amount;
        this->_energyPoints -= 1;
        std::cout << "\033[36m                  Remaining hit points for " << this->_name << " : " << this->_hitPoints << "\033[0m" << std::endl;
    }
}

void ClapTrap::status()
{
    std::cout << "\n ----- Fighter Status -------\n" << std::endl;
    std::cout << "- Name : " << this->_name << std::endl;
    std::cout << "- Hit points: " << this->_hitPoints << std::endl;
    std::cout << "- Energy points: " << this->_energyPoints << std::endl;
}