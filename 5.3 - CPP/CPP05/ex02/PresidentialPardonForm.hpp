/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brisly <brisly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 15:31:54 by brisly            #+#    #+#             */
/*   Updated: 2023/08/24 09:44:06 by brisly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"
# include "Bureaucrat.hpp"

class PresidentialPardonForm : public AForm
{
    public:

        PresidentialPardonForm(std::string target);
        PresidentialPardonForm(const PresidentialPardonForm &src);
        ~PresidentialPardonForm();
        PresidentialPardonForm &operator=(const PresidentialPardonForm &src);
        
        const std::string   getTarget() const;

        virtual void        execute(Bureaucrat const & executor) const;

    private :

        std::string     _target;
};

#endif