/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brisly <brisly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 21:37:31 by brisly            #+#    #+#             */
/*   Updated: 2023/06/04 21:18:49 by brisly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP
# include <string>
# include "Weapon.hpp"

class HumanB {
    private:
        std::string _name;
        Weapon *_weapon;

    public:
        HumanB(std::string name);
        ~HumanB();
        void attack();
        void setWeapon(Weapon &weapon);
};

#endif