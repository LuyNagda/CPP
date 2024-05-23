/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 15:11:22 by lunagda           #+#    #+#             */
/*   Updated: 2024/05/23 16:00:36 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <string>
# include <stack>
# include <sstream>
# include <cstdlib>
# include <cctype>

class RPN
{
	private:
		std::stack<int> _stack;
		std::string _input;
	public:
		RPN(std::string input);
		RPN(const RPN &copy);
		RPN &operator=(const RPN &rhs);
		~RPN();
		void calculate();
		inline std::string trim(const std::string &str);
};

#endif
