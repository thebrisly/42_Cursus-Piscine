/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brisly <brisly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 20:09:36 by brisly            #+#    #+#             */
/*   Updated: 2023/08/20 21:38:20 by brisly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <string>
# include <iostream>

class Bureaucrat {

    public:
    
        Bureaucrat(void);
		Bureaucrat(std::string name);
        Bureaucrat(const std::string name, int grade);
        Bureaucrat(const Bureaucrat &src);
        ~Bureaucrat();
        Bureaucrat	&operator=(const Bureaucrat &src);

        const std::string getName() const;
        int         getGrade() const;

        void decrementGrade(int q);
        void incrementGrade(int q);


        // ****************************************************** //
        //Creating two exception classes for Bureaucrat :    
        // These exception classes, GradeTooHighException and GradeTooLowException, 
        // are customized for use specifically with the Bureaucrat class when grade-related errors are detected.
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

    private:
    
        const std::string   _name;
        int                 _grade;
};

std::ostream &operator<<(std::ostream &ostr, const Bureaucrat &src);

#endif