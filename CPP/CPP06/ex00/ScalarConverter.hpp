/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brisly <brisly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 19:32:49 by brisly            #+#    #+#             */
/*   Updated: 2023/08/27 21:26:17 by brisly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <cmath>
#include <string>
#include <limits.h>
#include <cfloat>
#include <ostream>
#include <stdlib.h>

static class ScalarConverter 
{

    public :        
        static void convert(std::string string);

        class UnknowTypeException : public std::exception
        {
            public :

                virtual const char* what() const throw()
                {
                    return ("The type you gave seems incorrect. Make sure that it's a double, float, char or int.");
                }
        };

    private :
        ScalarConverter();
        ~ScalarConverter();
        ScalarConverter(const ScalarConverter &src);
        ScalarConverter &operator=(const ScalarConverter &src);

        static int isInt(std::string string) const;
        static int isFloat(std::string string) const;
        static int isChar(std::string string) const;
        static int isDouble(std::string string) const;
        
        
};

#endif