/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 13:07:03 by lunagda           #+#    #+#             */
/*   Updated: 2024/05/23 14:23:11 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <string>
# include <map>
# include <fstream>
# include <sstream>
# include <cstdlib>
# include <limits>
# include <algorithm>

class Btc
{
	private:
		std::map <std::string, float> data;
	public:
		Btc();
		~Btc();
		Btc(const Btc &copy);
		Btc &operator=(const Btc &copy);
		void	setData();
		void	readInput(char *filename);

		std::map<std::string, float> getData();
		std::string *splitData(std::string str, char delimiter);
		int	check_date(int year, int month, int day);
		int	check_data(std::string date, std::string value);
		double	findValue(std::string date);
};


#endif
