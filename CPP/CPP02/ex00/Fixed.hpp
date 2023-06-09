/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brisly <brisly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 08:58:37 by brisly            #+#    #+#             */
/*   Updated: 2023/06/09 07:54:41 by brisly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <string>

class Fixed { //a canonic class contains:
    public:
        Fixed(); //default constructor
        //Fixed(int number); //default constructor 2 //Did it here but I just saw that we will do it in the next exercise lol
        Fixed (Fixed &src); //copy constructor

        // https://www.youtube.com/watch?v=ZcmQ5y7QyTc Great video to understand overloading operator
        Fixed& operator=(Fixed const &src); //overloading operator for =
        
        ~Fixed(); //default destructor

        int getRawBits (void) const;
        void setRawBits (int const raw);
        
    private:
        int _fixedNumber;
        static int const _bits = 8;
};

#endif