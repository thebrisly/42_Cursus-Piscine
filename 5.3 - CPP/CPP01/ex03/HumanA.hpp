/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brisly <brisly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 21:37:08 by brisly            #+#    #+#             */
/*   Updated: 2023/06/04 21:42:04 by brisly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP
# include <string>
# include "Weapon.hpp"

class HumanA {
    private:
        std::string _name;
        Weapon &_weapon;    //it's a reference bc each HumanA NEEDS to have a weapon at its creation
                            //references are good utils that show the dependence between two elements
        
    public:
        HumanA(std::string name, Weapon &weapon);
        ~HumanA();
        void attack();
};

#endif