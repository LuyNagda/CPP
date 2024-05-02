/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 11:30:15 by lunagda           #+#    #+#             */
/*   Updated: 2024/05/02 12:27:43 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try
	{
		Bureaucrat b1("b1", 1);
		Bureaucrat b2("b2", 150);
		Form f1("f1", 1, 1);
		Form f2("f2", 150, 150);
		b2.signForm(f1);
		std::cout << f1;
		b1.signForm(f1);
		std::cout << f1;
		b1.signForm(f2);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
