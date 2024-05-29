/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 16:14:14 by lunagda           #+#    #+#             */
/*   Updated: 2024/05/28 14:08:09 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::~PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe &copy)
{
	*this = copy;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &copy)
{
	if (this != &copy)
	{
	}
	return (*this);
}

std::vector<int> *PmergeMe::getVector()
{
	return (&_vector);
}

void PmergeMe::binaryInsertionSort(std::vector<int> &result, int element)
{
	int left = 0;
	int right = result.size() - 1;

	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		if (result[mid] == element)
		{
			result.insert(result.begin() + mid, element);
			return ;
		}
		else if (result[mid] < element)
			left = mid + 1;
		else
			right = mid - 1;
	}
	result.insert(result.begin() + left, element);
}

std::vector<int> PmergeMe::merge(std::vector<int> &left, std::vector<int> &right)
{
	std::vector<int> result = left;

	for (size_t i = 0; i < right.size(); i++)
	{
		binaryInsertionSort(result, right[i]);
	}
	return (result);
}

std::vector<int> PmergeMe::fordJohnsonAlgo(std::vector<int> &arr)
{
	if (arr.size() <= 1)
	{
		return (arr);
	}
	else if (arr.size() == 2)
	{
		if (arr[0] > arr[1])
			std::swap(arr[0], arr[1]);
		return (arr);
	}
	else if (arr.size() == 3)
	{
		if (arr[0] > arr[1])
			std::swap(arr[0], arr[1]);
		if (arr[1] > arr[2])
			std::swap(arr[1], arr[2]);
		if (arr[0] > arr[1])
			std::swap(arr[0], arr[1]);
		return (arr);
	}
	std::vector<int> left(arr.begin(), arr.begin() + 3);
	std::vector<int> right(arr.begin() + 3, arr.end());
	left = fordJohnsonAlgo(left);
	right = fordJohnsonAlgo(right);
	_vector = merge(left, right);
	return (_vector);
}

void PmergeMe::printVector()
{
	for (std::vector<int>::iterator it = _vector.begin(); it != _vector.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

void PmergeMe::setVector(char **av)
{
	for (int i = 1; av[i]; i++)
	{
		_vector.push_back(std::atoi(av[i]));
	}
}

std::deque<int> *PmergeMe::getDeque()
{
	return (&_deque);
}

void PmergeMe::binaryInsertionSort(std::deque<int> &result, int element)
{
	int left = 0;
	int right = result.size() - 1;

	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		if (result[mid] == element)
		{
			result.insert(result.begin() + mid, element);
			return ;
		}
		else if (result[mid] < element)
			left = mid + 1;
		else
			right = mid - 1;
	}
	result.insert(result.begin() + left, element);
}

std::deque<int> PmergeMe::merge(std::deque<int> &left, std::deque<int> &right)
{
	std::deque<int> result = left;

	for (size_t i = 0; i < right.size(); i++)
	{
		binaryInsertionSort(result, right[i]);
	}
	return (result);
}

std::deque<int> PmergeMe::fordJohnsonAlgo(std::deque<int> &arr)
{
	if (arr.size() <= 1)
	{
		return (arr);
	}
	else if (arr.size() == 2)
	{
		if (arr[0] > arr[1])
			std::swap(arr[0], arr[1]);
		return (arr);
	}
	else if (arr.size() == 3)
	{
		if (arr[0] > arr[1])
			std::swap(arr[0], arr[1]);
		if (arr[1] > arr[2])
			std::swap(arr[1], arr[2]);
		if (arr[0] > arr[1])
			std::swap(arr[0], arr[1]);
		return (arr);
	}
	std::deque<int> left(arr.begin(), arr.begin() + 3);
	std::deque<int> right(arr.begin() + 3, arr.end());
	left = fordJohnsonAlgo(left);
	right = fordJohnsonAlgo(right);
	_deque = merge(left, right);
	return (_deque);
}

void PmergeMe::printDeque()
{
	for (std::deque<int>::iterator it = _deque.begin(); it != _deque.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

void PmergeMe::setDeque(char **av)
{
	for (int i = 1; av[i]; i++)
	{
		_deque.push_back(std::atoi(av[i]));
	}
}

int	PmergeMe::checkArgs(char **av)
{
	std::vector<long long int> arr;
	
	for (int i = 1; av[i]; i++)
	{
		for (int j = 0; av[i][j]; j++)
		{
			if (av[i][j] < '0' || av[i][j] > '9')
				return (1);
		}
		arr.push_back(std::atoll(av[i]));
	}
	for (size_t i = 0; i < arr.size() - 1; i++)
	{
		if (arr[i] < 0 || arr[i] > 2147483647)
			return (1);
	}
	return (0);
}
