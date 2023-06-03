/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brisly <brisly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 21:08:23 by brisly            #+#    #+#             */
/*   Updated: 2023/06/03 08:11:50 by brisly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

class Zombie {
    private:
        std::string _name;

    public:
        Zombie(std::string name);
        ~Zombie();
        
        void announce(void);
};