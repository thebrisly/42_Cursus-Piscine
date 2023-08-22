/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brisly <brisly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 20:09:33 by brisly            #+#    #+#             */
/*   Updated: 2023/08/22 22:14:37 by brisly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main() 
{
    //trying something that works
    try 
    {
        Bureaucrat	brc1 = Bureaucrat("Camille Honnête", 123);
        //Bureaucrat  brc2 = brc1; //pour montrer que le constructeur avec = fonctionne.
        //Bureaucrat brc3(brc1); //pour montrer que le constructeur par copie fonctionne
        std::cout << brc1 << std::endl;
        //std::cout << brc2 << std::endl;
        //std::cout << brc3 << std::endl;
        Form    f1 = Form("Form1", 150, 140);
        std::cout << f1 << std::endl;
        brc1.signForm(f1);
        //brc2.signForm(f1);
        std::cout << f1 << std::endl;
    }

    catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

    //trying something that doesn't work
    try 
    {
        Bureaucrat	brc1 = Bureaucrat("Camille Honnête", 123);
        std::cout << brc1 << std::endl;
        Form    f1 = Form("Form1", 110, 1);
        std::cout << f1 << std::endl;
        brc1.signForm(f1);
        std::cout << f1 << std::endl;
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