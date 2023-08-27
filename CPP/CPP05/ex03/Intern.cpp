/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brisly <brisly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 22:27:29 by brisly            #+#    #+#             */
/*   Updated: 2023/08/27 09:58:55 by brisly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
    std::cout << "\033[90mConstructor for Intern called\033[0m" << std::endl;
}

Intern::~Intern()
{
    std::cout << "\033[90mDestructor for Intern called\033[0m" << std::endl;
}

Intern::Intern(const Intern &src)
{
    std::cout << "\033[90mCopy constructor for Intern called\033[0m" << std::endl;
    *this = src;
}

Intern &Intern::operator=(const Intern &src)
{
    return (*this);
}

AForm *Intern::makeSCF(std::string target) const{
    return (new ShrubberyCreationForm(target));
}

AForm *Intern::makeRRF(std::string target) const{
    return (new RobotomyRequestForm(target));
}

AForm *Intern::makePPF(std::string target) const{
    return (new PresidentialPardonForm(target));
}

AForm* Intern::makeForm(std::string form_name, std::string target) const
{
    typedef AForm* (Intern::*PtrFunctions)(std::string) const;

    PtrFunctions ListPtrFunctions[] = {&Intern::makeSCF, &Intern::makePPF, &Intern::makeRRF};
}