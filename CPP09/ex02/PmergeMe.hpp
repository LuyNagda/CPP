/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 16:14:23 by lunagda           #+#    #+#             */
/*   Updated: 2024/05/28 14:04:37 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <string>
# include <vector>
# include <deque>
# include <cstdlib>
# include <ctime>

class PmergeMe
{
	private:
		std::vector<int> _vector;
		std::deque<int>	_deque;
	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe(const PmergeMe &copy);
		PmergeMe &operator=(const PmergeMe &copy);
		int checkArgs(char **av);
		std::vector<int> *getVector();
		void setVector(char **av);
		void printVector();
		std::vector<int> fordJohnsonAlgo(std::vector<int> &arr);
		void binaryInsertionSort(std::vector<int> &result, int element);
		std::vector<int> merge(std::vector<int> &left, std::vector<int> &right);
		std::deque<int> *getDeque();
		void setDeque(char **av);
		void printDeque();
		std::deque<int> fordJohnsonAlgo(std::deque<int> &arr);
		void binaryInsertionSort(std::deque<int> &result, int element);
		std::deque<int> merge(std::deque<int> &left, std::deque<int> &right);
};

#endif
