/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brisly <brisly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 14:09:21 by brisly            #+#    #+#             */
/*   Updated: 2023/08/26 22:01:14 by brisly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	{
        std::cout << "\033[94m//PresidentialPardonForm tests \033[0m" << std::endl;
        try {

			Bureaucrat						brc("Donaldo Trumpu", 5);
            Bureaucrat                      brc1("Vladimouche Poutinouche", 20);
            PresidentialPardonForm        ppf("random_target");
            PresidentialPardonForm        ppf1("second");
			std::cout << brc << std::endl;
            std::cout << ppf << std::endl;
			brc.signForm(ppf);
			brc.executeForm(ppf);
            brc1.signForm(ppf);
			brc1.executeForm(ppf);
            brc1.signForm(ppf1);
			brc1.executeForm(ppf1);
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

			Bureaucrat						brc("Goldorak", 40);
            RobotomyRequestForm        	    rrf("mars");
            Bureaucrat						brc1("Wall-E", 100);
            RobotomyRequestForm        	    rrf1("earth");
			std::cout << brc << std::endl;
            std::cout << rrf << std::endl;
			brc.signForm(rrf);
			brc.executeForm(rrf);
            brc1.signForm(rrf1);
			brc1.executeForm(rrf1);
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

			Bureaucrat						brc("Mosquito", 20);
            ShrubberyCreationForm        	scf("garden");
            Bureaucrat						brc1("Ant Man", 150);
            ShrubberyCreationForm        	scf1("roses");
			std::cout << brc << std::endl;
            std::cout << scf << std::endl;
			brc.signForm(scf);
			brc.executeForm(scf);
            brc1.signForm(scf1);
			brc1.executeForm(scf1);
            std::cout << "\n";
        }
        catch(const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }
        std::cout << "\n";
    }
}