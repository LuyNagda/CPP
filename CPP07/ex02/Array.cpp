/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 16:33:22 by lunagda           #+#    #+#             */
/*   Updated: 2024/05/17 16:34:33 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

Array::Array() : _size(0), _array(NULL)
{
}

Array::Array(unsigned int n) : _size(n), _array(new int[n])
{
	for (unsigned int i = 0; i < n; i++)
		_array[i] = 0;
}

Array::Array(const Array &copy) : _size(copy._size), _array(new int[copy._size])
{
	for (unsigned int i = 0; i < copy._size; i++)
		_array[i] = copy._array[i];
}

Array::~Array()
{
	delete[] _array;
}

Array &Array::operator=(const Array &copy)
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

int &Array::operator[](unsigned int index)
{
	if (index >= _size)
		throw Array::OutOfLimits();
	return (_array[index]);
}

unsigned int Array::size() const
{
	return (_size);
}

const char *Array::OutOfLimits::what() const throw()
{
	return ("Error: Out of limits");
}
