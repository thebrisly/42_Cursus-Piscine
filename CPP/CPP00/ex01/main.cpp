/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brisly <brisly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 21:26:20 by brisly            #+#    #+#             */
/*   Updated: 2023/06/01 14:24:44 by brisly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <stdlib.h>
#include "Contact.hpp"
#include "PhoneBook.hpp"

void search(PhoneBook &directory)
{
    std::cout << "⬇ --- Here's what's currently in the directory --- ⬇" << std::endl;
    directory.show_directory();
    std::cout << "\n";
}

void add(PhoneBook &directory){
    std::string fn, ln, nn, phone, secret;

    std::cout << " ⋆⸜(˙꒳​˙ ) Thank you for using the funniest PhoneBook ever. I need some information now...\n";
    std::cout << "1. What is the first name of your contact ?" << std::endl;
    std::cin >> fn;
    std::cout << "2. Its last name " << std::endl;
    std::cin >> ln;
    std::cout << "3. What's its nickname ?" << std::endl;
    std::cin >> nn;
    std::cout << "4. What's its phone number ?" << std::endl;
    std::cin >> phone;
    std::cout << "5. If you know it... tell me its deepest secret" << std::endl;
    std::cin >> secret;
    std::cout << "Contact added successfuly :). If you wanna search it now, just type SEARCH" << std::endl;
    directory.add_repertory(fn, ln, nn, phone, secret);
}

int main()
{
    std::string action;
    
    PhoneBook directory(0);

    std::cout << "☏  Welcome in my PhoneBook ☏" << std::endl;
    while (1)
    {
        std::cout << "What do you wanna do ? (SEARCH, ADD or EXIT) \n" << std::endl; //voir si on le demande pas que dans certains cas
        std::cin >> action;
        if (action == "ADD")
            add(directory);
        else if (action == "SEARCH")
            search(directory);
        else if (action == "EXIT"){
            std::cout << "Thank you for using the funniest PhoneBook ever \033[95m(づ ᴗ _ᴗ)づ\033[0m" << std::endl;
            break ;
            //exit (0);
        }
        //else
        //    std::cout << "Only these actions are possible: ADD, SEARCH or EXIT.\n";
    }
    return (0);
}