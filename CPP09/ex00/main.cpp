/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 13:06:26 by lunagda           #+#    #+#             */
/*   Updated: 2024/05/23 14:06:17 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	Btc btc;

	if (argc != 2)
	{
		std::cerr << "Usage: ./btc data.csv" << std::endl;
		return (1);
	}
	try 
	{
		btc.setData();
		btc.readInput(argv[1]);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return (1);
	}
	return (0);
}
