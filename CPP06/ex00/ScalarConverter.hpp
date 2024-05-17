/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 12:43:13 by lunagda           #+#    #+#             */
/*   Updated: 2024/05/17 14:10:29 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP

# define SCALARCONVERTER_HPP
# include <iostream>
# include <string>
# include "limits.h"
# include <limits>
# include <cmath>

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &src);
		~ScalarConverter();
		ScalarConverter &operator=(const ScalarConverter &src);
	public:
		static void convert(const std::string &input);
		class ImpossibleException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class NonDisplayableException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

void displayChar(const std::string &input);
void displayInt(const std::string &input);
void displayFloat(const std::string &input);
void displayDouble(const std::string &input);

#endif
