/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brisly <brisly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 11:59:53 by brisly            #+#    #+#             */
/*   Updated: 2023/06/06 21:50:12 by brisly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <string>
#include <iostream>

 Harl::Harl(){
    std::cout << "\033[90mConstructor for Harl called\033[0m" << std::endl;
 }

Harl::~Harl(){
    std::cout << "\033[90mDestructor for Harl called\033[0m" << std::endl;
}

void Harl::complain(std::string level)
{
    int i = 0;
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    
    void (Harl::*ptr_to_memberfunction[4]) (void);
    ptr_to_memberfunction[0] = &Harl::debug;
    ptr_to_memberfunction[1] = &Harl::info;
    ptr_to_memberfunction[2] = &Harl::warning;
    ptr_to_memberfunction[3] = &Harl::error;

    while (i < 4){
        if (level == levels[i])
        {
            (this->*ptr_to_memberfunction[i])();
            break ;
        }
        i++;
    }
    if (i == 4)
        std::cout << " \033[31m😠 Wrong level of instruction ! Harl will be angry 😠\033[0m" << std::endl;
}

void Harl::debug(void){
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do !" << std::endl;
}

void Harl::info(void){
    std::cout << "I cannot believe adding extra bacon costs more money. You didnt put enough bacon in my burger ! If you did, I wouldnt be asking for more !" << std::endl;
}

void Harl::warning(void){
    std::cout << "I think I deserve to have some extra bacon for free. Ive been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error(void){
    std::cout << "This is unacceptable ! I want to speak to the manager now." << std::endl;
}