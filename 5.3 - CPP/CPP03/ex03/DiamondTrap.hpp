/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 22:04:54 by brisly            #+#    #+#             */
/*   Updated: 2023/06/30 11:03:06 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP
# include <string>
# include <iostream>
# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
    private:
        std::string _name;

    public:
        DiamondTrap(std::string name);
        DiamondTrap(DiamondTrap const &src);
        DiamondTrap& operator=(DiamondTrap const &src);
        ~DiamondTrap();

        void attack(const std::string &target);
        void whoAmI(void) const;
};

#endif
