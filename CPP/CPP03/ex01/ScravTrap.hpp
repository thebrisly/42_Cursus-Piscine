/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScravTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brisly <brisly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 14:59:30 by brisly            #+#    #+#             */
/*   Updated: 2023/06/09 15:18:35 by brisly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCRAVTRAP_HPP
# define SCRAVTRAP_HPP
# include <string>
# include <iostream>
# include "ClapTrap.hpp"

class ScravTrap : public ClapTrap
{
    public:
        ScravTrap(std::string name);
        ScravTrap(ScravTrap const &source);
        ScravTrap& operator=(ScravTrap const &src);
        ~ScravTrap();

        void guardGate();

};

#endif