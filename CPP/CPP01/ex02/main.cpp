/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brisly <brisly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 20:45:48 by brisly            #+#    #+#             */
/*   Updated: 2023/06/03 21:03:36 by brisly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int main()
{
    std::string     test = "HI THIS IS BRAIN";
    std::string     *stringPTR = &test;
    std::string     &stringREF = test; //je ne pourrai jamais changer ce sur quoi cette reference pointe

    std::cout << "Address of test: " << &test << std::endl;
    std::cout << "Address of stringPTR: " << stringPTR << std::endl;
    std::cout << "Address of stringREF; " << &stringREF << std::endl;

    std::cout << "\n-------------------------------\n" << std::endl;

    std::cout << "Value of test: " << test << std::endl;
    std::cout << "Value of stringPTR: " << *stringPTR << std::endl;
    std::cout << "Value of stringREF: " << stringREF << std::endl;

}