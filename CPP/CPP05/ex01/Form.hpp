/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brisly <brisly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 20:55:06 by brisly            #+#    #+#             */
/*   Updated: 2023/08/22 21:47:02 by brisly           ###   ########.fr       */
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

    private : 

        const std::string   _name;
        bool                _signed;
        int                 _sgrade;
        int                 _egrade;

};

std::ostream &operator<<(std::ostream &ostr, const Form &src);

#endif