/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 16:41:44 by lunagda           #+#    #+#             */
/*   Updated: 2024/04/11 13:42:29 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main(void)
{
	ClapTrap claptrap("Claptrap");
	ScavTrap test;
	ScavTrap scavtrap("Scavtrap");

	claptrap.attack("enemy");
	claptrap.takeDamage(5);
	claptrap.beRepaired(5);
	std::cout << "ClapTrap Tests End" << std::endl << std::endl;

	scavtrap.attack("enemy2");
	scavtrap.guardGate();
	scavtrap.takeDamage(20);
	scavtrap.beRepaired(5);
	scavtrap.takeDamage(100);
	scavtrap.beRepaired(15);
	test.guardGate();

	return (0);
}
