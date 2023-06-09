/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brisly <brisly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 21:42:22 by brisly            #+#    #+#             */
/*   Updated: 2023/06/09 21:56:23 by brisly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
    std::cout << "\033[90mConstructor for FragTrap " << this->_name << " called\033[0m" << std::endl;
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
}

FragTrap::~FragTrap() {
    std::cout << "\033[90mDestructor for FragTrap " << this->_name << " called\033[0m" << std::endl;
} 

FragTrap::FragTrap(const FragTrap &source) : ClapTrap(source) {
    std::cout << "\033[90mCopy constructor FragTrap called\033[0m" << std::endl;
    *this = source;
}

FragTrap& FragTrap::operator=(FragTrap const &src) {
    std::cout << "\033[90mAssignment operator called\033[0m" << std::endl;
    
    ClapTrap::operator=(src);

    this->_name = src._name;
    this->_hitPoints = src._hitPoints;
    this->_energyPoints = src._energyPoints;
    this->_attackDamage = src._attackDamage;

    return (*this);
}


void FragTrap::highFivesGuys()
{
    std::cout << "\033[34m HEY YOU HUMAN... yes you. Give me a high five pls. Just a big big 5. \033[0m" << std::endl;
}