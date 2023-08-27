/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brisly <brisly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 09:05:08 by brisly            #+#    #+#             */
/*   Updated: 2023/08/27 18:04:35 by brisly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"
# include "Bureaucrat.hpp"

# define TREE "      ^   \n     / \\  \n    /___\\ \n   /^   ^\\\n  / ^   ^ \\\n /__^___^__\\  ฅ^•ﻌ•^ฅ"



class ShrubberyCreationForm : public AForm
{
    public:

        ShrubberyCreationForm(std::string target);
        ShrubberyCreationForm(const ShrubberyCreationForm &src);
        virtual ~ShrubberyCreationForm();
        ShrubberyCreationForm &operator=(const ShrubberyCreationForm &src);
        
        const std::string   getTarget() const;

        virtual void        execute(Bureaucrat const & executor) const;

    private :

        std::string     _target;
};

#endif