/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 08:58:29 by brisly            #+#    #+#             */
/*   Updated: 2023/06/28 13:30:24 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed() : _fixedNumber(0) {
    std::cout << "\033[90mConstructor for Fixed called\033[0m" << std::endl;
}

//Did it here but I just saw that we will do it in the next exercise lol
/*Fixed::Fixed(int number) : _fixedNumber(number) {
    std::cout << "\033[90mConstructor 2 for Fixed called\033[0m" << std::endl;
}*/

Fixed::Fixed (Fixed &constructor) {
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
