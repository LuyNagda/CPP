/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 16:29:13 by lunagda           #+#    #+#             */
/*   Updated: 2024/05/22 12:54:49 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP

# define ARRAY_HPP
# include <iostream>

template <typename T>
class Array
{
	private:
		unsigned int	_size;
		T				*_array;
	public:
		Array();
		Array(unsigned int n);
		Array(const Array &copy);
		~Array();
		Array &operator=(const Array &copy);
		T &operator[](unsigned int index);
		unsigned int size() const;
		class OutOfLimits : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

#include "Array.tpp"

#endif
