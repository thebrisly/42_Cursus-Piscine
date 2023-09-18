/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:09:11 by brisly            #+#    #+#             */
/*   Updated: 2023/09/13 11:45:20 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP
# include <iostream>

template <typename T> class Array
{
	public:

		Array();
		~Array();
		Array(unsigned int n);
		Array(const Array& src);

		Array& operator=(const Array& src);
		T& operator[](unsigned int index);
		
		unsigned int size() const;

	private:

		T* 				_array;
		unsigned int 	_size;


	class IndexOutOfRangeException : public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return ("Out of range");
			}
	};
};

#endif
