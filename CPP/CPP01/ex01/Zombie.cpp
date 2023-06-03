/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brisly <brisly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 21:35:38 by brisly            #+#    #+#             */
/*   Updated: 2023/06/03 08:11:17 by brisly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

Zombie::Zombie()
{
    std::cout << "\033[90mConstructor for Zombie called\033[0m" << std::endl;
}

Zombie::~Zombie()
{
    std::cout << "\033[90mDestructor for Zombie called\033[0m" << std::endl;
}

void Zombie::announce(void)
{
    std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

std::string Zombie::getName(void)
{
    return (this->_name);
}

void Zombie::setName(std::string new_name)
{
    this->_name = new_name;
}