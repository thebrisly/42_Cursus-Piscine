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

#include "Array.tpp"
#include <iostream>

#define MAX_VAL 750
int main(int, char**)
{
    {
        unsigned int s = 5;
        std::cout << "\033[34m--- Create array int with no value inside ---\033[0m" << std::endl;
        Array<int> array(s);
        std::cout << "array.size = " << array.size() << std::endl;
        for (unsigned int i = 0; i < array.size(); i++)
            std::cout << "array[" << i << "] = " << array[i] << std::endl;
        std::cout << std::endl;
    }

    {
        std::cout << "\033[34m--- Int array of size 4 with 3 values only---\033[0m" << std::endl;
        Array<int> array(4);
        std::cout << "array.size = " << array.size() << std::endl;
        array[0] = 9543;
        array[1] = 453;
        array[2] = 5;
        for (unsigned int i = 0; i < array.size(); i++)
            std::cout << "array[" << i << "] = " << array[i] << std::endl;
        std::cout << std::endl;
    }

    {
        std::cout << "\033[34m--- Empty array ---\033[0m" << std::endl;
        Array<int> array;
        std::cout << "array.size = " << array.size() << std::endl;
        std::cout << std::endl;
    }

    {
        std::cout << "\033[34m--- Proof that assignment operator works well ---\033[0m" << std::endl;
        Array<int> array(3);
        array[0] = 9543;
        array[1] = 453;
        array[2] = 5;

        Array<int> array2;
        array2 = array;
        array2[0] = 0;
        array2[1] = 42;
        array[0] = 1;
        for (unsigned int i = 0; i < array2.size(); i++)
            std::cout << "array2[" << i << "] = " << array2[i] << std::endl;
        std::cout << std::endl;
        for (unsigned int i = 0; i < array.size(); i++)
            std::cout << "array[" << i << "] = " << array[i] << std::endl;
        std::cout << std::endl;
    }

      {
        std::cout << "\033[34m--- Proof that copy constructor works well ---\033[0m" << std::endl;
        Array<int> array(3);
        array[0] = 9543;
        array[1] = 453;
        array[2] = 5;

        Array<int> array2(array);
        array2[0] = 0;
        array2[1] = 42;
        array[0] = 1;
        for (unsigned int i = 0; i < array2.size(); i++)
            std::cout << "array2[" << i << "] = " << array2[i] << std::endl;
        std::cout << std::endl;
        for (unsigned int i = 0; i < array.size(); i++)
            std::cout << "array[" << i << "] = " << array[i] << std::endl;
        std::cout << std::endl;
    }
}
