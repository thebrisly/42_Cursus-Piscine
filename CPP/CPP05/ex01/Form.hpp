/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 20:55:06 by brisly            #+#    #+#             */
/*   Updated: 2023/08/25 13:30:11 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <string.h>
# include <stdio.h>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form {

    public :

    Form(void);
    Form(std::string name, int sGrade, int eGrade);
    Form(const Form &src);
    ~Form();
    Form &operator=(const Form &src);

    const std::string   getName() const;
    int                 get_sGrade() const;
    int                 get_eGrade() const;
    bool                get_Signed() const;

    void                beSigned(Bureaucrat &src);


    class GradeTooHighException : public std::exception
    {
        public :

            virtual const char* what() const throw()
            {
                return ("The grade you set is too high");
            }
    };

    class GradeTooLowException : public std::exception
    {
        public :

            virtual const char * what() const throw()
            {
                return ("The grade you set is too low");
            }
    };

    class FormAlreadySignedException : public std::exception
    {
        public :

            virtual const char * what() const throw()
            {
                return ("the form is already signed :)");
            }
    };


    private :

        const std::string   _name;
        bool                _signed;
        const int           _sgrade;
        const int           _egrade;

};

std::ostream &operator<<(std::ostream &ostr, const Form &src);

#endif
