/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brisly <brisly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 15:31:32 by brisly            #+#    #+#             */
/*   Updated: 2023/08/24 12:01:45 by brisly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target) 
{
    std::cout << "\033[90mConstructor for PresidentialPardonForm called\033[0m" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "\033[90mDestructor for PresidentialPardonForm called\033[0m" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src) : AForm(src.getName(), src.get_sGrade(), src.get_eGrade())
{
    std::cout << "\033[90mCopy constructor for PresidentialPardonForm called\033[0m" << std::endl;
    *this = src;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &src)
{
    this->setSigned(src.get_Signed());
    this->_target = src.getTarget();
    return (*this);
}

const std::string   PresidentialPardonForm::getTarget() const 
{
    return (this->_target);
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    if (this->get_Signed() == 0)
        throw (AForm::NotSignedException());
    if (executor.getGrade() > this->get_eGrade())
        throw (AForm::GradeTooLowException());
    std::cout << this->getTarget() << " has been excused by Zaphod Bleebrox (don't ask me who the fuck is this)" << std::endl;
}