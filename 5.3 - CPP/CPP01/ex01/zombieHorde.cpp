/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brisly <brisly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 21:17:16 by brisly            #+#    #+#             */
/*   Updated: 2023/06/03 21:17:27 by brisly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
    int i = 0;

    Zombie *horde = new Zombie[N];
    while (i < N)
    {
        horde[i].setName(name);
        i++;
    }
    return (horde);
}