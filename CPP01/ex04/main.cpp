/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 15:44:17 by lunagda           #+#    #+#             */
/*   Updated: 2024/03/06 16:55:31 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>

void	replace_string(const std::string filename, const std::string s1, const std::string s2)
{
	std::ifstream	file(filename.c_str());
	std::string		newfilename = filename + ".replace";
	std::ofstream	outputFile(newfilename.c_str());
	std::string		line;
	std::string		suffix;
	size_t			pos;

	if (!file.is_open() || !outputFile.is_open())
		std::cerr << "Error opening file." << std::endl;
	else
	{
		while (getline(file, line))
		{
			int	last = 0;
			while ((pos = line.find(s1, last)) != std::string::npos)
			{
				suffix = line.substr(pos + s1.size());
				line.erase(pos);
				line += s2 + suffix;
				last = pos + s2.size();
			}
			outputFile << line;
			if (!file.eof())
				outputFile << std::endl;
		}
		file.close();
		outputFile.close();
	}
}

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "Error: Invalid number of arguments" << std::endl;
		return (1);
	}
	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	replace_string(filename, s1, s2);
	
	return (0);
}
