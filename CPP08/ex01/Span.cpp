/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 12:37:41 by lunagda           #+#    #+#             */
/*   Updated: 2024/05/21 13:09:26 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int n) : _n(n)
{
}

Span::Span(const Span &copy)
{
	*this = copy;
}

Span &Span::operator=(const Span &copy)
{
	if (this != &copy)
	{
		_n = copy._n;
		_vec = copy._vec;
	}
	return *this;
}

Span::~Span()
{
}

void Span::addNumber(int number)
{
	if (_vec.size() == _n)
		throw SpanFullException();
	_vec.push_back(number);
}

void Span::addMultipleNumbers(int n)
{
	for (int i = 0; i < n; i++)
	{
		if (_vec.size() == _n)
			throw SpanFullException();
		_vec.push_back(rand() % n);
	}
}

int Span::shortestSpan()
{
	if (_vec.size() <= 1)
		throw SpanEmptyException();
	std::vector<int> tmp = _vec;
	std::sort(tmp.begin(), tmp.end());
	int min = tmp[1] - tmp[0];
	for (unsigned int i = 1; i < tmp.size() - 1; i++)
	{
		if (tmp[i + 1] - tmp[i] < min)
			min = tmp[i + 1] - tmp[i];
	}
	return min;
}

int	Span::longestSpan()
{
	if (_vec.size() <= 1)
		throw SpanEmptyException();
	std::vector<int> tmp = _vec;
	std::sort(tmp.begin(), tmp.end());
	return tmp[tmp.size() - 1] - tmp[0];
}

const char *Span::SpanFullException::what() const throw()
{
	return "Error: Span is full";
}

const char *Span::SpanEmptyException::what() const throw()
{
	return "Error: Span is empty";
}
