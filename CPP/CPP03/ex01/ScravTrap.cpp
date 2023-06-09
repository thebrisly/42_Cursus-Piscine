/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScravTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brisly <brisly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 15:08:12 by brisly            #+#    #+#             */
/*   Updated: 2023/06/09 15:26:34 by brisly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScravTrap.hpp"

ScravTrap::ScravTrap(std::string name) : this->getName() (name), this->getHit() (100), this->getEnergy() (50), this->getDamage() (20) {
    std::cout << "\033[90mConstructor for ScravTrap " << this->_name << " called\033[0m" << std::endl;
}

ScravTrap::~ScravTrap() {
    std::cout << "\033[90mDestructor for ScravTrap " << this->getName() << " called\033[0m" << std::endl;
} 

ScravTrap::ScravTrap(const ScravTrap &source) {
    std::cout << "\033[90mCopy constructor ScravTrap called\033[0m" << std::endl;
    *this = source;
}

ScravTrap& ScravTrap::operator=(ScravTrap const &src) {
    std::cout << "\033[90mAssignment operator called\033[0m" << std::endl;

    this->getName() = src.getName();
    this->getHit() = src.getHit();
    this->getEnergy() = src.getEnergy();
    this->getDamage() = src.getDamage();

    return (*this);
}