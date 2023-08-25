/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 20:09:33 by brisly            #+#    #+#             */
/*   Updated: 2023/08/25 12:49:11 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int main()
{

    {
        std::cout << "//trying something simple that works" << std::endl;
        try{
            Bureaucrat	brc1 = Bureaucrat("Camille Honnête", 123);
            std::cout << brc1 << std::endl;
        }
        catch(const std::exception& e){
            std::cerr << e.what() << std::endl;
        }
    }

    std::cout << "\n";


    {
        std::cout << "//trying an incremention that works only" << std::endl;
        try {
            Bureaucrat	brc2 = Bureaucrat("Jean Tonique", 130);
            std::cout << brc2 << std::endl;
            brc2.incrementGrade();
            std::cout << brc2 << std::endl;
        }
        catch(const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }
    }

    std::cout << "\n";

    {
        std::cout << "//trying a decrementation that works only" << std::endl;
        try {
            Bureaucrat	brc2 = Bureaucrat("Jean Tonique", 130);
            std::cout << brc2 << std::endl;
            brc2.decrementGrade();
            std::cout << brc2 << std::endl;
        }
        catch(const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }
    }

    std::cout << "\n";

    {
        std::cout << "//trying something that works first and then we increment and fucks everything" << std::endl;
        try {
            Bureaucrat	brc2 = Bureaucrat("Jean Tonique", 1);
            std::cout << brc2 << std::endl;
            brc2.incrementGrade();
        }
        catch(const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }
    }

    std::cout << "\n";

    {
        std::cout << "//trying something that works first and then we decrement and fucks everything" << std::endl;
        try {
            Bureaucrat	brc2 = Bureaucrat("Jean Tonique", 150);
            std::cout << brc2 << std::endl;
            brc2.decrementGrade();
        }
        catch(const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }
    }

    std::cout << "\n";

    {
        std::cout << "//creating a bureaucrat with copy constructor to see that the only thing that changes is the grade and not the name :" << std::endl;
        try {
            Bureaucrat	brc2 = Bureaucrat("Jean Tonique", 33);
            Bureaucrat  brc3;
            std::cout << brc2 << std::endl;
            std::cout << brc3 << std::endl;

            brc3 = brc2;
            std::cout << brc2 << std::endl;
            std::cout << brc3 << std::endl;

        }
        catch(const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }
    }
}


// The code below is just here to understand better the try and catch concepts
// int main() {
//     int dividend, divisor, result;

//     std::cout << "Entrez le dividende : ";
//     std::cin >> dividend;

//     std::cout << "Entrez le diviseur : ";
//     std::cin >> divisor;

//     try {
//         if (divisor == 0) {
//             throw "Division par zéro est interdite !";  // Lancer une exception
//         }

//         result = dividend / divisor;
//         std::cout << "Résultat : " << result << std::endl;
//     }
//     catch (const char* errorMessage) {
//         std::cerr << "Erreur : " << errorMessage << std::endl;
//     }

//     return 0;
// }
