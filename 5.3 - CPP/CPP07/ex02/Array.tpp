
#ifndef ARRAY_TPP
# define ARRAY_TPP
# include "Array.hpp"

template<typename T>
Array<T>::Array() 
{
	_array = NULL;
	_size = 0;
}

template<typename T>
Array<T>::Array(unsigned int n) 
{
	_array = new T[n];
	_size = n;
}

template<typename T>
Array<T>::Array(const Array& src) 
{
	_array = new T[src._size];
	_size = src._size;
	for (unsigned int i = 0; i < _size; i++)
		_array[i] = src._array[i];
}

template<typename T>
Array<T>::~Array() 
{
	if (_array)
		delete[] _array;
}

template<typename T>
Array<T>& Array<T>::operator=(const Array& src) 
{
	if (_array)
		delete[] _array;
	_array = new T[src._size];
	_size = src._size;
	for (unsigned int i = 0; i < _size; i++)
		_array[i] = src._array[i];
	return *this;
}

template<typename T>
T& Array<T>::operator[](unsigned int index) 
{
	if (index >= _size)
		throw IndexOutOfRangeException();
	return (_array[index]);
}

template<typename T>
unsigned int Array<T>::size() const 
{
	return _size;
}

#endif