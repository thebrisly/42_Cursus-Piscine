/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brisly <brisly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 21:37:38 by brisly            #+#    #+#             */
/*   Updated: 2023/06/27 14:03:54 by brisly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name) {
    std::cout << "\033[90mConstructor for HumanB called\033[0m" << std::endl;
    this->_weapon = 0;
};

HumanB::~HumanB(){
    std::cout << "\033[90mDestructor for HumanB called\033[0m" << std::endl;
}

void HumanB::attack(){
    if (this->_weapon)
        std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
    else
        std::cout << this->_name << " tried to attack but without succes (and any weapon neither...)" << std::endl;
}

void HumanB::setWeapon(Weapon &weapon){
    this->_weapon = &weapon;
}