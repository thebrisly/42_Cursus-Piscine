/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brisly <brisly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 11:59:58 by brisly            #+#    #+#             */
/*   Updated: 2023/06/06 22:13:48 by brisly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Bien comprendre les pointeurs sur fonction membre: http://sitesimons.free.fr/C++2/A9.pdf

#include "Harl.hpp"
#include <iostream>

int	main(void)
{
	Harl harl;

    std::cout << "--- Testing with Debug: " << std::endl;
	harl.complain("DEBUG");

    std::cout << "\n--- Testing with Info: " << std::endl;
	harl.complain("INFO");

    std::cout << "\n--- Testing with Warning: " << std::endl;
	harl.complain("WARNING");

    std::cout << "\n--- Testing with Error: " << std::endl;
	harl.complain("ERROR");

    std::cout << "\n--- Testing with invalid level: " << std::endl;
    harl.complain("pouet");
}