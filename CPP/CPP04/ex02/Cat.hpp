/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 08:06:50 by brisly            #+#    #+#             */
/*   Updated: 2023/08/16 12:45:22 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP
# include "Animal.hpp"
# include <string>
# include <iostream>
# include "Brain.hpp"

class Cat : public Animal {
    public:
        Cat();
        Cat(Cat const &src);
        Cat& operator=(Cat const &src);
        virtual ~Cat(); //bc animal is a polymorph object

        virtual void makeSound(void) const;
        void setType(std::string newType);
        Brain* getBrain() const;

    private:
        Brain* _brain;

};

#endif
