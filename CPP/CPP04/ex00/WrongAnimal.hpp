/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brisly <brisly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 08:06:50 by brisly            #+#    #+#             */
/*   Updated: 2023/06/12 08:36:01 by brisly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP
# include <string>
# include <iostream>

class WrongAnimal {
    public:
        WrongAnimal();
        WrongAnimal(WrongAnimal const &src);
        WrongAnimal& operator=(WrongAnimal const &src);
        virtual ~WrongAnimal();

        void makeSound(void) const;
        std::string getType(void) const;
        

    protected:
        std::string type;
};

#endif