/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 13:06:15 by lunagda           #+#    #+#             */
/*   Updated: 2024/05/23 15:14:19 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

Btc::Btc()
{
}

Btc::~Btc()
{
}

Btc::Btc(const Btc &copy)
{
	*this = copy;
}

Btc &Btc::operator=(const Btc &copy)
{
	if (this != &copy)
	{
		this->data = copy.data;
	}
	return (*this);
}

inline std::string trim(std::string str)
{
    str.erase(str.find_last_not_of(' ')+1);
    str.erase(0, str.find_first_not_of(' '));
    return (str);
}

std::string *Btc::splitData(std::string str, char delimiter)
{
	std::string *splitLine = new std::string[3];
	int i = 0;
	size_t index;

	for (index = str.find(delimiter); index != std::string::npos; index = str.find(delimiter))
	{
		splitLine[i] = str.substr(0, index);
		str = str.substr(index + 1);
		i++;
	}
	splitLine[i] = str.substr(index + 1);
	return (splitLine);
}

int	Btc::check_date(int year, int month, int day)
{
	if (year < 0 || month < 0 || day < 0)
		return (0);
	if (month > 12 || day > 31)
		return (0);
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
	{
		if (month == 2 && day > 29)
			return (0);
	}
	if (month == 2 && day > 28)
		return (0);
	if (month == 4 || month == 6 || month == 9 || month == 11)
	{
		if (day > 30)
			return (0);
	}
	if (year > 2024)
		return (0);
	if (year < 1990)
		return (0);
	return (1);
}

int	Btc::check_data(std::string date, std::string value)
{
	int i = 0;
	std::string *_date = new std::string[3];

	if (date.length() != 10)
	{
		std::cerr << "Error: Invalid date length => " << date << std::endl;	
		return (0);
	}
	_date = splitData(date, '-');
	if (_date[0].empty() || _date[1].empty() || _date[2].empty())
	{
		std::cerr << "Error: Invalid date format => " << date << std::endl;	
		return (0);
	}
	if (_date[0].length() != 4 || _date[1].length() != 2 || _date[2].length() != 2)
	{
		std::cerr << "Error: Invalid year length => " << _date[0] << std::endl;	
		return (0);
	}
	if (_date[1].length() != 2)
	{
		std::cerr << "Error: Invalid month length => " << _date[1] << std::endl;	
		return (0);
	}
	if (_date[2].length() != 2)
	{
		std::cerr << "Error: Invalid day length => " << _date[2] << std::endl;	
		return (0);
	}
	if (check_date(std::atoi(_date[0].c_str()), std::atoi(_date[1].c_str()), std::atoi(_date[2].c_str())) == 0)
	{
		std::cerr << "Error: Invalid date => " << date << std::endl;
		return (0);
	}
	if (value[0] == '-')
	{
		std::cerr << "Error: Not a positive number." << std::endl;
		return (0);
	}
	if (value[i] == '+')
		i++;
	while (value[i])
	{
		if (!isdigit(value[i]) && value[i] != '.')
		{
			std::cerr << "Error: Invalid value => " << value << std::endl;
			return (0);
		}
		i++;
	}
	return (1);
}

std::string subtractOneFromStr(std::string str)
{
	int str_int = std::atoi(str.c_str());
	--str_int;
	std::stringstream ss;
	ss << str_int;
	std::string temp = ss.str();
	if (temp.length() == 1)
		return ("0" + temp);
	else
		return (temp);
}

double Btc::findValue(std::string date)
{
	std::string *_date = new std::string[3];
	std::string year;
	std::string month;
	std::string day;
	std::string prev_date;

	if (data[date] != 0)
		return (data[date]);

	_date = splitData(date, '-');
	year = _date[0];
	month = _date[1];
	day = _date[2];

	day = subtractOneFromStr(day);
	while (day.compare("00"))
	{
		prev_date = year + "-" + month + "-" + day;
		if (data[prev_date] != 0)
			return (data[prev_date]);
		day = subtractOneFromStr(day);
	}
	month = subtractOneFromStr(month);
	while (month.compare("00"))
	{
		day = "31";
		while (day.compare("00"))
		{
			prev_date = year + "-" + month + "-" + day;
			if (data[prev_date] != 0)
				return (data[prev_date]);
			day = subtractOneFromStr(day);
		}
		month = subtractOneFromStr(month);
	}
	year = subtractOneFromStr(year);
	while (year.compare("00"))
	{
		month = "12";
		while (month.compare("00"))
		{
			day = "31";
			while (day.compare("00"))
			{
				prev_date = year + "-" + month + "-" + day;
				if (data[prev_date] != 0)
					return (data[prev_date]);
				day = subtractOneFromStr(day);
			}
			month = subtractOneFromStr(month);
		}
		year = subtractOneFromStr(year);
	}
	return (0);
}

void Btc::setData()
{
	std::string firstline;
	std::string line;
	std::string key;
	double value;
	std::string *splitLine = new std::string[2];

	std::ifstream dataFile;
	dataFile.open("data.csv");
	if (!dataFile.is_open())
		throw std::runtime_error("Error: Data.csv file not found.");
	std::getline(dataFile, firstline);
	while (std::getline(dataFile, line))
	{
		splitLine = splitData(line, ',');
		key = trim(splitLine[0]);
		value = std::atof(trim(splitLine[1]).c_str());
		data[key] = value;
	}
}

void Btc::readInput(char *filename)
{
	std::string firstline;
	std::string line;
	std::string key;
	double value;
	std::string *splitLine = new std::string[2];
	double converted_value;

	std::ifstream dataFile;
	dataFile.open(filename);
	if (!dataFile.is_open())
		throw std::runtime_error("Error: File not found.");
	std::getline(dataFile, firstline);
	while (std::getline(dataFile, line))
	{
		splitLine = splitData(line, '|');
		if (splitLine[0].empty() || splitLine[1].empty())
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue ;
		}
		else
		{
			key = trim(splitLine[0]);
			value = std::atof(trim(splitLine[1]).c_str());
		}
		if (check_data(key, trim(splitLine[1])) == 0)
			continue ;
		if (value > 1000)
		{
			std::cerr << "Error: too large a number." << std::endl;
			continue ;
		}
		converted_value = value * findValue(key);
		std::cout << key << " => " << value << " => " << converted_value << std::endl;
	}
}

std::map<std::string, float> Btc::getData()
{
	return (data);
}
