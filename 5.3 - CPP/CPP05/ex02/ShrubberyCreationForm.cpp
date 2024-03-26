/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brisly <brisly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 12:02:08 by brisly            #+#    #+#             */
/*   Updated: 2023/08/24 22:06:09 by brisly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>

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


// J'ai mis c_str() pcq le constructeur de std::ofstream ne reconnaît pas la conversion 
//d'une std::string en un const char* attendu pour le nom de fichier. Donc je le "caste"
void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    if (this->get_Signed() == 0)
        throw (AForm::NotSignedException());
    if (executor.getGrade() > this->get_eGrade())
        throw (AForm::GradeTooLowException());
    std::string file_name = this->getTarget() + "_shrubbery";
    std::ofstream File(file_name.c_str());
    File << TREE << std::endl;
    File.close();
    
}