/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brisly <brisly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 08:06:50 by brisly            #+#    #+#             */
/*   Updated: 2023/06/12 14:44:21 by brisly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <string>
# include <iostream>

class Animal {
    public:
        Animal();
        Animal(Animal const &src);
        Animal& operator=(Animal const &src);
        virtual ~Animal();

        virtual void makeSound(void) const = 0; // thanks to this, the class will become abstract
        std::string getType(void) const;
        

    protected:
        std::string type;
};

#endif