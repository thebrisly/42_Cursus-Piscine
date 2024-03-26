/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 20:09:33 by brisly            #+#    #+#             */
/*   Updated: 2023/08/25 13:29:45 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{
    std::cout << " \033[94m ------------------------------------- \n\033[0m";
    {
        std::cout << "\033[94m//trying something simple that works\033[0m" << std::endl;
        try {
            Bureaucrat	brc1 = Bureaucrat("Camille Honnête", 123);
            std::cout << brc1 << std::endl;
            Form        f1 = Form("Form1", 150, 140);
            std::cout << f1 << std::endl;
            std::cout << "\n";

            brc1.signForm(f1);
            std::cout << f1 << std::endl;
        }
        catch(const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }
        std::cout << "\n";
    }

    std::cout << " \033[94m ------------------------------------- \n\033[0m";
    {
        std::cout << "\033[94m//trying to sign a Form with the wrong grade (too low)\033[0m" << std::endl;
        try {
            Bureaucrat	brc1 = Bureaucrat("Camille Honnête", 123);
            std::cout << brc1 << std::endl;
            Form        f1 = Form("Form1", 10, 140);
            std::cout << f1 << std::endl;
            std::cout << "\n";

            brc1.signForm(f1);
            std::cout << f1 << std::endl;
        }
        catch(const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }
        std::cout << "\n";
    }

    std::cout << " \033[94m ------------------------------------- \n\033[0m";
    {
        std::cout << "\033[94m//trying to create a Form with grade to sign too high \033[0m" << std::endl;
        try {
            Form        f1 = Form("Form1", 0, 140);
            std::cout << f1 << std::endl;
            std::cout << "\n";
        }
        catch(const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }
        std::cout << "\n";
    }

    std::cout << " \033[94m ------------------------------------- \n\033[0m";
    {
        std::cout << "\033[94m//trying to create a Form with grade too sign low \033[0m" << std::endl;
        try {
            Form        f1 = Form("Form1", 151, 140);
            std::cout << f1 << std::endl;
            std::cout << "\n";
        }
        catch(const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }
        std::cout << "\n";
    }

    std::cout << " \033[94m ------------------------------------- \n\033[0m";
    {
        std::cout << "\033[94m//trying to create a Form with grade to execute too high \033[0m" << std::endl;
        try {
            Form        f1 = Form("Form1", 5, 0);
            std::cout << f1 << std::endl;
            std::cout << "\n";
        }
        catch(const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }
        std::cout << "\n";
    }

    std::cout << " \033[94m ------------------------------------- \n\033[0m";
    {
        std::cout << "\033[94m//trying to create a Form with grade to execute too low \033[0m" << std::endl;
        try {
            Form        f1 = Form("Form1", 4, 151);
            std::cout << f1 << std::endl;
            std::cout << "\n";
        }
        catch(const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }
        std::cout << "\n";
    }

    std::cout << " \033[94m ------------------------------------- \n\033[0m";
    {
        std::cout << "\033[94m//trying to create a form with copy constructor and see the changes :) \033[0m" << std::endl;
        try {
            Form        f1 = Form("Form1", 2, 3);
            Form        f2;
            std::cout << f1 << std::endl;
            std::cout << f2 << std::endl;

            f2 = f1;
            std::cout << f2 << std::endl;
            std::cout << "\n";
        }
        catch(const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }
        std::cout << "\n";
    }

    std::cout << " \033[94m ------------------------------------- \n\033[0m";
    {
        std::cout << "\033[94m//trying to sign a form already signed \033[0m" << std::endl;
        try {
            Bureaucrat	brc1 = Bureaucrat("Camille Honnête", 123);
            Form        f1 = Form("Form1", 130, 140);
            brc1.signForm(f1);
            std::cout << f1 << std::endl;
            brc1.signForm(f1);
        }
        catch(const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }
        std::cout << "\n";
    }

}
