/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brisly <brisly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:07:08 by brisly            #+#    #+#             */
/*   Updated: 2023/09/12 21:24:51 by brisly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP
# include <iostream>

template <typename T>
void iter(T* array, size_t length, void (*function)(T&))
{
	size_t i = 0;
	while (i < length)
	{
		function(array[i]);
		i++;
	}
}

template <typename T>
void printElement(T& element)
{
    std::cout << element << " ";
}

#endif