/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 16:13:41 by lunagda           #+#    #+#             */
/*   Updated: 2024/05/28 14:04:27 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char **av)
{
	PmergeMe p;
	PmergeMe p2;
	std::vector<int> *arr;
	std::deque<int> *deq;

	if (ac < 2)
	{
		std::cout << "Usage: ./pmergeMe [int1] [int2] [int3] ..." << std::endl;
		return (1);
	}
	if (p.checkArgs(av) == 1)
	{
		std::cout << "Error: Invalid argument(s)" << std::endl;
		return (1);
	}
	p.setVector(av);
	p2.setDeque(av);
	arr = p.getVector();
	deq = p2.getDeque();
	std::cout << "Before: ";
	p.printVector();
	std::clock_t start = std::clock();
	p.fordJohnsonAlgo(*arr);
	std::clock_t end = std::clock();
	std::cout << "After:  ";
	p.printVector();
	double elapsed_time = ((double)(end - start) / CLOCKS_PER_SEC) * 1000.0;
	std::cout << "Time to process a range of " << arr->size() << " elements with std::vector : " << elapsed_time << " ms" << std::endl;
	start = std::clock();
	p2.fordJohnsonAlgo(*deq);
	end = std::clock();
	elapsed_time = ((double)(end - start) / CLOCKS_PER_SEC) * 1000.0;
	std::cout << "Time to process a range of " << arr->size() << " elements with std::deque : " << elapsed_time << " ms" << std::endl;
	return (0);
}