/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 15:14:21 by lunagda           #+#    #+#             */
/*   Updated: 2024/05/28 15:50:18 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP

# define ITER_HPP
# include <iostream>

template <typename T>
void	iter(const T *array, const size_t size, const void (*f)(T const &))
{
	for (size_t i = 0; i < size; i++)
		f(array[i]);
}

template <typename T>
void	iter(T *array, size_t size, void (*f)(T &))
{
	for (size_t i = 0; i < size; i++)
		f(array[i]);
}

#endif