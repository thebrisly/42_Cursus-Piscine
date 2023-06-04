/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brisly <brisly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 21:36:58 by brisly            #+#    #+#             */
/*   Updated: 2023/06/04 21:34:15 by brisly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include <string>
#include <iostream>

Weapon::Weapon(std::string weaponType) : _weapon(weaponType) {
    std::cout << "\033[90mConstructor for Weapon called\033[0m" << std::endl;
}

Weapon::~Weapon(){
    std::cout << "\033[90mDestructor for Weapon called\033[0m" << std::endl;
}

std::string const &Weapon::getType(){
    return (this->_weapon);
}


void Weapon::setType(std::string weaponType){
    this->_weapon = weaponType;
}