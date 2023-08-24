/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brisly <brisly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 12:00:40 by brisly            #+#    #+#             */
/*   Updated: 2023/08/24 12:07:04 by brisly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 75, 45), _target(target) 
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
    (void) executor;
    std::cout << "just a test for robotomy" << std::endl;
    //need to do this.
}