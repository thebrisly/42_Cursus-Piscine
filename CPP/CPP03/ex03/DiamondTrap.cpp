/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brisly <brisly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 09:38:13 by brisly            #+#    #+#             */
/*   Updated: 2023/06/10 10:25:56 by brisly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) {
    std::cout << "Default constructor for DiamondTrap " << this->_name << " called" << std::endl;
    ClapTrap::_name = name + "_clap_name";
    this->_name = name;
    this->_hitPoints = FragTrap::_hitPoints;
    this->_energyPoints = ScavTrap::_energyPoints;
    this->_attackDamage = FragTrap::_attackDamage;
}

DiamondTrap::DiamondTrap(DiamondTrap const &src){
    std::cout << "Copy constructor for DiamondTrap " << this->_name << " called" << std::endl;
    this->_name = src.ClapTrap::_name;
    this->_hitPoints = src.FragTrap::_hitPoints;
    this->_energyPoints = src.ScavTrap::_energyPoints;
    this->_attackDamage = src.FragTrap::_attackDamage;
}

DiamondTrap& DiamondTrap::operator=(DiamondTrap const &src) {
    this->_name = src.ClapTrap::_name;
    this->_hitPoints = src.FragTrap::_hitPoints;
    this->_energyPoints = src.ScavTrap::_energyPoints;
    this->_attackDamage = src.FragTrap::_attackDamage;
    return (*this);
}

DiamondTrap::~DiamondTrap(){
    std::cout << "Default destructor for DiamondTrap " << this->_name << " called" << std::endl;
}

void DiamondTrap::attack(const std::string &target) const
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI(void) const {
    std::cout << "Sorry but i'm a bit confused. Who the fuck am I ?? Am I ";
    std::cout << this->_name << " (DiamondTrap) or " << ClapTrap::_name << " (ClapTrap) ?" << std::endl;
}