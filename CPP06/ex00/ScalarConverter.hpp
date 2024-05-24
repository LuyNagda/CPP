/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 12:43:13 by lunagda           #+#    #+#             */
/*   Updated: 2024/05/24 16:31:40 by lunagda          ###   ########.fr       */
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
};

typedef enum		e_type
{
	CHAR, INT, FLOAT, DOUBLE, UNKNOWN
}					t_type;

bool checkInt(const std::string input);
bool checkFloat(const std::string input);
bool checkDouble(const std::string input);
bool checkChar(const std::string input);
t_type getType(const std::string input);
t_type checkException(const std::string input);
void displayChar(const std::string &input);
void displayInt(const std::string &input);
void displayFloat(const std::string &input);
void displayDouble(const std::string &input);
typedef				void (*converter)(std::string const& str);

#endif
