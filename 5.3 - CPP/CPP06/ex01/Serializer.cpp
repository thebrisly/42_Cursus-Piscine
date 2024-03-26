/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brisly <brisly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:03:16 by brisly            #+#    #+#             */
/*   Updated: 2023/09/11 13:03:17 by brisly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer() {
    std::cout << "\033[90mConstrucor for Serializer called\033[0m" << std::endl;
}

Serializer::~Serializer() {
    std::cout << "\033[90mDestructor for Serializer called\033[0m" << std::endl;
}

Serializer::Serializer(const Serializer &src) {
    std::cout << "\033[90mCopy constructor for Serializer called\033[0m" << std::endl;
    *this = src;
}

Serializer	&Serializer::operator=(Serializer const &src) {
	(void)src;
	 std::cout << "\033[90mAssignment operator for Serializer called\033[0m" << std::endl;
	return *this;
}

/* ----------------------- METHODS ----------------------- */

/* L'opérateur reinterpret_cast convertit une valeur de pointeur null
 en valeur de pointeur null du type de destination.*/

uintptr_t Serializer::serialize(Data* ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data *>(raw);
}