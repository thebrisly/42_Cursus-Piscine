/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:06:56 by brisly            #+#    #+#             */
/*   Updated: 2023/09/13 09:59:26 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

int main()
{
    std::cout << "intArray: ";
	int intArray[] = {1, 2, 3, 4, 5};
    iter(intArray, 5, printElement<int>);
    std::cout << std::endl;

    std::cout << "doubleArray: ";
	double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    iter(doubleArray, 5, printElement<double>);
    std::cout << std::endl;

	std::cout << "stringArray: ";
	std::string stringArray[] = {"hello", "my", "name", "is", "laura"};
    iter(stringArray, 5, printElement<std::string>);
    std::cout << std::endl;

    return 0;
}

// class Awesome
// {
//   public:
//     Awesome( void ) : _n( 42 ) { return; }
//     int get( void ) const { return this->_n; }
//   private:
//     int _n;
// };

// std::ostream & operator<<( std::ostream & o, Awesome const & rhs )
// {
//   o << rhs.get();
//   return o;
// }

// template< typename T >
// void print( T& x )
// {
//   std::cout << x << std::endl;
//   return;
// }

// int main() {
//   int tab[] = { 0, 1, 2, 3, 4 };
//   Awesome tab2[5];

//   iter( tab, 5, print<int> );
//   iter( tab2, 5, print<Awesome> );

//   return 0;
// }
