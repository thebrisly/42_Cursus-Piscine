/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brisly <brisly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 20:09:33 by brisly            #+#    #+#             */
/*   Updated: 2023/08/20 21:51:28 by brisly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int main() 
{

    //trying something that works
    try 
    {
        Bureaucrat	brc1 = Bureaucrat("Camille Honnête", 123);
        std::cout << brc1 << std::endl;
    }

    catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

    //trying something that works first and then we decrement and fucks everything
    try 
    {
        Bureaucrat	brc2 = Bureaucrat("Jean Tonique", 150);
		std::cout << brc2 << std::endl;
        brc2.decrementGrade(4);
        //std::cout << brc2 << std::endl;
    }

    catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}


// The code below is just here to understand better the try and catch concepts
/*int main() {
    int dividend, divisor, result;

    std::cout << "Entrez le dividende : ";
    std::cin >> dividend;

    std::cout << "Entrez le diviseur : ";
    std::cin >> divisor;

    try {
        if (divisor == 0) {
            throw "Division par zéro est interdite !";  // Lancer une exception
        }

        result = dividend / divisor;
        std::cout << "Résultat : " << result << std::endl;
    }
    catch (const char* errorMessage) {
        std::cerr << "Erreur : " << errorMessage << std::endl;
    }

    return 0;
}*/