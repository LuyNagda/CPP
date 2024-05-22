/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 11:34:30 by lunagda           #+#    #+#             */
/*   Updated: 2024/05/22 11:14:13 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Form::Form() : _name("default"), _signed(false), _gradeToSign(150), _gradeToExecute(150) {}

Form::Form(int sign_grade, int exec_grade) : _name("default"), _signed(false), _gradeToSign(sign_grade), _gradeToExecute(exec_grade)
{
	std::cout << "Form Constructor called for " << this->getName() <<
	" with sign-grade of " << sign_grade << " and execution-grade of " << exec_grade <<
	std::endl;
	const int i = this->getGradeToSign();
	const int j = this->getGradeToExecute();
	if (i > 150 || j > 150)
		throw(Form::GradeTooLowException());
	else if( i < 1 || j < 1)
		throw(Form::GradeTooHighException());
}

Form::Form(std::string const name, int gradeToSign, int gradeToExecute) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw Form::GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw Form::GradeTooLowException();
}

Form::Form(Form const & obj) : _name(obj._name), _signed(obj._signed), _gradeToSign(obj._gradeToSign), _gradeToExecute(obj._gradeToExecute) {}

Form::~Form() {}

Form & Form::operator=(Form const & obj)
{
	if (this == &obj)
		return (*this);
	this->_signed = obj._signed;
	return (*this);
}

std::string Form::getName() const
{
	return (this->_name);
}

bool Form::getSigned() const
{
	return (this->_signed);
}

int Form::getGradeToSign() const
{
	return (this->_gradeToSign);
}

int Form::getGradeToExecute() const
{
	return (this->_gradeToExecute);
}

void Form::beSigned(Bureaucrat const & obj)
{
	if (this->_signed)
		return ;
	if (obj.getGrade() > this->_gradeToSign)
		throw Form::GradeTooLowException();
	if (obj.getGrade() <= this->_gradeToSign)
		this->_signed = true;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

const char* Form::FormNotSignedException::what() const throw()
{
	return ("Form not signed");
}

std::ostream & operator<<(std::ostream & os, Form const & obj)
{
	os << "Form " << obj.getName() << " is ";
	if (obj.getSigned())
		os << "signed";
	else
		os << "not signed" << " and requires grade " << obj.getGradeToSign() << " to sign and grade " << obj.getGradeToExecute() << " to execute";
	os << std::endl;
	return (os);
}
