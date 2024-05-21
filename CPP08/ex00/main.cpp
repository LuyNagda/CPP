/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 12:44:26 by lunagda           #+#    #+#             */
/*   Updated: 2024/05/21 14:28:45 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main(void)
{
	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(5);
	try
	{
		std::vector<int>::iterator it = easyfind(vec, 3);
		std::cout << *it << std::endl;
		std::vector<int>::iterator fit = easyfind(vec, 52);
		std::cout << *fit << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: could not find" << '\n';
	}
	
	
	return (0);
}