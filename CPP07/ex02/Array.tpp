/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 12:11:08 by lunagda           #+#    #+#             */
/*   Updated: 2024/05/22 12:59:44 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <stdexcept>

template <typename T>
Array<T>::Array() : _size(0), _array(NULL)
{
}

template <typename T>
Array<T>::Array(unsigned int n) : _size(n), _array(new T[n])
{
	for (unsigned int i = 0; i < n; i++)
		_array[i] = 0;
}

template <typename T>
Array<T>::Array(const Array &copy) : _size(copy._size), _array(new T[copy._size])
{
	for (unsigned int i = 0; i < copy._size; i++)
		_array[i] = copy._array[i];
}

template <typename T>
Array<T>::~Array()
{
	delete[] _array;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &copy)
{
	if (this == &copy)
		return (*this);
	delete[] _array;
	_size = copy._size;
	_array = new int[copy._size];
	for (unsigned int i = 0; i < copy._size; i++)
		_array[i] = copy._array[i];
	return (*this);
}

template <typename T>
T &Array<T>::operator[](unsigned int index)
{
	if (index >= _size)
		throw Array::OutOfLimits();
	return (_array[index]);
}

template <typename T>
unsigned int Array<T>::size() const
{
	return (_size);
}

template <typename T>
const char *Array<T>::OutOfLimits::what() const throw()
{
	return ("Error: Out of limits");
}
