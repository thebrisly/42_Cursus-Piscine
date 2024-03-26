/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brisly <brisly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 21:42:09 by brisly            #+#    #+#             */
/*   Updated: 2023/06/09 22:22:08 by brisly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
# include <string>
# include <iostream>
# include "ClapTrap.hpp"

// https://www.geeksforgeeks.org/virtual-base-class-in-c/
class FragTrap : virtual public ClapTrap
{
    public:
        FragTrap(std::string name);
        FragTrap(FragTrap const &source);
        FragTrap& operator=(FragTrap const &src);
        ~FragTrap();

        void highFivesGuys();

};

#endif