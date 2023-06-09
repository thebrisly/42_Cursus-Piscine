/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brisly <brisly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 08:55:14 by brisly            #+#    #+#             */
/*   Updated: 2023/06/09 07:56:15 by brisly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int main( void ) 
{
    Fixed a; //here we call the default constructor
    Fixed b(a); //here we call the copy constructor
    Fixed c; 

    c = b; //here we call the overloaded assignment operator !

    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;

    /*std::cout << "\n --- Just another test to better understand ad hoc polymorphism :" << std::endl;
    Fixed d (42);
    std::cout << d.getRawBits() << std::endl;
    //Did it here but I just saw that we will do it in the next exercise lol
    */
    
    return 0;
}
