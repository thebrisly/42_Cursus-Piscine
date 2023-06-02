/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brisly <brisly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 21:35:38 by brisly            #+#    #+#             */
/*   Updated: 2023/06/02 22:22:05 by brisly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

Zombie::Zombie(std::string name) : _name(name)
{
    std::cout << "\033[90mConstructor for " << this->_name << " Zombie called\033[0m" << std::endl;
}

Zombie::~Zombie()
{
    std::cout << "\033[90mDestructor for " << this->_name << " called\033[0m" << std::endl;
}

void Zombie::announce(void)
{
    std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}