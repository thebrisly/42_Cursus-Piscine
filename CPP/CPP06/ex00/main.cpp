/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brisly <brisly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 19:32:24 by brisly            #+#    #+#             */
/*   Updated: 2023/08/27 21:26:15 by brisly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

/* A member function declared as static can be called without having to instantiate the class.
It can only use static member variables and functions, i.e. those which exist outside any instance.*/

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        std::string arg = argv[1];
        ScalarConverter::convert(arg);
    }
    else
        std::cerr << "2 args only needed : ./convert and a char, float, int or double" << std::endl; 
}