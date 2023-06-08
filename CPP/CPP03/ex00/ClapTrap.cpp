/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brisly <brisly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 21:32:26 by brisly            #+#    #+#             */
/*   Updated: 2023/06/08 21:54:02 by brisly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"


ClapTrap::ClapTrap(std::string name) : _name (name), _hitPoints (10), _energyPoints (10), _attackDamage (0) {
    std::cout << "Constructor for ClapTrap " << this->_name << " called" << std::endl;
}

ClapTrap::~ClapTrap() {
    std::cout << "Destructor for ClapTrap " << this->_name << " called" << std::endl;
} 

ClapTrap::ClapTrap(const ClapTrap &src) {
    std::cout << "Copy constructor ClapTrap called" << std::endl;
}

void ClapTrap::attack(const std::string &target){
    std::cout << "Claptrap " << this->_name << " attacks " << target->_name << " causing " << this->_attackDamage << " points of damage !" << std::endl; 
    this->_energyPoints -= 1;
    target.takeDamage(this->_attackDamage);
}

void ClapTrap::takeDamage(unsigned int amount){
    std::cout << "";
}

void ClapTrap::beRepaired(unsigned int amount) {

}