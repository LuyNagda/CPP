/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luynagda <luynagda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 10:26:45 by luynagda          #+#    #+#             */
/*   Updated: 2024/03/17 10:32:27 by luynagda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	harl_translate(char *argv)
{
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	
	for (int i = 0; i < 4; i++)
	{
		if (levels[i] == argv)
			return (i);
	}
	return (-1);
}

void	harl_switch(char *argv, Harl &harl)
{
	switch (harl_translate(argv))
	{
		case 0:
			harl.complain("DEBUG");
		case 1:
			harl.complain("INFO");
		case 2:
			harl.complain("WARNING");
		case 3:
			harl.complain("ERROR");
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}

int	main(int argc, char **argv)
{
	Harl harl;

	if (argc != 2)
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	else
		harl_switch(argv[1], harl);
	return (0);
}
