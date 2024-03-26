/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 08:58:29 by brisly            #+#    #+#             */
/*   Updated: 2023/06/28 13:29:41 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

// Great video to understand Fixed Point Numbers: https://www.youtube.com/watch?v=ZMsrZvBmQnU

Fixed::Fixed() : _fixedNumber(0) {
    std::cout << "\033[90mConstructor for Fixed called\033[0m" << std::endl;
}

Fixed::Fixed(int const number) {
    std::cout << "\033[90mInt Constructor for Fixed called\033[0m" << std::endl;
	this->_fixedNumber = (number << this->_bits);
}

Fixed::Fixed(float const number) {
    std::cout << "\033[90mFloat Constructor for Fixed called\033[0m" << std::endl;
	this->_fixedNumber = static_cast<int>(roundf(number*(1 << this->_bits)));
}

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
    return (this->_fixedNumber);
}

void Fixed::setRawBits (int const raw) {
    this->_fixedNumber = raw;
}

float Fixed::toFloat (void) const {
     return (static_cast<float>(this->_fixedNumber)) / (1 << this->_bits); //comme si on divise par 256
}

int Fixed::toInt (void) const {
    return (static_cast<int>((this->_fixedNumber) >> this->_bits));
}

/* Comparison operators */
bool    Fixed::operator>(const Fixed &fixed) const
{
	return (this->toFloat() > fixed.toFloat());
}

bool    Fixed::operator<(const Fixed &fixed) const {
	return (this->toFloat() < fixed.toFloat());
}

bool    Fixed::operator>=(const Fixed &fixed) const{
	return (this->toFloat() >= fixed.toFloat());
}

bool    Fixed::operator<=(const Fixed &fixed) const{
	return (this->toFloat() <= fixed.toFloat());
}

bool    Fixed::operator==(const Fixed &fixed) const{
	return (this->toFloat()== fixed.toFloat());
}

bool    Fixed::operator!=(const Fixed &fixed) const{
	return (this->toFloat() != fixed.toFloat());
}

/* Arithmetic operators */
Fixed   Fixed::operator+(const Fixed &fixed) const{
	return (this->toFloat() + fixed.toFloat());
}

Fixed   Fixed::operator-(const Fixed &fixed) const{
	return (this->toFloat() - fixed.toFloat());
}

Fixed   Fixed::operator*(const Fixed &fixed) const{
	return (this->toFloat() * fixed.toFloat());
}

Fixed   Fixed::operator/(const Fixed &fixed) const{
	return (this->toFloat() / fixed.toFloat());
}


/* Incrementation operators */
Fixed&  Fixed::operator++(void) // Prefix increment operator -> saw that on google
{
	this->_fixedNumber++;
	return (*this);
}

Fixed   Fixed::operator++(int) //Postfix increment operator -> saw that on google
{
	Fixed	temp(*this);

	_fixedNumber++;
	return (temp);
}

Fixed&  Fixed::operator--(void) // Prefix increment operator -> saw that on google
{
	this->_fixedNumber--;
	return (*this);
}

Fixed   Fixed::operator--(int) //Postfix increment operator -> saw that on google
{
	Fixed	temp(*this);

	_fixedNumber++;
	return (temp);
}


/* MIN & MAX */
Fixed &Fixed::min(Fixed &fixed1, Fixed &fixed2){
	if (fixed1 > fixed2)
		return (fixed2);
	else
		return (fixed1);
}

const Fixed &Fixed::min(const Fixed &fixed1, const Fixed &fixed2){
	if (fixed1 > fixed2)
		return (fixed2);
	else
		return (fixed1);
}

Fixed &Fixed::max(Fixed &fixed1, Fixed &fixed2){
	if (fixed1 > fixed2)
		return (fixed1);
	else
		return (fixed2);
}

const Fixed &Fixed::max(const Fixed &fixed1, const Fixed &fixed2){
	if (fixed1 > fixed2)
		return (fixed1);
	else
		return (fixed2);
}

/* << for */
std::ostream & operator<<(std::ostream &os, const Fixed &src) {
    std::cout << "\033[90mAssignment << operator called \033[0m";

    os << src.toFloat();
    return (os);
}
