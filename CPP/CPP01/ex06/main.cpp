/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brisly <brisly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 11:59:58 by brisly            #+#    #+#             */
/*   Updated: 2023/06/06 22:19:49 by brisly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Bien comprendre les pointeurs sur fonction membre: http://sitesimons.free.fr/C++2/A9.pdf

#include "Harl.hpp"
#include <iostream>

int	main(int argc, char **argv)
{
	Harl harl;

    if (argc == 2)
    {
        std::string level = argv[1];

        harl.complain(level);
    }
    else
        std::cout << "Wrong number of args !" << std::endl;
}