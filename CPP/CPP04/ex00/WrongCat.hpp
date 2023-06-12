/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brisly <brisly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 08:06:50 by brisly            #+#    #+#             */
/*   Updated: 2023/06/12 09:20:00 by brisly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP
# include "WrongAnimal.hpp"
# include <string>
# include <iostream>

class WrongCat : public WrongAnimal {
    public:
        WrongCat();
        WrongCat(WrongCat const &src);
        WrongCat& operator=(WrongCat const &src);
        virtual ~WrongCat();

        void makeSound(void) const;

};

#endif