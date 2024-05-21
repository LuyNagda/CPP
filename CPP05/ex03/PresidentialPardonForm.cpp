/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:39:17 by lunagda           #+#    #+#             */
/*   Updated: 2024/05/21 16:17:40 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): Form("PresidentialPardonForm", 25, 5), _target("default")
{
	std::cout << "Presidential Default constructor called\n";
}

PresidentialPardonForm::PresidentialPardonForm(std::string target): Form("PresidentialPardonForm", 25, 5), _target(target)
{
	std::cout << "Presidential constructor for target " << target << " called\n";
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy)
{
	std::cout << "PresidentialPardonForm copy constructor called\n";
	*this = copy;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm destructor " << this->_name << " called\n";
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &copy)
{
	std::cout << "PresidentialPardonForm assignation operator called\n";
	if (this == &copy)
		return *this;
	return *this;
}

std::string PresidentialPardonForm::getTarget(void) const
{
	return (this->_target);
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if ((int)executor.getGrade() > this->getGradeToExecute())
		throw (Bureaucrat::GradeTooLowException());
	else if (!this->getSigned())
		throw (Form::FormNotSignedException());
	else
		std::cout << this->getTarget() << " has been pardoned by Zafod Beeblebrox\n";
}

Form *PresidentialPardonForm::makeForm(Form *form, std::string const name, std::string const target)
{
	if (form == NULL && name == "presidential pardon")
		return (new PresidentialPardonForm(target));
	return (form);
}