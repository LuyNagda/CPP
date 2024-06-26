/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 11:30:15 by lunagda           #+#    #+#             */
/*   Updated: 2024/05/21 12:05:09 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main()
{
	try
	{
		Bureaucrat b1("b1", 1);
		std::cout << b1;
		b1.decrementGrade();
		std::cout << b1;
		b1.incrementGrade();
		b1.incrementGrade();
		std::cout << b1;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Bureaucrat b2;
		std::cout << b2;
		for (int i = 0; i < 50; i++)
			b2.incrementGrade();
		std::cout << b2;
		for (int i = 0; i < 150; i++)
			b2.decrementGrade();
		std::cout << b2;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}