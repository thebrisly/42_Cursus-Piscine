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

Dog::Dog() : Animal() {
    std::cout << "\033[90mConstructor for a Dog called\033[0m" << std::endl;
    this->type = "Dog";
    this->_brain = new Brain();
}

Dog::~Dog() {
    std::cout << "\033[90mDestructor for a Dog called\033[0m" << std::endl;
    delete this->_brain;
}

Dog::Dog(const Dog &src) : Animal(src) {
    std::cout << "\033[90mCopy constructor Dog called\033[0m" << std::endl;
    this->_brain = new Brain(*(src._brain)); // Copy the Brain
}

Dog &Dog::operator=(const Dog &src) {
    if (this != &src) {
        Animal::operator=(src); // Call the base class's operator=
        delete _brain; // Release existing brain resources
        _brain = new Brain(*(src._brain)); // Copy the Brain
    }
    return (*this);
}

void Dog::makeSound() const {
    std::cout << "WOOF WOOF" << std::endl;
}

void Dog::setType(std::string newType) {
    this->type = newType;
}

Brain* Dog::getBrain() const {
        return _brain;
    }
