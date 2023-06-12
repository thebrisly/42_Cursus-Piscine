/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brisly <brisly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 08:06:39 by brisly            #+#    #+#             */
/*   Updated: 2023/06/12 08:30:50 by brisly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() {
    std::cout << "\033[90mConstructor for a Dog called\033[0m" << std::endl;
    this->type = "Dog";
}

Dog::~Dog() {
    std::cout << "\033[90mDestructor for a Dog called\033[0m" << std::endl;
}

Dog::Dog(const Dog &src) : Animal(src) {
    std::cout << "\033[90mCopy constructor Dog called\033[0m" << std::endl;
    *this = src;
}

Dog &Dog::operator=(const Dog &src) {
    this->type = src.type;
    return (*this);
}

void Dog::makeSound() const {
    std::cout << "WOOF WOOF" << std::endl;
}
