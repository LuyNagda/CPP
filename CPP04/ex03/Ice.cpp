/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 13:31:18 by lunagda           #+#    #+#             */
/*   Updated: 2024/05/13 13:38:58 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(): AMateria("ice")
{
	std::cout << "Ice default constructor called" << std::endl;
}

Ice::Ice(const Ice &copy): AMateria(copy)
{
	std::cout << "Ice copy constructor called" << std::endl;
	*this = copy;
}

Ice::~Ice()
{
	std::cout << "Ice destructor called" << std::endl;
	return ;
}

Ice &Ice::operator=(const Ice &copy)
{
	std::cout << "Ice assignation operator called" << std::endl;
	this->_type = copy._type;
	return (*this);
}

AMateria* Ice::clone() const
{
	std::cout << "Ice clone called" << std::endl;
	return (new Ice(*this));
}

std::string const &Ice::getType() const
{
	return (this->_type);
}

void Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
