/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 08:06:50 by brisly            #+#    #+#             */
/*   Updated: 2023/08/16 12:41:59 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP
# include "Animal.hpp"
# include <string>
# include <iostream>
# include "Brain.hpp"

class Dog : public Animal {
    public:
        Dog();
        Dog(Dog const &src);
        Dog& operator=(Dog const &src);
        virtual ~Dog();

        virtual void makeSound(void) const;
        void setType(std::string newType);
        Brain* getBrain() const;

    private:
        Brain* _brain;

};

#endif
