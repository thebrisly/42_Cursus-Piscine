/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:09:01 by brisly            #+#    #+#             */
/*   Updated: 2023/09/13 11:41:00 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>

#define MAX_VAL 750
int main(int, char**)
{
    {
        std::cout << "--- Empty array ---" << std::endl;
        Array<int> array;
        std::cout << "array.size = " << array.size() << std::endl;
        std::cout << std::endl;
    }

    {
        unsigned int s = 3;
        std::cout << "--- Create array int ---" << std::endl;
        Array<int> array(s);
        std::cout << "array.size = " << array.size() << std::endl;
        for (unsigned int i = 0; i < array.size(); i++)
            std::cout << "array[" << i << "] = " << array[i] << std::endl;
        std::cout << std::endl;
    }

    {
        std::cout << "--- Array int ---" << std::endl;
        Array<int> array(3);
        std::cout << "array.size = " << array.size() << std::endl;
        array[0] = 1;
        array[1] = 2;
        array[2] = 3;
        for (unsigned int i = 0; i < array.size(); i++)
            std::cout << "array[" << i << "] = " << array[i] << std::endl;
        std::cout << std::endl;
    }
}
