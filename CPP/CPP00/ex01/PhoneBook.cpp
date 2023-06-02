/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brisly <brisly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 22:41:19 by brisly            #+#    #+#             */
/*   Updated: 2023/06/02 12:10:12 by brisly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <stdio.h>

PhoneBook::PhoneBook(int value) : _size(value), _full(value) {
    std::cout << "\033[90mConstructor for PhoneBook called\033[0m" << std::endl;
}

PhoneBook::~PhoneBook(void) {
    std::cout << "\033[90mDestructor for PhoneBook called\033[0m" << std::endl;
}

int PhoneBook::getsize(void) {
    return this->_size;
}

void PhoneBook::setsize(void) {
    if (this->getsize() == 8)
        this->_size = 0;
}

int PhoneBook::getfull(void) {
    return this->_full;
}

void PhoneBook::setfull(void) {
    if (this->getfull() == 8)
        this->_full = 7;
}

void PhoneBook::add_repertory(std::string firstName, std::string lastName, std::string nickname, std::string phoneNumber, std::string secret)
{
    this->setsize();
    this->setfull();
    this->_contacts[_size].savecontact(firstName, lastName, nickname, phoneNumber, secret, getsize());
    _size++;
    _full++;
}

void PhoneBook::show_directory() const
{
    for (int i = 0; i < _full; i++)
    {
        _contacts[i].showlittle();
    }
}

void PhoneBook::show_contact(int index) const{
    _contacts[index].showall();
}
