/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 13:35:51 by lunagda           #+#    #+#             */
/*   Updated: 2024/05/14 14:08:05 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP

# define CURE_HPP
# include "AMateria.hpp"

class Cure : public AMateria
{
	public:
		Cure();
		Cure(const Cure &copy);
		virtual ~Cure();
		Cure &operator=(const Cure &copy);

		AMateria* clone() const;
		std::string const &getType() const;
		void use(ICharacter &target);
	private:
		std::string _type;
};

#endif
