/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brisly <brisly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:03:36 by brisly            #+#    #+#             */
/*   Updated: 2023/09/11 13:03:37 by brisly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

# include <iostream>
# include <string>
#include <stdlib.h>

class Base
{
    public :
        virtual ~Base();
};

class A : public Base {};

class B : public Base {};

class C : public Base {};

#endif