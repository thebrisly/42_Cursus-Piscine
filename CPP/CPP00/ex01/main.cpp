/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brisly <brisly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 21:26:20 by brisly            #+#    #+#             */
/*   Updated: 2023/06/02 20:41:44 by brisly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <stdlib.h>
#include <cctype>
#include <limits>
#include "Contact.hpp"
#include "PhoneBook.hpp"

// https://stackoverflow.com/questions/5131647/why-would-we-call-cin-clear-and-cin-ignore-after-reading-input 
// EXPLICATIONS pour .clear & .ignore

int ask_index(PhoneBook &directory)
{
    int index;

    while (true) 
    {
        std::cin >> index;
        std::cin.ignore(1000, '\n');

        if (std::cin.fail()) 
        {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "\033[31m(ভ_ ভ) ރ Give me a valid integer, please!\033[0m" << std::endl;
        }
        else if (index == 0)
            return (-1);
        else if (index <= 0 || index > 8 || index > directory.getfull()) 
            std::cout << "It seems that no contact exists at this index... Try again" << std::endl;
        else
            break;
    }

    return (index - 1);
}

void search(PhoneBook &directory)
{
    int index;
    
    (void) index; //pas oublier d'enlever ensuite
    std::cout << "⬇ -- Here's what's currently in the directory -- ⬇" << std::endl;
    std::cout << "-------------------------------------------------" << std::endl;
    std::cout << "|   Index   | First Name | Last Name| Nick Name |" << std::endl;
    std::cout << "-------------------------------------------------" << std::endl;
    directory.show_directory();
    if (directory.getsize() == 0) {
        std::cout << "\033[31mHO HO... Directory seems empty ! ADD someone in the PhoneBook.\033[0m\n\n";
        return ;
    }
    std::cout << "-------------------------------------------------" << std::endl;
    std::cout << "\n";
    std::cout << "> You can now select a contact by its index or quit by clcking on 0" << std::endl; // a voir pour le exit
    index = ask_index(directory);
    if (index >= 0)
        directory.show_contact(index);
}

void add(PhoneBook &directory)
{
    std::string fn, ln, nn, phone, secret;

    std::cout << " \033[95m(◡◕⏖◕)ᑐ🝐 \033[0m Hello my dear ~ I need some information now \033[95m⠁⭒*.✩.*⭒⠁\033[0m" << std::endl;
    std::cout << "> What is the first name of your contact ?" << std::endl;
    std::cin >> std::ws;
    std::getline(std::cin, fn);
    std::cout << "> Its last name ?" << std::endl;
    std::getline(std::cin, ln);
    std::cout << "> What's its nickname ?" << std::endl;
    std::getline(std::cin, nn);
    std::cout << "> What's its phone number ?" << std::endl;
    std::getline(std::cin, phone);
    std::cout << "> If you know it... tell me its deepest secret" << std::endl;
    std::getline(std::cin, secret);
    std::cout << "> Contact added successfuly :). If you wanna search it now, just type SEARCH\n" << std::endl;
    directory.add_repertory(fn, ln, nn, phone, secret);
}

int main()
{
    std::string action;
    
    PhoneBook directory(0);

    std::cout << "\e[1;1H\e[2J";
    while (1)
    {
        std::cout << "\033[95m☏  Welcome in my PhoneBook ☏\033[0m" << std::endl;
        std::cout << "> What do you wanna do ? (SEARCH, ADD or EXIT) \n" << std::endl; //voir si on le demande pas que dans certains cas
        std::cin >> action;
        std::cout << std::endl;
        if (action == "ADD")
            add(directory);
        else if (action == "SEARCH")
            search(directory);
        else if (action == "EXIT")
        {
            std::cout << "> Thank you for using the funniest PhoneBook ever \033[95m(づ ᴗ _ᴗ)づ\033[0m" << std::endl;
            break;
        }
    }
    return (0);
}