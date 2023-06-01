/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brisly <brisly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 08:00:29 by brisly            #+#    #+#             */
/*   Updated: 2023/06/01 14:15:58 by brisly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void){
    std::cout << "\033[90mConstructor for Contact called\033[0m" << std::endl;
}

Contact::~Contact(void){
    std::cout << "\033[90mDestructor for Contact called\033[0m" << std::endl;
}

void Contact::savecontact(std::string firstName, std::string lastName, std::string nickname, std::string phoneNumber, std::string secret)
{
    this->_firstName = firstName;
    this->_lastName = lastName;
    this->_nickname = nickname;
    this->_phoneNumber = phoneNumber;
    this->_secret = secret;
}

void Contact::showlittle(void) const
{
    std::cout << "Here is the last name: " << this->_lastName << std::endl; //just to test
}