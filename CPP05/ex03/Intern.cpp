/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 16:04:04 by lunagda           #+#    #+#             */
/*   Updated: 2024/05/22 11:36:09 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

const std::string Intern::names[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
const CF Intern::forms[3] = {&Intern::ShrubberyCreation, &Intern::RobotomyRequest, &Intern::PresidentialPardon};
	
Intern::Intern() {}

Intern::Intern(Intern const & obj)
{
	*this = obj;
}

Intern::~Intern() {}

Intern &Intern::operator=(Intern const & obj)
{
	if (this == &obj)
		return (*this);
	return (*this);
}

Form *Intern::ShrubberyCreation(const std::string &target) const
{
	return(new ShrubberyCreationForm(target));
}

Form *Intern::RobotomyRequest(const std::string &target) const
{
	return(new RobotomyRequestForm(target));
}

Form *Intern::PresidentialPardon(const std::string &target) const
{
	return(new PresidentialPardonForm(target));
}
Form *Intern::makeForm(std::string const name, std::string const target)
{
	for (int i = 0; i < 3; i++)
	{
		if (name == names[i])
			return ((this->*forms[i])(target));
	}
	throw Intern::FormNotFoundException();
}

const char *Intern::FormNotFoundException::what() const throw()
{
	return ("Form not found");
}