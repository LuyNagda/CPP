/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luynagda <luynagda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 14:39:59 by lunagda           #+#    #+#             */
/*   Updated: 2024/03/17 10:13:11 by luynagda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP

# define WEAPON_HPP

# include <iostream>

class Weapon
{
	private:
		std::string _type;
	public:
		Weapon(std::string type);
		~Weapon(void);
		const std::string	&getType(void);
		void				setType(std::string type);
};

#endif
