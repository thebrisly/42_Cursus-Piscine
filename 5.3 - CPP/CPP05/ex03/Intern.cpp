/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brisly <brisly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 22:27:29 by brisly            #+#    #+#             */
/*   Updated: 2023/08/27 17:51:08 by brisly           ###   ########.fr       */
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
    (void) src; //just to shut up the warnings
    std::cout << "\033[90mCopy constructor for Intern called\033[0m" << std::endl;
    *this = src;
}

Intern &Intern::operator=(const Intern &src)
{
    (void) src; //just to shut up the warnings
    return (*this);
}

AForm *Intern::makeSCF(std::string target) const{
    return new ShrubberyCreationForm(target);
}

AForm *Intern::makeRRF(std::string target) const{
    return new RobotomyRequestForm(target);
}

AForm *Intern::makePPF(std::string target) const{
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(std::string form_name, std::string target) const
{
    AForm* Newform = NULL;

    typedef AForm* (Intern::*PtrFunctions)(std::string) const;

    PtrFunctions ListPtrFunctions[] = {&Intern::makeSCF, &Intern::makePPF, &Intern::makeRRF};
    std::string names[] = {"shrubbery creation", "presidential pardon", "robotomy request"};

    for (int i = 0; i < 3; i++)
    {
        if (form_name == names[i])
        {
            std::cout << "Intern creates" << form_name << std::endl;
            Newform = (this->*ListPtrFunctions[i])(target);
        }
    }
    if (!Newform)
        throw(Intern::WrongFormException());
    return (Newform);
}