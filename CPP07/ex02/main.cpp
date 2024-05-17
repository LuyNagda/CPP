/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 15:17:10 by lunagda           #+#    #+#             */
/*   Updated: 2024/05/17 16:37:57 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main()
{
	Array array(5);
	Array array2(5);

	for (unsigned int i = 0; i < array.size(); i++)
	{
		array[i] = i;
		array2[i] = i + 1;
	}
	for (unsigned int i = 0; i < array.size(); i++)
		std::cout << array[i] << " ";
	std::cout << std::endl;
	for (unsigned int i = 0; i < array2.size(); i++)
		std::cout << array2[i] << " ";
	std::cout << std::endl;
	try
	{
		array[5] = 42;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
