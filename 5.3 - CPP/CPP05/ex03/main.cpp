/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brisly <brisly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 22:02:43 by brisly            #+#    #+#             */
/*   Updated: 2023/08/27 18:02:19 by brisly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main()
{
    {
        std::cout << "\033[94m//Correct tests \033[0m" << std::endl;
        try {

            Intern someRandomIntern;
            AForm *form;
            AForm *copy;
            form = someRandomIntern.makeForm("robotomy request", "Bender");
            copy = form;
            if (form)
            {
                std::cout << *form << std::endl;
                std::cout << *copy << std::endl;
                delete form;
            }
        }
        catch(const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }
        std::cout << "\n";
    }

    // -------------------------------------------------
    
    {
        std::cout << "\033[94m//Wrong tests \033[0m" << std::endl;
        try {

            Intern someRandomIntern;
            AForm *form;
            form = someRandomIntern.makeForm("glouglou", "fish");
            if (form)
            {
                std::cout << *form << std::endl;
                delete form;
            }
        }
        catch(const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }
        std::cout << "\n";
    }
}