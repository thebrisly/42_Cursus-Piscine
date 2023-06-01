/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brisly <brisly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 21:26:20 by brisly            #+#    #+#             */
/*   Updated: 2023/06/01 10:49:06 by brisly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <stdlib.h>
#include "Contact.hpp"
#include "PhoneBook.hpp"


void add(){
    std::string fn, ln, nn, phone, secret;

    std::cout << "What is the first name of your contact ?" << std::endl;
    std::cin >> fn;
    std::cout << "Its last name ?" << std::endl;
    std::cin >> ln;
    std::cout << "If it has a nickname write it down. Otherwise just write "-"" << std::endl;
    std::cin >> nn;
    std::cout << "What's its phone number ?" << std::endl;
    std::cin >> phone;
    std::cout << "If you know it... tell me its deepest secret" << std::endl;
    std::cin >> secret;
    std::cout << "Contact added successfuly :). If you wanna search it now, just type SEARCH" << std::endl;
    // envoyer ces informations a la classe phonebook qui elle appellera contact :)

}

int main()
{
    std::string action;
    
    //PhoneBook directory;

    while (1)
    {
        std::cout << "Which action do you want to take next?\n" << std::endl;
        std::cin >> action;
        if (action == "ADD")
        {
            std::cout << "adding new contact...\n";
            add();
        }
        else if (action == "SEARCH")
            std::cout << "searching in repertory...\n";
            //fonction pour search
        else if (action == "EXIT"){
            std::cout << "Thank you for using the funniest PhoneBook ever (c'est faux)" << std::endl;
            exit (0);
        }
        else
            std::cout << "Only these actions are possible: ADD, SEARCH or EXIT.\n";
    }
}