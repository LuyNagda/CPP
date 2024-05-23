/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 15:11:13 by lunagda           #+#    #+#             */
/*   Updated: 2024/05/23 16:08:59 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(std::string input) : _input(input)
{
}

RPN::~RPN()
{
}

RPN::RPN(const RPN &copy)
{
	*this = copy;
}

RPN &RPN::operator=(const RPN &rhs)
{
	if (this != &rhs)
	{
		this->_input = rhs._input;
	}
	return (*this);
}


inline std::string RPN::trim(const std::string &str)
{
	size_t first = str.find_first_not_of(' ');
	size_t last = str.find_last_not_of(' ');
	return (str.substr(first, (last - first + 1)));
}

void RPN::calculate()
{
	std::istringstream iss(_input);
	std::string token;
	int	number;
	int	count = 0;
	int	operand = 0;
	
	if (_input.empty())
	{
		std::cerr << "Error: Empty input" << std::endl;
		return ;
	}
	_input = trim(_input);
	while (iss >> token)
	{
		if (token == "+" || token == "-" || token == "*" || token == "/")
		{
			if (_stack.size() < 2)
			{
				std::cerr << "Error: Not enough operands" << std::endl;
				return ;
			}
			int a = _stack.top();
			_stack.pop();
			int b = _stack.top();
			_stack.pop();
			if (token == "+")
				_stack.push(b + a);
			else if (token == "-")
				_stack.push(b - a);
			else if (token == "*")
				_stack.push(b * a);
			else if (token == "/")
			{
				if (a == 0)
				{
					std::cerr << "Error: Division by zero" << std::endl;
					return ;
				}
				_stack.push(b / a);
			}
			operand++;
		}
		else
		{
			number = std::atoi(token.c_str());
			if (number < 0 || number > 9 || token.find(".") != std::string::npos)
			{
				std::cerr << "Error: Invalid number" << std::endl;
				return ;
			}
			_stack.push(number);
			count++;
		}
	}
	if (count == operand + 1 && _stack.size() == 1 && operand > 0)
		std::cout << _stack.top() << std::endl;
	else
		std::cerr << "Error: Invalid expression" << std::endl;
}
