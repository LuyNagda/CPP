/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 15:44:17 by lunagda           #+#    #+#             */
/*   Updated: 2024/03/04 17:16:42 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>

void	replace_string(const std::string filename, const std::string s1, const std::string s2)
{
	std::ifstream file(filename.c_str());
	std::string newfilename = filename + ".replace";
	std::ofstream outputFile(newfilename.c_str());

	if (!file.is_open() || !outputFile.is_open())
		std::cerr << "Error opening file." << std::endl;
	else
	{
		char c;
        while (file.get(c)) 
		{
            if (c == '\n') {
                outputFile << c;
            } else if (c == ' ') {
                outputFile << c;
            } else {
                std::string word;
                word += c;
                while (file.get(c) && c != ' ' && c != '\n') {
                    word += c;
                }
                if (word == s1) {
                    outputFile << s2;
                } else {
                    outputFile << word;
                }
                if (c == ' ') {
                    outputFile << c;
                }
                if (c == '\n') {
                    outputFile << c;
                }
            }
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
