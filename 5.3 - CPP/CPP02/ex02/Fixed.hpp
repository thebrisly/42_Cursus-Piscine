/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 08:58:37 by brisly            #+#    #+#             */
/*   Updated: 2023/06/28 11:21:44 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <string>
# include <iostream>
# include <cmath>

class Fixed { //a canonic class contains:
    public:
        Fixed(); //default constructor
        Fixed(int const number); //default int constructor
        Fixed(float const number); //default float constructor
        Fixed(const Fixed &src); //copy constructor
        Fixed& operator=(Fixed const &src); //overloading operator for =
        ~Fixed(); //default destructor

        bool    operator>(const Fixed &fixed) const;
        bool    operator<(const Fixed &fixed) const;
        bool    operator>=(const Fixed &fixed) const;
        bool    operator<=(const Fixed &fixed) const;
        bool    operator==(const Fixed &fixed) const;
        bool    operator!=(const Fixed &fixed) const;

        Fixed   operator+(const Fixed &fixed) const;
        Fixed   operator-(const Fixed &fixed) const;
        Fixed   operator*(const Fixed &fixed) const;
        Fixed   operator/(const Fixed &fixed) const;

        Fixed&  operator++(void); // Prefix increment operator -> saw that on google
        Fixed   operator++(int); //Postfix increment operator -> saw that on google
        Fixed&  operator--(void); // Prefix increment operator -> saw that on google
        Fixed   operator--(int); //Postfix increment operator -> saw that on google

        static Fixed &min(Fixed &fixed1, Fixed &fixed2);
        static const Fixed &min(const Fixed &fixed1, const Fixed &fixed2);
        static Fixed &max(Fixed &fixed1, Fixed &fixed2);
        static const Fixed &max(const Fixed &fixed1, const Fixed &fixed2);

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
