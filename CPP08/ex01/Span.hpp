/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 12:33:08 by lunagda           #+#    #+#             */
/*   Updated: 2024/05/21 13:09:38 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>

class Span
{
	private:
		unsigned int _n;
		std::vector<int> _vec;
	public:
		Span(unsigned int n);
		Span(const Span &copy);
		Span &operator=(const Span &copy);
		~Span();
		void addNumber(int number);
		void addMultipleNumbers(int n);
		int shortestSpan();
		int longestSpan();
		class SpanEmptyException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class SpanFullException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

#endif
