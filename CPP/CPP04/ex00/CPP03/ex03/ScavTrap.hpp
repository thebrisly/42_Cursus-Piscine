/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brisly <brisly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 14:59:30 by brisly            #+#    #+#             */
/*   Updated: 2023/06/09 21:38:59 by brisly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ScavTRAP_HPP
# define ScavTRAP_HPP
# include <string>
# include <iostream>
# include "ClapTrap.hpp"

// https://www.geeksforgeeks.org/virtual-base-class-in-c/
class ScavTrap : virtual public ClapTrap
{
    public:
        ScavTrap(std::string name);
        ScavTrap(ScavTrap const &source);
        ScavTrap& operator=(ScavTrap const &src);
        ~ScavTrap();

        void attack(const std::string &target);

        void guardGate();

};

#endif