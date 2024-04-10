/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 16:41:44 by lunagda           #+#    #+#             */
/*   Updated: 2024/04/10 12:36:16 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int	main(void)
{
	ClapTrap claptrap("Claptrap");
	FragTrap fragtrap("Fragtrap");

	claptrap.attack("enemy");
	claptrap.takeDamage(5);
	claptrap.beRepaired(5);
	std::cout << "ClapTrap Tests End" << std::endl << std::endl;

	fragtrap.attack("enemy3");
	fragtrap.highFivesGuys();
	fragtrap.takeDamage(20);
	fragtrap.beRepaired(5);
	
	return (0);
}
