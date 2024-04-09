/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 16:42:01 by lunagda           #+#    #+#             */
/*   Updated: 2024/04/09 17:15:03 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class ClapTrap
{
	protected:
		std::string _name;
		int _hitPoints;
		int _energyPoints;
		int	_attackDamage;
	public:
		ClapTrap(std::string name);
		~ClapTrap();
		void attack(const std::string &target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};
