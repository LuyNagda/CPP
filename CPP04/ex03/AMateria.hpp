/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 16:01:24 by lunagda           #+#    #+#             */
/*   Updated: 2024/05/14 14:07:39 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include <string>
# include "ICharacter.hpp"

class ICharacter;

class AMateria
{
	protected:
		std::string _type;
	public:
		AMateria();
		AMateria(const AMateria &copy);
		AMateria(std::string const & type);
		virtual ~AMateria();
		AMateria &operator=(const AMateria &copy);

		std::string const &getType() const;
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter &target);
};

#endif
