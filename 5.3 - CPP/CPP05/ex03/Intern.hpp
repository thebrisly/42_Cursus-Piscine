/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brisly <brisly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 22:19:54 by brisly            #+#    #+#             */
/*   Updated: 2023/08/27 17:51:21 by brisly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class Intern 
{
    public :

        Intern();
        Intern(const Intern &src);
        ~Intern();
        Intern &operator=(const Intern &src);

        AForm* makeForm(std::string form_name, std::string target) const;

        class WrongFormException : public std::exception
        {
            public :

                virtual const char *what() const throw()
                {
                    return("someone gave this form a wrong name");
                }
        };

    private :

        AForm* makeSCF(std::string target) const;
        AForm* makeRRF(std::string target) const;
        AForm* makePPF(std::string target) const;
};

#endif