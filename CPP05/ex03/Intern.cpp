/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 16:04:04 by lunagda           #+#    #+#             */
/*   Updated: 2024/05/21 16:07:05 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

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

Form *Intern::makeForm(std::string const name, std::string const target)
{
	Form *form = NULL;
	
	form = Form::makeForm(name, target);
	if (!form)
		throw Intern::FormNotFoundException();
	return (form);
}

const char *Intern::FormNotFoundException::what() const throw()
{
	return ("Form not found");
}