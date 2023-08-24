/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brisly <brisly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 12:02:08 by brisly            #+#    #+#             */
/*   Updated: 2023/08/24 12:07:16 by brisly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target) 
{
    std::cout << "\033[90mConstructor for ShrubberyCreationForm called\033[0m" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "\033[90mDestructor for ShrubberyCreationForm called\033[0m" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) : AForm(src.getName(), src.get_sGrade(), src.get_eGrade())
{
    std::cout << "\033[90mCopy constructor for ShrubberyCreationForm called\033[0m" << std::endl;
    *this = src;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src)
{
    this->setSigned(src.get_Signed());
    this->_target = src.getTarget();
    return (*this);
}

const std::string   ShrubberyCreationForm::getTarget() const 
{
    return (this->_target);
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    (void) executor;
    std::cout << "just a test for shrubbery" << std::endl;
    // need to do this.
}