/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brisly <brisly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 19:32:32 by brisly            #+#    #+#             */
/*   Updated: 2023/08/27 21:41:26 by brisly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

// Constructors & Destructors
ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &src) { (void) src; }

ScalarConverter &operator=(const ScalarConverter &src)
{ return *this }

// ----------------------------------------------------- //
// Other methods


void ScalarConverter::convert(std::string string)
{
    std::string types[] = {"int", "float", "char", "double"};
    void (ScalarConverter::*ptr_to_memberfunction[]) (std::string) = { &ScalarConverter::printInt, &ScalarConverter::printFloat, &ScalarConverter::printChar, &ScalarConverter::printDouble};

    std::string type = get_type(string);
    for (int i = 0; i < 4; i++)
    {
        if (type == types[i])
        {
            (ScalarConverter::(ptr_to_memberfunction[i]))(string);
            break;
        }
        i++;
    }
}

std::string ScalarConverter::get_type(std::string string)  
{
    if (isChar(string))
        return ("char");
    /*else if (isInt(string))
        return ("int");
    else if (isDouble(string))
        return ("double");
    else if (isFloat(string))
        return ("float");*/
    else
        {
            std::cerr << "Invalid entry. Try again." << std::endl; //or smthg else
            return 0;
        }
}

int ScalarConverter::isChar(std::string string)  
{
    if (string.size() == 1)
    {
        if (std::isprint(string[0]) == 1 && std::isdigit(string[0]) == 0)
            return 1;
        else
            return 0;
    }
    else
        return 0;
}

/*int ScalarConverter::isDouble(std::string string)  
{

}

int ScalarConverter::isInt(std::string string)  
{

}

int ScalarConverter::isFloat(std::string string)  
{

}*/

void ScalarConverter::printChar(std::string string)  
{
    (void) string;
    std::cout << "it'as a char :)" << std::endl;
}

void ScalarConverter::printInt(std::string string)  
{
    (void) string;
    std::cout << "it'as an int :)" << std::endl;
}

void ScalarConverter::printDouble(std::string string)  
{
    (void) string;
    std::cout << "it'as a double :)" << std::endl;
}

void ScalarConverter::printFloat(std::string string)  
{
    (void) string;
    std::cout << "it'as a float :)" << std::endl;
}

