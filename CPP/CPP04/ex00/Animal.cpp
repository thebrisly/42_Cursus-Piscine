/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brisly <brisly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 08:06:39 by brisly            #+#    #+#             */
/*   Updated: 2023/06/12 09:01:59 by brisly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() {
    std::cout << "\033[90mConstructor for a simple animal called\033[0m" << std::endl;
    this->type = "Animal";
}

Animal::~Animal() {
    std::cout << "\033[90mDestructor for a simple animal called\033[0m" << std::endl;
}

Animal::Animal(const Animal &src) {
    std::cout << "\033[90mCopy constructor Animal called\033[0m" << std::endl;
    *this = src;
}

Animal &Animal::operator=(const Animal &src) {
    this->type = src.type;
    return (*this);
}

void Animal::makeSound() const {
    std::cout << "An animal can make a lot of different sounds... I don't know which one to choose." << std::endl;
}

std::string Animal::getType() const {
    return (this->type);
}