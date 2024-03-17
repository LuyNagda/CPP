/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luynagda <luynagda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 14:39:48 by lunagda           #+#    #+#             */
/*   Updated: 2024/03/17 10:15:02 by luynagda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name): _weapon(NULL)
{
	this->_name = name;
	std::cout << "HumanB " << name << " created with no weapon" << std::endl;
}

HumanB::~HumanB(void)
{
	std::cout << "HumanB " << this->_name << " destroyed" << std::endl;
}

void	HumanB::attack(void)
{
	if (this->_weapon == NULL)
	{
		std::cout << this->_name << " has no weapon" << std::endl;
		return ;
	}
	std::cout << this->_name << " attacks with his " << \
		this->_weapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
}
