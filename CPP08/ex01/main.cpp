/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 12:41:29 by lunagda           #+#    #+#             */
/*   Updated: 2024/05/21 13:12:51 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main(void)
{
	Span sp = Span(20000);
	std::cout <<" *********  First Test  ********* "<< std::endl;
	for (int i = 0; i < 20000; i++)
		sp.addNumber(rand() % 20000);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	std::cout << std::endl;
	{
		std::cout <<" *********  Second Test  ********* "<< std::endl;
		try
		{
			sp.addNumber(42);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		std::cout << std::endl;
	}
	{
		std::cout <<" *********  Third Test  ********* "<< std::endl;
		Span sp2 = Span(1);
		try
		{
			sp2.shortestSpan();
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		std::cout << std::endl;
	}
	{
		std::cout <<" *********  Fourth Test  ********* "<< std::endl;
		Span sp3 = Span(20000);
		sp3.addMultipleNumbers(20000);
		std::cout << sp3.shortestSpan() << std::endl;
		std::cout << sp3.longestSpan() << std::endl;
		std::cout << std::endl;
	}
	{
		std::cout <<" *********  Fifth Test  ********* "<< std::endl;
		try
		{
			Span sp4 = Span(20000);
			sp4.addMultipleNumbers(20001);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		std::cout << std::endl;
	}
	return 0;
}