/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brisly <brisly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 14:13:33 by brisly            #+#    #+#             */
/*   Updated: 2023/08/26 21:53:03 by brisly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

//Constructors and destructor
AForm::AForm(void) : _name("Bob"), _signed(false), _sgrade(100), _egrade(3) {
    std::cout << "\033[90mDefault constructor for AForm called\033[0m" << std::endl;
}

AForm::AForm(std::string name, int sGrade, int eGrade) : _name(name), _signed(false), _sgrade(sGrade), _egrade(eGrade) {
    std::cout << "\033[90mConstructor for AForm called\033[0m" << std::endl;
    if (this->_sgrade > 150 || this->_egrade > 150)
        throw (AForm::GradeTooLowException());
    if (this->_sgrade < 1 || this->_sgrade < 1)
        throw (AForm::GradeTooHighException());
}

AForm::~AForm() {
    std::cout << "\033[90mDestructor for AForm called\033[0m" << std::endl;
}

AForm::AForm(const AForm &src) : _sgrade(src._sgrade), _egrade(src._egrade) {
    std::cout << "\033[90mCopy constructor for AForm called\033[0m" << std::endl;
    *this = src;
}

AForm &AForm::operator=(const AForm &src)
{
    this->_signed = src.get_Signed();
    return (*this);
}

std::ostream &	operator<<(std::ostream & ostr, AForm const & src)
{
    ostr << "|   AForm name : " << src.getName() << std::endl;
    ostr << "|   Signed (TRUE = 1 /FALSE = 0) : " << src.get_Signed() << std::endl;
    ostr << "|   Minimum grade to sign : " << src.get_sGrade() << std::endl;
    ostr << "|   Minimum grade to execute : " << src.get_eGrade();
	return (ostr);
}


// ****************************************************** //
// Accessors

const std::string AForm::getName() const 
{
    return (this->_name);
}

int AForm::get_sGrade() const 
{
    return (this->_sgrade);
}

int AForm::get_eGrade() const 
{
    return (this->_egrade);
}

bool AForm::get_Signed() const 
{
    return (this->_signed);
}

// ****************************************************** //
// Functions

void	AForm::setSigned(bool sign)
{
	this->_signed = sign;
	return ;
}

void AForm::beSigned(Bureaucrat &src)
{
    if (src.getGrade() <= this->_sgrade && this->get_Signed() == 0)
        this->_signed = true;
    else if (src.getGrade() <= this->_sgrade && this->get_Signed() == 1)
        throw (AForm::FormAlreadySignedException());
    else
        throw (AForm::GradeTooLowException());
}