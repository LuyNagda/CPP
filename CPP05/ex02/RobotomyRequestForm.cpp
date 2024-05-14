/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:35:13 by lunagda           #+#    #+#             */
/*   Updated: 2024/05/14 16:51:45 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): Form("RobotomyRequestForm", 72, 45), target("default")
{
	std::cout << "Robotomy Default constructor called\n";
}

RobotomyRequestForm::RobotomyRequestForm(std::string target): Form("RobotomyRequestForm", 72, 45), target(target)
{
	std::cout << "Robotomy constructor for target " << target << " called\n";
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy)
{
	std::cout << "RobotomyRequestForm copy constructor called\n";
	*this = copy;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm destructor " << this->_name << " called\n";
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &copy)
{
	std::cout << "RobotomyRequestForm assignation operator called\n";
	if (this == &copy)
		return *this;
	return *this;
}

std::string RobotomyRequestForm::getTarget(void) const
{
	return (this->target);
}

static int robot_fail = 0;

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if ((int)executor.getGrade() > this->getGradeToExecute())
		throw (Bureaucrat::GradeTooLowException());
	else if (!this->getSigned())
		throw (Form::FormNotSignedException());
	else if (robot_fail++ % 2)
		std::cout << "BzzzzzzzzzzzzzZZZ" << this->getTarget() << " has been robotomized successfully\n";
	else
		std::cout << "Robotomy of " << this->getTarget() << " failed\n";
}
