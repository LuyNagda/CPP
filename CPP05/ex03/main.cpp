/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 11:30:15 by lunagda           #+#    #+#             */
/*   Updated: 2024/05/21 16:05:43 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"

int main(void)
{
	Intern		bob;
	Form		*form;
	Bureaucrat	karen("Karen", 50);

	// Test how all forms are created properly execpt for the last one
	try
	{
		form = bob.makeForm("robotomy request", "Alice");
		delete form;
		form = bob.makeForm("shrubbery creation", "Charlie");
		delete form;
		form = bob.makeForm("presidential pardon", "David");
		delete form;
		form = bob.makeForm("random request", "Elisa");
		delete form;
	}
	catch (std::exception &e)
	{
		std::cout << "Caught exception: " << e.what() << std::endl;
	}

	// Test some Actions with available form
	std::cout << "------------------------------------" << std::endl;
	form = bob.makeForm("shrubbery creation", "Fred");
	form->beSigned(karen);
	karen.executeForm(*form);
	delete form;
	std::cout << "------------------------------------" << std::endl;
	form = bob.makeForm("presidential pardon", "Georgia");
	karen.signForm(*form);
	karen.executeForm(*form);
	delete form;
	return (0);
}
