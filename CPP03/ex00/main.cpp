/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 16:41:44 by lunagda           #+#    #+#             */
/*   Updated: 2024/04/10 13:16:06 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap test;
	ClapTrap claptrap("Claptrap");

	claptrap.attack("enemy");
	claptrap.takeDamage(5);
	claptrap.beRepaired(5);
	test.beRepaired(1);
	for (int i = 0; i < 12; i++)
		test.attack("enemy");
	test.beRepaired(2);
	return (0);
}
