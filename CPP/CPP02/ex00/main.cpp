/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brisly <brisly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 08:55:14 by brisly            #+#    #+#             */
/*   Updated: 2023/06/07 09:59:53 by brisly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int main( void ) 
{
    Fixed a;
    Fixed b(a); //constructeur par parametre
    Fixed c; //constructeur par copie (pcq apres c = b)

    c = b;

    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;

    std::cout << "\n --- Just another test to better understand ad hoc polymorphism :" << std::endl;
    Fixed d (42);
    std::cout << d.getRawBits() << std::endl;
    
    return 0;
}
