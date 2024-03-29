/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 14:15:38 by lunagda           #+#    #+#             */
/*   Updated: 2024/02/01 14:30:08 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name);

int	main(void)
{
	int	size;

	size = 20;
	Zombie	*horde = zombieHorde(size, "OK");
	for (int i = 0; i < size; i++)
		horde[i].announce();
	delete [] horde;
}