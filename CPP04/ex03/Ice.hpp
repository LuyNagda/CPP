/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 13:30:33 by lunagda           #+#    #+#             */
/*   Updated: 2024/05/13 13:38:25 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class Ice : public AMateria
{
	public:
		Ice();
		Ice(const Ice &copy);
		virtual ~Ice();
		Ice &operator=(const Ice &copy);

		AMateria* clone() const;
		std::string const &getType() const;
		void use(ICharacter &target);
	private:
		std::string _type;
};

#endif
