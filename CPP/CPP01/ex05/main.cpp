/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brisly <brisly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 11:59:58 by brisly            #+#    #+#             */
/*   Updated: 2023/06/06 21:52:26 by brisly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Bien comprendre les pointeurs sur fonction membre: http://sitesimons.free.fr/C++2/A9.pdf

#include "Harl.hpp"
#include <iostream>

int	main(void)
{
	Harl harl;

    std::cout << "Testing with Debug: " << std::endl;
	harl.complain("DEBUG");

    std::cout << "\nTesting with Info: " << std::endl;
	harl.complain("INFO");

    std::cout << "\nTesting with Warning: " << std::endl;
	harl.complain("WARNING");

    std::cout << "\nTesting with Error: " << std::endl;
	harl.complain("ERROR");

    std::cout << "\nTesting with invalid level: " << std::endl;
    harl.complain("pouet");
}