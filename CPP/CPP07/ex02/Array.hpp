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
				return "Out of range";
			}
	};
};

template<typename T>
Array<T>::Array() {
	_array = NULL;
	_size = 0;
}

template<typename T>
Array<T>::Array(unsigned int n) {
	_array = new T[n];
	_size = n;
}

template<typename T>
Array<T>::Array(const Array& src) {
	_array = new T[src._size];
	_size = src._size;
	for (unsigned int i = 0; i < _size; i++)
		_array[i] = src._array[i];
}

template<typename T>
Array<T>::~Array() {
	if (_array)
		delete[] _array;
}

template<typename T>
Array<T>& Array<T>::operator=(const Array& src) {
	if (_array)
		delete[] _array;
	_array = new T[src._size];
	_size = src._size;
	for (unsigned int i = 0; i < _size; i++)
		_array[i] = src._array[i];
	return *this;
}

template<typename T>
T& Array<T>::operator[](unsigned int index) {
	if (index >= _size)
		throw IndexOutOfRangeException();
	return _array[index];
}

template<typename T>
unsigned int Array<T>::size() const {
	return _size;
}


#endif
