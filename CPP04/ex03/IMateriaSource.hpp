/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 13:28:25 by lunagda           #+#    #+#             */
/*   Updated: 2024/05/14 14:08:07 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIALSOURCE_HPP
#define IMATERIALSOURCE_HPP

#include "AMateria.hpp"

class IMateriaSource
{
	public:
		virtual ~IMateriaSource() {}
		virtual void learnMateria(AMateria *m) = 0;
		virtual AMateria *createMateria(std::string const &type) = 0;
};

#endif
