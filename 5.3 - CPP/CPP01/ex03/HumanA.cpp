/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brisly <brisly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 21:37:22 by brisly            #+#    #+#             */
/*   Updated: 2023/06/04 21:21:53 by brisly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "HumanA.hpp"
#include "Weapon.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _weapon(weapon){
    std::cout << "\033[90mConstructor for HumanA called\033[0m" << std::endl;
};

HumanA::~HumanA(){
    std::cout << "\033[90mDestructor for HumanA called\033[0m" << std::endl;
}

void HumanA::attack(){
    std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
}