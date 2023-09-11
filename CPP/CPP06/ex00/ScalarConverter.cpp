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
#include <cerrno>

// Constructors & Destructors
ScalarConverter::ScalarConverter() {}
ScalarConverter::~ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &src) { (void) src; }

// ----------------------------------------------------- //
// Other methods

void ScalarConverter::convert(std::string string)
{
    std::string type = get_type(string);
    if (type == "char")
        printChar(string, type);
    else if (type == "int")
        printInt(string, type);
    else if (type == "double")
        printDouble(string, type);
    else if (type == "float")
        printFloat(string, type);
    else
        std::cerr << "\033[31mInvalid entry. Try again.\033[0m" << std::endl;
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

int ScalarConverter::isInt(std::string string) {
    char* end_ptr;
    errno = 0;
    long int converted = std::strtol(string.c_str(), &end_ptr, 0);

    if (errno == 0 && *end_ptr == '\0' && converted >= INT_MIN && converted <= INT_MAX) {
        return 1;
    }
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
    char    c = string[0];
    // explicit conversions
    int		i = static_cast<int>(c);
	float	f = static_cast<float>(c);
	double	d = static_cast<double>(c);

    std::cout << "\033[35m// ORIGINAL TYPE: " << type << std::endl;
    std::cout << "\033[0mchar : " << c << std::endl;
    std::cout << "int : " << i << std::endl;
    std::cout << "float: " << f << ".0f" << std::endl;
	std::cout << "double: " << d << ".0" << std::endl;
}

void ScalarConverter::printInt(std::string string, std::string type)  
{
    int i = std::atoi(string.c_str());
    // explicit conversions
    char    c = static_cast<char>(i);
	float	f = static_cast<float>(i);
	double	d = static_cast<double>(i);
    std::cout << "\033[35m// ORIGINAL TYPE: " << type << std::endl;
    std::cout << "\033[0mchar : ";
    if (!std::isprint(c) && i < 128 && i >= 0)
        std::cout << "non displayable" << std::endl;
    else if (i < 0 || i > 127)
        std::cout << "impossible" << std::endl;
    else
        std::cout << c << std::endl;
    std::cout << "int : " << i << std::endl;
    std::cout << "float: " << f << ".0f" << std::endl;
	std::cout << "double: " << d << ".0" << std::endl;
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

