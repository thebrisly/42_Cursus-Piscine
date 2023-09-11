/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brisly <brisly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 19:32:49 by brisly            #+#    #+#             */
/*   Updated: 2023/09/11 10:32:19 by brisly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <cstring>
# include <limits.h>
# include <cfloat>
# include <ostream>
# include <stdlib.h>

class ScalarConverter 
{

    public :        
        static void convert(std::string string);

        /*class UnknowTypeException : public std::exception
        {
            public :

                virtual const char* what() const throw()
                {
                    return ("The type you gave seems incorrect. Make sure that it's a double, float, char or int.");
                }
        };*/

    private :
        ScalarConverter();
        ~ScalarConverter();
        ScalarConverter(const ScalarConverter &src);
        ScalarConverter &operator=(const ScalarConverter &src);

        static std::string get_type(std::string string);
        static int isInt(std::string string);
        static int isFloat(std::string string);
        static int isChar(std::string string);
        static int isDouble(std::string string);
        
        static void printChar(std::string string, std::string type);
        static void printInt(std::string string, std::string type);
        static void printDouble(std::string string, std::string type);
        static void printFloat(std::string string, std::string type);

        static void checkChar(int i, char c);
        static void checkInt(int i);
};

#endif