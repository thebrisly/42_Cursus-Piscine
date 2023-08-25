/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brisly <brisly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 14:09:21 by brisly            #+#    #+#             */
/*   Updated: 2023/08/24 22:04:40 by brisly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
    //Let's create a  bureaucrat that could sign the PResidentialForm but not execute it.
    Bureaucrat brc1("Georgette", 45);
    //AForm f1; //if we try to instintiate this variable we will have an error bc AForm is an abstract class !
    //PresidentialPardonForm ppf("Vlad la Poutine");
    //RobotomyRequestForm rrf("idk");
    ShrubberyCreationForm srf("ok");
    std::cout << srf << std::endl;
    //brc1.signForm(ppf);
    //brc1.executeForm(ppf);
    //brc1.signForm(rrf);
    //brc1.executeForm(rrf);
    brc1.signForm(srf);
    brc1.executeForm(srf);

	{
        std::cout << "\033[94m//PresidentialPardonForm tests \033[0m" << std::endl;
        try {

			Bureaucrat						brc("Donaldo Trumpu", 20, 1);
            PresidentialPardonForm        ppf("random_target");
			std::cout << brc << std::endl;
            std::cout << ppf << std::endl;
			brc.signForm(ppf);
			brc.executeForm(ppf);
            std::cout << "\n";
        }
        catch(const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }
        std::cout << "\n";
    }

    std::cout << " \033[94m ------------------------------------- \n\033[0m";

	{
        std::cout << "\033[94m//RobotomyRequestForm tests \033[0m" << std::endl;
        try {

			Bureaucrat						brc("Goldorak", 75, 69);
            RobotomyRequestForm        	rrf("random_target");
			std::cout << brc << std::endl;
            std::cout << rrf << std::endl;
			brc.signForm(rrf);
			brc.executeForm(rrf);
            std::cout << "\n";
        }
        catch(const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }
        std::cout << "\n";
    }

	std::cout << " \033[94m ------------------------------------- \n\033[0m";

	{
        std::cout << "\033[94m//ShrubberyCreationForm tests \033[0m" << std::endl;
        try {

			Bureaucrat						brc("Goldorak", 34, 20);
            ShrubberyCreationForm        	scf("random_target");
			std::cout << brc << std::endl;
            std::cout << scf << std::endl;
			brc.signForm(scf);
			brc.executeForm(scf);
            std::cout << "\n";
        }
        catch(const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }
        std::cout << "\n";
    }
}