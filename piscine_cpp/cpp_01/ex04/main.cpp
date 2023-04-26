/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 16:45:08 by mbocquel          #+#    #+#             */
/*   Updated: 2023/04/26 14:43:04 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include <string>
#include <cerrno>
#include <cstring>

int	main(int argc, char **argv)
{
	//--> Error Management
	if (argc != 4)
	{
		std::cerr << "Error: Wrong number of argument" << std::endl;
		return (1);
	}
	std::string filename = argv[1];
	if (filename.empty())
	{
		std::cerr << "Error: Wrong file name" << std::endl;
		return (1);
	}
	std::ifstream file_in(filename.c_str());
	if (file_in.fail())
	{
		std::cerr << "Error: " << filename << ": " << std::strerror(errno) << std::endl;
		return (1);
	}
	std::ofstream file_out((filename + ".replace").c_str());
	if (file_out.fail())
	{
		std::cerr << "Error: " << filename  + ".replace :" << std::strerror(errno) << std::endl;
		file_in.close();
		return (1);
	}
	//<-- end of error Management
	
	std::string str = argv[2];
	std::string str1 = argv[3];
	std::string line;
	std::size_t found;
	
	std::getline(file_in, line);
	while (1)
	{
		if (line.empty() && file_in.eof())
			break ;
		found = line.find(str);
		while (found!=std::string::npos)
		{
			file_out << line.substr(0, found);
			file_out << str1;
			line = line.substr(found + str.size(), line.size() - found - str.size());
			found = line.find(str);
		}
		file_out << line << std::endl;
		std::getline(file_in, line);
	}
	file_in.close();
	file_out.close();
	return (0);
}

