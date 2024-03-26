/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brisly <brisly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 12:00:40 by brisly            #+#    #+#             */
/*   Updated: 2023/08/24 21:44:20 by brisly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <stdlib.h>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target) 
{
    std::cout << "\033[90mConstructor for RobotomyRequestForm called\033[0m" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "\033[90mDestructor for RobotomyRequestForm called\033[0m" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) : AForm(src.getName(), src.get_sGrade(), src.get_eGrade())
{
    std::cout << "\033[90mCopy constructor for RobotomyRequestForm called\033[0m" << std::endl;
    *this = src;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &src)
{
    this->setSigned(src.get_Signed());
    this->_target = src.getTarget();
    return (*this);
}

const std::string   RobotomyRequestForm::getTarget() const 
{
    return (this->_target);
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    if (this->get_Signed() == 0)
        throw (AForm::NotSignedException());
    if (executor.getGrade() > this->get_eGrade())
        throw (AForm::GradeTooLowException());
    std::srand(std::time(0));
    int v1 = std::rand() % 2;
    if (v1 == 0)
        std::cout << "BRRRRRRRRRRRRRRRRR " << this->getTarget() << " has been successfully robotomized (50% of the time)" << std::endl;
    else if (v1 == 1)
        std::cout << "MMMhhhhh Operation failed. You had a 50% chance of succeeding, you were out of luck!" << std::endl;
    
}