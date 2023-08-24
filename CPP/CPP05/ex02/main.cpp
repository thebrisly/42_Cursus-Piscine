/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brisly <brisly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 14:09:21 by brisly            #+#    #+#             */
/*   Updated: 2023/08/24 12:05:59 by brisly           ###   ########.fr       */
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
    Bureaucrat brc1("Georgette", 5);
    //AForm f1; //if we try to instintiate this variable we will have an error bc AForm is an abstract class !
    PresidentialPardonForm ppf("Vlad la Poutine");
    RobotomyRequestForm rrf("idk");
    ShrubberyCreationForm srf("ok");
    std::cout << ppf << std::endl;
    brc1.signForm(ppf);
    brc1.executeForm(ppf);

}