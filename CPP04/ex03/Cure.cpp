/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 13:36:24 by lunagda           #+#    #+#             */
/*   Updated: 2024/05/13 13:38:45 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
	std::cout << "Cure default constructor called" << std::endl;
}

Cure::Cure(const Cure &copy)
{
	std::cout << "Cure copy constructor called" << std::endl;
	*this = copy;
}

Cure::~Cure()
{
	std::cout << "Cure destructor called" << std::endl;
	return ;
}

Cure &Cure::operator=(const Cure &copy)
{
	std::cout << "Cure assignation operator called" << std::endl;
	this->_type = copy._type;
	return (*this);
}

AMateria* Cure::clone() const
{
	std::cout << "Cure clone called" << std::endl;
	return (new Cure(*this));
}

std::string const &Cure::getType() const
{
	return (this->_type);
}

void Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
