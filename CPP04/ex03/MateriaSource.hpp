/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 13:29:33 by lunagda           #+#    #+#             */
/*   Updated: 2024/05/14 14:07:53 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	public:
		MateriaSource();
		MateriaSource(MateriaSource const &copy);
		~MateriaSource();
		MateriaSource &operator=(MateriaSource const &copy);
		void learnMateria(AMateria *m);
		AMateria *createMateria(std::string const &type);
	private:
		AMateria *(_inventory[4]);
};

#endif
