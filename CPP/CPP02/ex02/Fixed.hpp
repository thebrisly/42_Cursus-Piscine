/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brisly <brisly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 08:58:37 by brisly            #+#    #+#             */
/*   Updated: 2023/06/07 14:32:03 by brisly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <string>

class Fixed { //a canonic class contains:
    public:
        Fixed(); //default constructor
        Fixed(int const number); //default int constructor
        Fixed(float const number); //default float constructor
        Fixed(const Fixed &src); //copy constructor

        // https://www.youtube.com/watch?v=ZcmQ5y7QyTc Great video to understand overloading operator
        //In this exercise this is useless because we don't use it at all. It's just to learn how to do canonic classes
        Fixed& operator=(Fixed const &src); //overloading operator for =
        
        ~Fixed(); //default destructor

        int getRawBits (void) const;
        void setRawBits (int const raw);

        float toFloat (void) const;
        int toInt (void) const;
        
    private:
        int _fixedNumber;
        static int const _bits = 8;
};

std::ostream & operator<<(std::ostream &os, const Fixed &src); //overloading operator for <<

#endif