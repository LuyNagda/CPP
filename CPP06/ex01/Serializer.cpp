/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 13:53:02 by lunagda           #+#    #+#             */
/*   Updated: 2024/05/17 14:17:50 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer()
{
}

Serializer::Serializer(const Serializer &src)
{
	*this = src;
}

Serializer::~Serializer()
{
}

Serializer &Serializer::operator=(const Serializer &src)
{
	if (this != &src)
	{
		*this = src;
	}
	return (*this);
}

uintptr_t Serializer::serialize(Data *ptr)
{
	uintptr_t raw;

	raw = reinterpret_cast<uintptr_t>(ptr);
	return (raw);
}

Data *Serializer::deserialize(uintptr_t raw)
{
	Data *ptr;

	ptr = reinterpret_cast<Data *>(raw);
	return (ptr);
}
