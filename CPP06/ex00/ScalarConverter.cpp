/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 12:44:43 by lunagda           #+#    #+#             */
/*   Updated: 2024/05/17 14:12:01 by lunagda          ###   ########.fr       */
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

void ScalarConverter::convert(const std::string &input)
{
	displayChar(input);
	displayInt(input);
	displayFloat(input);
	displayDouble(input);
}

void displayChar(const std::string &input)
{
	std::cout << "char: ";
	try
	{
		long long i = atol(input.c_str());
		if (i < 0 || i > 255)
			throw ScalarConverter::ImpossibleException();
		if (isprint(i))
			std::cout << "'" << static_cast<char>(i) << "'" << std::endl;
		else
			throw ScalarConverter::NonDisplayableException();
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
}

void displayInt(const std::string &input)
{
	std::cout << "int: ";
	try
	{
		long long i = atol(input.c_str());
		if (i < std::numeric_limits<int>::min() || i > std::numeric_limits<int>::max())
			throw ScalarConverter::ImpossibleException();
		std::cout << static_cast<int>(i) << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
}

void displayFloat(const std::string &input)
{
	std::cout << "float: ";
	try
	{
		float i = strtold(input.c_str(), NULL);
		if (i == 0)
			std::cout << "0.0f" << std::endl;
		else
		{	
			if (i < std::numeric_limits<float>::min() || i > std::numeric_limits<float>::max())
				throw ScalarConverter::ImpossibleException();
			if (i - static_cast<int>(i) == 0)
				std::cout << static_cast<double>(i) << ".0f" << std::endl;
			else
				std::cout << static_cast<float>(i) << "f" << std::endl;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void displayDouble(const std::string &input)
{
	std::cout << "double: ";
	try
	{
		long double i = strtold(input.c_str(), NULL);
		if (i == 0)
			std::cout << "0.0" << std::endl;
		else
		{	
			if (i < std::numeric_limits<double>::min() || i > std::numeric_limits<double>::max())
				throw ScalarConverter::ImpossibleException();
			if (i - static_cast<int>(i) == 0)
				std::cout << static_cast<double>(i) << ".0" << std::endl;
			else
				std::cout << static_cast<double>(i) << std::endl;
		}
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << '\n';
	}
}

const char *ScalarConverter::ImpossibleException::what() const throw()
{
	return "impossible";
}

const char *ScalarConverter::NonDisplayableException::what() const throw()
{
	return "Non displayable";
}
