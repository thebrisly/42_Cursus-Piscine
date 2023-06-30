/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 08:58:29 by brisly            #+#    #+#             */
/*   Updated: 2023/06/28 13:29:38 by lfabbian         ###   ########.fr       */
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
	this->_fixedNumber = (number << this->_bits);
}


//NEW IN THIS EXERCISE
Fixed::Fixed(float const number) {
    std::cout << "\033[90mFloat Constructor for Fixed called\033[0m" << std::endl;
	this->_fixedNumber = static_cast<int>(roundf(number*(1 << this->_bits)));
}
/* ------------------------------------------- */

// Copy constructor
Fixed::Fixed (const Fixed &constructor) {
    std::cout << "\033[90mCopy constructor for Fixed called\033[0m" << std::endl;
    *this = constructor;
}

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
