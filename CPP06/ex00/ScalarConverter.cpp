/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 12:44:43 by lunagda           #+#    #+#             */
/*   Updated: 2024/05/24 16:38:54 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &src)
{
	*this = src;
}

ScalarConverter::~ScalarConverter()
{
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &src)
{
	(void)src;
	return (*this);
}

bool checkInt(const std::string input)
{
	if (!isdigit(input[0]) && input[0] != '-' && input[0] != '+')
		return (false);
	if (input.length() == 1 && !isdigit(input[0]))
		return (false);
	for (size_t i = 1; i < input.length(); i++)
	{
		if (!isdigit(input[i]))
			return (false);
	}
	return (true);
}

bool checkFloat(const std::string input)
{
	size_t i = 0;
	bool dot = false;
	
	if (!isdigit(input[0]) && input[0] != '-' && input[0] != '+')
		return (false);
	if (input.length() == 1 && !isdigit(input[0]))
		return (false);
	for (i = 1; i < input.length(); i++)
	{
		if (input[i] == '.' && !dot)
			dot = true;
		else if (!isdigit(input[i]))
		{
			if (i == input.length() - 1 && input[i] == 'f')
				return (true);
			return (false);
		}
	}
	return (dot);
}

bool checkDouble(const std::string input)
{
	size_t i = 0;
	bool dot = false;
	
	if (!isdigit(input[0]) && input[0] != '-' && input[0] != '+')
		return (false);
	if (input.length() == 1 && !isdigit(input[0]))
		return (false);
	for (i = 1; i < input.length(); i++)
	{
		if (input[i] == '.' && !dot)
			dot = true;
		else if (!isdigit(input[i]))
			return (false);
	}
	return (dot);
}

bool checkChar(const std::string input)
{
	if (input.length() == 3 && input[0] == '\'' && input[2] == '\'')
		return (true);
	return (false);
}

t_type checkException(const std::string input)
{
	if (!input.compare("-inff") || !input.compare("+inff") || !input.compare("nanf"))
		return (FLOAT);
	if (!input.compare("-inf") || !input.compare("+inf") || !input.compare("nan"))
		return (DOUBLE);
	return (UNKNOWN);
}

t_type getType(const std::string input)
{
	t_type type = checkException(input);

	if (type != UNKNOWN)
		return (type);
	if (checkInt(input))
		return (INT);
	if (checkFloat(input))
		return (FLOAT);
	if (checkDouble(input))
		return (DOUBLE);
	if (checkChar(input))
		return (CHAR);
	return (UNKNOWN);
}

void ScalarConverter::convert(const std::string &input)
{
	t_type type = getType(input);
	converter converter[4] = {&displayChar, &displayInt, &displayFloat, &displayDouble};
	
	if (type == UNKNOWN)
	{
		type = checkException(input);
		if (type == UNKNOWN)
		{
			std::cerr << "Unknown type" << std::endl;
			return;
		}
	}
	else
		return (converter[type](input));
}

void displayChar(const std::string &input)
{
	char c = input[1];

	if (static_cast<int>(c) < 32 || static_cast<int>(c) > 126)
		std::cout << "Impossible" << std::endl;
	if (isprint(c))
		std::cout << "char: " << "'" << static_cast<char>(c) << "'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

void displayInt(const std::string &input)
{
	double d = strtod(input.c_str(), NULL);

	if (d < 0. || d > 255.)
		std::cout << "char: Overflow" << std::endl;
	else if (d < 32. || d > 126.)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: " << "'" << static_cast<char>(d) << "'" << std::endl;
	if (d < static_cast<double>(std::numeric_limits<int>::min()) || d > static_cast<double>(std::numeric_limits<int>::max()))
		std::cout << "int: Overflow" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(d) << std::endl;
	std::cout << "float: " << static_cast<float>(d) << std::endl;
	std::cout << "double: " << static_cast<double>(d) << std::endl;
}

void displayFloat(const std::string &input)
{
	double d = strtod(input.c_str(), NULL);

	if (!input.compare("nanf"))
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << static_cast<float>(d) << std::endl;
		std::cout << "double: " << static_cast<double>(d) << std::endl;
		return;
	}
	if (d < 0. || d > 255.)
		std::cout << "char: Overflow" << std::endl;
	else if (d < 32. || d > 126.)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: " << "'" << static_cast<char>(d) << "'" << std::endl;
	if (d < static_cast<double>(std::numeric_limits<int>::min()) || d > static_cast<double>(std::numeric_limits<int>::max()))
		std::cout << "int: Overflow" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(d) << std::endl;
	std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(d) << std::endl;
}

void displayDouble(const std::string &input)
{
	double d = strtod(input.c_str(), NULL);

	if (!input.compare("nan"))
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << static_cast<float>(d) << std::endl;
		std::cout << "double: " << static_cast<double>(d) << std::endl;
		return;
	}
	if (d < 0. || d > 255.)
		std::cout << "char: Overflow" << std::endl;
	else if (d < 32. || d > 126.)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: " << "'" << static_cast<char>(d) << "'" << std::endl;
	if (d < static_cast<double>(std::numeric_limits<int>::min()) || d > static_cast<double>(std::numeric_limits<int>::max()))
		std::cout << "int: Overflow" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(d) << std::endl;
	std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(d) << std::endl;
}
