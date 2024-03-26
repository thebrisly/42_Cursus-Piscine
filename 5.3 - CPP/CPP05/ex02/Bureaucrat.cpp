/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brisly <brisly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 14:10:34 by brisly            #+#    #+#             */
/*   Updated: 2023/08/24 21:45:40 by brisly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

//constructors and destructor init
Bureaucrat::Bureaucrat() : _name("Charly"), _grade(150) {
    std::cout << "\033[90mConstructor for a Bureaucrat called\033[0m" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name) : _name(name), _grade(150) {
    std::cout << "\033[90mConstructor for a Bureaucrat called\033[0m" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name), _grade(grade) {
    std::cout << "\033[90mConstructor for a Bureaucrat called\033[0m" << std::endl;
    
    if (this->_grade > 150)
        throw (Bureaucrat::GradeTooLowException());
    else if (this->_grade < 1)
        throw (Bureaucrat::GradeTooHighException());
}

Bureaucrat::~Bureaucrat() {
    std::cout << "\033[90mDestructor for a Bureaucrat called\033[0m" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) : _name(src._name) {
    std::cout << "\033[90mCopy constructor Bureaucrat called\033[0m" << std::endl;
    this->_grade = src._grade;
    return ;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src)
{
    this->_grade = src._grade;
    return (*this);
}

//operator overload for << 
std::ostream &	operator<<(std::ostream & ostr, Bureaucrat const & src)
{
	ostr << src.getName() << ", Bureaucrat grade " << src.getGrade();
	return (ostr);
}


// ****************************************************** //
// Accessors
const std::string Bureaucrat::getName() const 
{
    return (this->_name);
}

int Bureaucrat::getGrade() const 
{
    return (this->_grade);
}


// ****************************************************** //
// Functions to decrement and increment
void Bureaucrat::decrementGrade(int q) 
{
    this->_grade += q;
    if (this->_grade > 150 )
        throw (Bureaucrat::GradeTooLowException());
}

void Bureaucrat::incrementGrade(int q) 
{
    this->_grade -= q;
    if (this->_grade < 1 )
        throw (Bureaucrat::GradeTooHighException());
}

void Bureaucrat::signForm(AForm &src)
{
    try
    {
        src.beSigned(*this);
        std::cout << this->getName() << " signed " << src.getName() << std::endl;
    }

    catch(const std::exception& e)
    {
        std::cerr << this->getName() << " couldn't sign " << src.getName() << " because " << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(AForm const & form)
{
    try
    {
        form.execute(*this);
        std::cout << this->getName() << " executed " << form.getName() << std::endl;
    }

    catch(const std::exception& e)
    {
        std::cerr << this->getName() << " couldn't execute " << form.getName() << " because " << e.what() << std::endl;
    }
}