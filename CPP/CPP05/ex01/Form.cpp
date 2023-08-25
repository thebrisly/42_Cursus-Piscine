/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 21:07:32 by brisly            #+#    #+#             */
/*   Updated: 2023/08/25 13:30:01 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

//Constructors and destructor
Form::Form(void) : _name("Bob"), _signed(false), _sgrade(100), _egrade(3) {
    std::cout << "\033[90mDefault constructor for a Form called\033[0m" << std::endl;
}

Form::Form(std::string name, int sGrade, int eGrade) : _name(name), _signed(false), _sgrade(sGrade), _egrade(eGrade) {
    std::cout << "\033[90mPersonalized constructor for a Form called\033[0m" << std::endl;
    if (this->_sgrade > 150 || this->_egrade > 150)
        throw (Form::GradeTooLowException());
    if (this->_sgrade < 1 || this->_egrade < 1)
        throw (Form::GradeTooHighException());
}

Form::~Form() {
    std::cout << "\033[90mDestructor for Form called\033[0m" << std::endl;
}

Form::Form(const Form &src) : _sgrade(src._sgrade), _egrade(src._egrade) {
    std::cout << "\033[90mCopy constructor Form called\033[0m" << std::endl;
    *this = src;
}

Form &Form::operator=(const Form &src)
{
    this->_signed = src.get_Signed();
    return (*this);
}

std::ostream &	operator<<(std::ostream & ostr, Form const & src)
{
    ostr << "|   Form name : " << src.getName() << std::endl;
    ostr << "|   Signed (TRUE = 1 /FALSE = 0) : " << src.get_Signed() << std::endl;
    ostr << "|   Minimum grade to sign : " << src.get_sGrade() << std::endl;
    ostr << "|   Minimum grade to execute : " << src.get_eGrade();
	return (ostr);
}


// ****************************************************** //
// Accessors

const std::string Form::getName() const
{
    return (this->_name);
}

int Form::get_sGrade() const
{
    return (this->_sgrade);
}

int Form::get_eGrade() const
{
    return (this->_egrade);
}

bool Form::get_Signed() const
{
    return (this->_signed);
}

// ****************************************************** //
// Functions

void Form::beSigned(Bureaucrat &src)
{
    if (src.getGrade() <= this->_sgrade && this->get_Signed() == 0)
        this->_signed = true;
    else if (src.getGrade() <= this->_sgrade && this->get_Signed() == 1)
        throw (Form::FormAlreadySignedException());
    else
        throw (Form::GradeTooLowException());
}
