/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brisly <brisly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 21:27:52 by brisly            #+#    #+#             */
/*   Updated: 2023/06/09 08:38:37 by brisly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
# include <string>
# include <iostream>

class ClapTrap {
    private:
        std::string     _name;
        int             _hitPoints;
        int             _energyPoints;
        int             _attackDamage;

    public:
        ClapTrap(std::string name);                 // default constructor
        ~ClapTrap();                                // default destructor
        ClapTrap(ClapTrap const &src);              // copy constructor
        ClapTrap& operator=(ClapTrap const &src);   // overloading operator for =

        void attack(const std::string &target);
        void takeDamage(unsigned int amount);
        std::string getName (void);
        //void beRepaired(unsigned int amount);
};

#endif