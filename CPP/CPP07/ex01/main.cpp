/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brisly <brisly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:06:56 by brisly            #+#    #+#             */
/*   Updated: 2023/09/12 21:27:29 by brisly           ###   ########.fr       */
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