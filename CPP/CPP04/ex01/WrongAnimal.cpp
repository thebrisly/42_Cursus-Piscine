/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brisly <brisly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 08:06:39 by brisly            #+#    #+#             */
/*   Updated: 2023/06/12 08:41:05 by brisly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
    std::cout << "\033[90mConstructor for a simple WrongAnimal called\033[0m" << std::endl;
    this->type = "WrongAnimal";
}

WrongAnimal::~WrongAnimal() {
    std::cout << "\033[90mDestructor for a simple WrongAnimal called\033[0m" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &src) {
    std::cout << "\033[90mCopy constructor WrongAnimal called\033[0m" << std::endl;
    *this = src;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &src) {
    this->type = src.type;
    return (*this);
}

void WrongAnimal::makeSound() const {
    std::cout << "A WrongAnimal can make a lot of different sounds... I don't know which one to choose." << std::endl;
}

std::string WrongAnimal::getType() const {
    return (this->type);
}