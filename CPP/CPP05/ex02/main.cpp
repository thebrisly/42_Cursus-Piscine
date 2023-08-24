/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brisly <brisly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 14:09:21 by brisly            #+#    #+#             */
/*   Updated: 2023/08/24 10:22:35 by brisly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    //Let's create a  bureaucrat that could sign the PResidentialForm but not execute it.
    Bureaucrat brc1("Georgette", 3);
    //AForm f1; //if we try to instintiate this variable we will have an error bc AForm is an abstract class !
    PresidentialPardonForm ppf("Vlad la Poutine");
    std::cout << ppf << std::endl;
    brc1.signForm(ppf);
    brc1.executeForm(ppf);

}