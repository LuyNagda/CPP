/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 14:39:57 by lunagda           #+#    #+#             */
/*   Updated: 2024/02/01 14:46:17 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type): _type(type)
{
	
}

Weapon::~Weapon(void)
{
}

const std::string	&Weapon::getType(void)
{
	return(this->_type);
}

void	Weapon::setType(std::string type)
{
	this->_type = type;
}
