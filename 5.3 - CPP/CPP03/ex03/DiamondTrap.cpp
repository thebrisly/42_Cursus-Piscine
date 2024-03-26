/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 09:38:13 by brisly            #+#    #+#             */
/*   Updated: 2023/06/30 11:03:13 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name) {
    std::cout << "Default constructor for DiamondTrap " << this->_name << " called" << std::endl;
    this->_name = name;
    this->_hitPoints = FragTrap::_hitPoints;
    this->_energyPoints = ScavTrap::_energyPoints;
    this->_attackDamage = FragTrap::_attackDamage;
}

DiamondTrap::DiamondTrap(DiamondTrap const &src) : ClapTrap(src), ScavTrap(src), FragTrap(src) {
    std::cout << "Copy constructor for DiamondTrap " << this->_name << " called" << std::endl;
    this->_name = src._name;
    this->_name = src.ClapTrap::_name;
    this->_hitPoints = src.FragTrap::_hitPoints;
    this->_energyPoints = src.ScavTrap::_energyPoints;
    this->_attackDamage = src.FragTrap::_attackDamage;
}

DiamondTrap& DiamondTrap::operator=(DiamondTrap const &src) {
    this->_name = src._name;
    this->_name = src.ClapTrap::_name;
    this->_hitPoints = src.FragTrap::_hitPoints;
    this->_energyPoints = src.ScavTrap::_energyPoints;
    this->_attackDamage = src.FragTrap::_attackDamage;
    return (*this);
}

DiamondTrap::~DiamondTrap(){
    std::cout << "Default destructor for DiamondTrap " << this->_name << " called" << std::endl;
}

void DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI(void) const {
    std::cout << "Sorry but i'm a bit confused. Who the fuck am I ?? Am I ";
    std::cout << this->_name << " (DiamondTrap) or " << ClapTrap::_name << " (ClapTrap) ?" << std::endl;
}
