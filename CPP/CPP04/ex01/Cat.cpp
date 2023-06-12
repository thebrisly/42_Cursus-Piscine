/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brisly <brisly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 08:06:39 by brisly            #+#    #+#             */
/*   Updated: 2023/06/12 08:30:50 by brisly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() {
    std::cout << "\033[90mConstructor for a Cat called\033[0m" << std::endl;
    this->type = "Cat";
    this->_brain = new Brain();
}

Cat::~Cat() {
    std::cout << "\033[90mDestructor for a Cat called\033[0m" << std::endl;
    delete this->_brain;
}

Cat::Cat(const Cat &src) : Animal(src) {
    std::cout << "\033[90mCopy constructor Cat called\033[0m" << std::endl;
    *this = src;
}

Cat &Cat::operator=(const Cat &src) {
    this->type = src.type;
    this->_brain = new Brain(*(src._brain));
    return (*this);
}

void Cat::makeSound() const {
    std::cout << "MIAOUUUUUUU" << std::endl;
}

void Cat::setType(std::string newType) {
    this->type = newType;
}