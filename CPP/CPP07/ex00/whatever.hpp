/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brisly <brisly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:01:52 by brisly            #+#    #+#             */
/*   Updated: 2023/09/12 20:56:47 by brisly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template <typename T>
void swap(T& x, T& y)
{
	T temp = x;
	x = y;
	y = temp;
}

template <typename T>
T max(const T& x, const T& y)
{
	if (x > y)
		return (x);
	else if (x < y)
		return (y);
	else
		return (y);
}

template <typename T>
T min(const T& x, const T& y)
{
	if (x < y)
		return (x);
	else if (x > y)
		return (y);
	else
		return (y);
}

#endif

/* 
https://www.geeksforgeeks.org/templates-cpp/

A template is a simple yet very powerful tool in C++. 
The simple idea is to pass the data type as a parameter so that we don’t 
need to write the same code for different data types. 
For example, a software company may need to sort() for different data types. 
Rather than writing and maintaining multiple codes, 
we can write one sort() and pass the datatype as a parameter.*/