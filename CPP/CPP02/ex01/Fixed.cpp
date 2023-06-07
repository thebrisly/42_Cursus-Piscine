/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brisly <brisly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 08:58:29 by brisly            #+#    #+#             */
/*   Updated: 2023/06/07 10:18:50 by brisly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed() : _fixedNumber(0) {
    std::cout << "\033[90mConstructor for Fixed called\033[0m" << std::endl;
}

Fixed::Fixed(int const number) : _fixedNumber(number) {
    std::cout << "\033[90mInt Constructor for Fixed called\033[0m" << std::endl;
}

Fixed::Fixed(float const number) : _fixedNumber(number) {
    std::cout << "\033[90mFloat Constructor for Fixed called\033[0m" << std::endl;
}

Fixed::Fixed (Fixed &constructor) {
    std::cout << "\033[90mCopy constructor for Fixed called\033[0m" << std::endl;
    *this = constructor;
}

//In this exercise this is useless because we don't use it at all. It's just to learn how to do canonic classes
Fixed & Fixed::operator=(Fixed const &src){
    std::cout << "\033[90mAssignment operator called\033[0m" << std::endl;

    if (this != &src)
        _fixedNumber = src.getRawBits();

    return *this;
}

Fixed & Fixed::operator=(Fixed const &src){
    std::cout << "\033[90mAssignment << operator called\033[0m" << std::endl;
}

Fixed::~Fixed(){
    std::cout << "\033[90mDestructor for Fixed called\033[0m" << std::endl;
}

int Fixed::getRawBits (void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return (this->_fixedNumber);
}

void Fixed::setRawBits (int const raw) {
    this->_fixedNumber = raw;
}
