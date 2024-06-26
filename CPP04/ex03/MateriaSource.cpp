/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 13:33:04 by lunagda           #+#    #+#             */
/*   Updated: 2024/05/14 14:10:03 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "AMateria.hpp"

MateriaSource::MateriaSource()
{
	std::cout << "MateriaSource was created" << std::endl;
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = 0;
}

MateriaSource::MateriaSource(MateriaSource const &copy)
{
	for (int i = 0; i < 4; i++)
	{
		if (copy._inventory[i])
			(this->_inventory)[i] = (copy._inventory[i])->clone();
	}
	std::cout << "MateriaSource was created from a copy" << std::endl;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if ((this->_inventory)[i])
			delete (this->_inventory)[i];
	}
	std::cout << "MateriaSource was destroyed" << std::endl;
}

MateriaSource &MateriaSource::operator=(MateriaSource const &copy)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i])
			delete this->_inventory[i];
		if (copy._inventory[i])
			this->_inventory[i] = copy._inventory[i];
	}
	return (*this);
}

void MateriaSource::learnMateria(AMateria *m)
{
	int i = 0;
	
	while (this->_inventory[i] != 0 && i < 4)
		i++;
	if (i >= 4)
	{
		std::cout << "Can't learn more than 4 Materia" << std::endl;
		return ;
	}
	(this->_inventory)[i] = m;
	std::cout << "Materia" << m->getType() << " learned" << std::endl;
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	int i = 0;

	while (this->_inventory[i] != 0 && i < 4)
		i++;
	if (i >= 4 || !(this->_inventory)[i])
	{
		std::cout << type << " materia does not exist" << std::endl;
		return (NULL);
	}
	std::cout << "Materia " << type << " created\n";
	return (((this->_inventory)[i])->clone());
}
