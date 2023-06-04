/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brisly <brisly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 21:37:49 by brisly            #+#    #+#             */
/*   Updated: 2023/06/04 21:33:02 by brisly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP
# include <string>

class Weapon {

    private:
        std::string _weapon;
    
    public:
        Weapon(std::string weaponType);
        ~Weapon();
        std::string const &getType();
        void        setType(std::string weaponType);
};

#endif