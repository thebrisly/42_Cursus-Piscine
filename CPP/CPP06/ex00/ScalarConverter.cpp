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

// ----------------------------------------------------- //
// Other methods

void ScalarConverter::convert(std::string string)
{
    //std::string types[] = {"int", "float", "char", "double"};
    std::string type = get_type(string);

    if (type == "unknown")
        std::cerr << "\033[31mInvalid entry. Try again.\033[0m" << std::endl;
    else {
        printChar(string, type);
        printInt(string, type);
        printDouble(string, type);
        printFloat(string, type);
    }

    /*if (type == "char")
        printChar(string, type);
    else if (type == "int")
        printInt(string, type);
    else if (type == "double")
        printDouble(string, type);
    else if (type == "float")
        printFloat(string, type);
    else
        std::cerr << "\033[31mInvalid entry. Try again.\033[0m" << std::endl;*/
}

std::string ScalarConverter::get_type(std::string string)  
{
    if (isChar(string))
        return ("char");
    else if (isInt(string))
        return ("int");
    else if (isFloat(string))
        return ("float");
    else if (isDouble(string))
        return ("double");
    else
        return ("unknown");
}

int ScalarConverter::isChar(std::string string)  
{
    if (string.size() != 1 || std::isdigit(string[0]))
        return 0;
    else
        return 1;
}

int ScalarConverter::isDouble(std::string string)
{
    char* end_ptr;
    int pointCount = 0;
    std::strtod(string.c_str(), &end_ptr);

    if (*end_ptr != '\0' || string[0] == '.' || string[string.length() - 1] == '.')
        return 0;
    for (size_t i = 0; i < string.length(); ++i)
    {
        if (string[i] == '.')
            pointCount++;
        if (pointCount > 1)
            return 0;
    }
    return 1;
}


int ScalarConverter::isInt(std::string string)  
{
    char* end_ptr;
    long int converted = std::strtol(string.c_str(), &end_ptr, 0);

    if (*end_ptr == '\0' && converted <= INT_MAX  && INT_MIN < converted)
        return 1;
    return 0;
}

int ScalarConverter::isFloat(std::string string)  
{
    int p_count = 0;
    int f_count = 0;
    char* end_ptr;
    strtod(string.c_str(), &end_ptr);
    if (string == "+inff" || string == "-inff")
        return 1;
    if (*end_ptr != 'f')
        return 0;
    for (size_t i = 0; i < string.length(); ++i) {
        if (string[i] == 'f')
            f_count++;
        if (string[i] == '.')
            p_count++;
    }
    return (f_count == 1 && p_count == 1);
}

void ScalarConverter::printChar(std::string string, std::string type)  
{
    //char to_display = reinterpret_cast<char>(string);

    char			res;
	bool			possible = false;

	std::cout << "char: ";
	if (type == "char")
	{
		possible = true;
		res = *reinterpret_cast<char *>(&string);
	}
	else if (type == "int")
	{
		int	i = reinterpret_cast<int>(string);
		possible = true;
		res = static_cast<char>(i);
	}
	else if (type == "float")
	{
		float	*f = reinterpret_cast<float *>(&string); 
		possible = true;
		res = static_cast<char>(*f);
	}
	else if (type == "double")
	{
		double	*d = reinterpret_cast<double *>(&string);
		possible = true;
		res = static_cast<char>(*d);
	}
	if (!possible)
		std::cout << "impossible";
	else if (std::isprint(res))
		std::cout << res;
	else
		std::cout << "Non displayable";
	std::cout << std::endl;
}

void ScalarConverter::printInt(std::string string, std::string type)  
{
    (void) string;
    (void) type;
    std::cout << "it'as an int :)" << std::endl;
}

void ScalarConverter::printDouble(std::string string, std::string type)  
{
    (void) string;
    (void) type;
    std::cout << "it'as a double :)" << std::endl;
}

void ScalarConverter::printFloat(std::string string, std::string type)  
{
    (void) string;
    (void) type;
    std::cout << "it'as a float :)" << std::endl;
}

