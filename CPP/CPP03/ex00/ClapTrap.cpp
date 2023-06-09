/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brisly <brisly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 21:32:26 by brisly            #+#    #+#             */
/*   Updated: 2023/06/09 08:42:42 by brisly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"


ClapTrap::ClapTrap(std::string name) : _name (name), _hitPoints (10), _energyPoints (10), _attackDamage (2) {
    std::cout << "\033[90mConstructor for ClapTrap " << this->_name << " called\033[0m" << std::endl;
}

ClapTrap::~ClapTrap() {
    std::cout << "\033[90mDestructor for ClapTrap " << this->_name << " called\033[0m" << std::endl;
} 

ClapTrap::ClapTrap(const ClapTrap &src) {
    std::cout << "\033[90mCopy constructor ClapTrap called\033[0m" << std::endl;
}

ClapTrap& operator=(ClapTrap const &src) {
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


void ClapTrap::attack(const std::string &target){
    if (this->_energyPoints - 1 < 0)
        std::cout << "\033[31mClapTrap " << this->_name << " seems not having any energy points left... He can't attack !\033[0m" << std::endl;
    else if (this->_hitPoints <= 0)
        std::cout << "\033[31mClapTrap " << this->_name << " seems not having any hit points left... He can't attack !\033[0m" << std::endl;
    else
    {
        std::cout << "\033[34m ˛˛ꉂ ◞•̀д•́)◞⚔◟(•̀д•́◟ ) Claptrap " << this->_name << " attacks " << target << " causing " << this->_attackDamage << " points of damage !\033[m" << std::endl; 
        this->_energyPoints -= 1;
    }
}

void ClapTrap::takeDamage(unsigned int amount){
    std::cout << "\033[34m ︵‿︵‿ヽ(°□° )ノ︵‿︵ OH OH" << this->_name << " just took " << amount << " points of damage\033[0m]" << std::endl;
    this->_hitPoints -= amount;
    if (this->_hitPoints < 0)
        std::cout << "\033[31m (×_×;） OMG ! " << this->_name << " just died after this attack !!!!\033[0m" << std::endl;
}

/*void ClapTrap::beRepaired(unsigned int amount) {


}*/