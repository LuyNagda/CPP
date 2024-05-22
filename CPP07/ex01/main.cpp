/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 15:15:43 by lunagda           #+#    #+#             */
/*   Updated: 2024/05/22 11:51:28 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <vector>

void print(int const &i)
{
	std::cout << i << std::endl;
}

int main(void)
{
	int tab[] = {0, 1, 2, 3, 4, 42, 42, 42, 42, 42};
	iter(tab, 10, print);
	return 0;
}