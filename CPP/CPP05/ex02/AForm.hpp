/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brisly <brisly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 14:14:24 by brisly            #+#    #+#             */
/*   Updated: 2023/08/24 21:45:58 by brisly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <string.h>
# include <stdio.h>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {

    public :

        AForm(void);
        AForm(std::string name, int sGrade, int eGrade);
        AForm(const AForm &src);
        ~AForm();
        AForm &operator=(const AForm &src);

        const std::string   getName() const;
        int                 get_sGrade() const;
        int                 get_eGrade() const;
        bool                get_Signed() const;

        void	            setSigned(bool sign);

        void                beSigned(Bureaucrat &src);
        virtual void        execute(Bureaucrat const & executor) const = 0;


        class GradeTooHighException : public std::exception
        {
            public :

                virtual const char* what() const throw()
                {
                    return ("The grade you set is too high.");
                }
        };

        class GradeTooLowException : public std::exception
        {
            public :

                virtual const char * what() const throw()
                {
                    return ("The grade you set is too low.");
                }
        };

        class NotSignedException : public std::exception
        {
            public :

                virtual const char * what() const throw()
                {
                    return ("The Form is not signed.");
                }
        };

    private : 

        const std::string   _name;
        bool                _signed;
        int                 _sgrade;
        int                 _egrade;

};

std::ostream &operator<<(std::ostream &ostr, const AForm &src);

#endif