/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brisly <brisly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 08:58:29 by brisly            #+#    #+#             */
/*   Updated: 2023/06/07 14:35:48 by brisly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

// Great video to understand Fixed Point Numbers: https://www.youtube.com/watch?v=ZMsrZvBmQnU

Fixed::Fixed() : _fixedNumber(0) {
    std::cout << "\033[90mConstructor for Fixed called\033[0m" << std::endl;
}

// https://stackoverflow.com/questions/67517939/how-to-connect-the-theory-of-fixed-point-numbers-and-its-practical-implementatio
/* ------------------------------------------- */
//NEW IN THIS EXERCISE
Fixed::Fixed(int const number) {
    std::cout << "\033[90mInt Constructor for Fixed called\033[0m" << std::endl;
    
    int result = number;
    int i = this->_bits;

    while (i > 0){
        result *=2;
        i--;
    }
    this->_fixedNumber = result;
}


//NEW IN THIS EXERCISE
Fixed::Fixed(float const number) {
    std::cout << "\033[90mFloat Constructor for Fixed called\033[0m" << std::endl;
    
    float result = number;
    int i = this->_bits;

    while (i > 0){
        result *=2;
        i--;
    }
    this->_fixedNumber = result;
}
/* ------------------------------------------- */

// Copy constructor
Fixed::Fixed (const Fixed &constructor) {
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

/* ------------------------------------------- */
//NEW IN THIS EXERCISE
// found this

float Fixed::toFloat (void) const {
     return (static_cast<float>(this->_fixedNumber) / (1 << this->_bits));
}

int Fixed::toInt (void) const {
    return (static_cast<int>(this->_fixedNumber) >> this->_bits);
}

// if we don't create this overloading operator, we can't display Fixed Numbers (from class Fixed)
std::ostream & operator<<(std::ostream &os, const Fixed &src) {
    std::cout << "\033[90mAssignment << operator called \033[0m";

    os << src.toFloat();
    return (os);
}