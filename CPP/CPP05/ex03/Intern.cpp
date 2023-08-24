/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brisly <brisly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 22:27:29 by brisly            #+#    #+#             */
/*   Updated: 2023/08/24 22:29:30 by brisly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
    std::cout << "\033[90mConstructor for Intern called\033[0m" << std::endl;
}

Intern::~Intern()
{
    std::cout << "\033[90mDestructor for Intern called\033[0m" << std::endl;
}

Intern::Intern(const Intern &src)
{
    std::cout << "\033[90mCopy constructor for Intern called\033[0m" << std::endl;
    *this = src;
}

Intern &Intern::operator=(const Intern &src)
{
    return (*this);
}