/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brisly <brisly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 22:41:19 by brisly            #+#    #+#             */
/*   Updated: 2023/06/01 14:15:23 by brisly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <stdio.h>

PhoneBook::PhoneBook(int value) : _size(value) {
    std::cout << "\033[90mConstructor for PhoneBook called\033[0m" << std::endl;
}

PhoneBook::~PhoneBook(void){
    std::cout << "\033[90mDestructor for PhoneBook called\033[0m" << std::endl;
}

void PhoneBook::add_repertory(std::string firstName, std::string lastName, std::string nickname, std::string phoneNumber, std::string secret)
{
    //if (size == 8)
    //    size == 0;
    this->_contacts[_size].savecontact(firstName, lastName, nickname, phoneNumber, secret);
    _size++;
}

void PhoneBook::show_directory() const
{
    //std::cout << "⬇ --- Here's what's currently in the directory --- ⬇" << std::endl;
    for (int i = 0; i < _size; i++)
    {
        _contacts[i].showlittle();
    }
}
