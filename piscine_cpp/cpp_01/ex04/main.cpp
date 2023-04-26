/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 16:45:08 by mbocquel          #+#    #+#             */
/*   Updated: 2023/04/26 16:43:59 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include <string>
#include <cerrno>
#include <cstring>

int	ft_error_msg(std::string filename)
{
	std::cerr << "Error: " << filename << " :" << std::strerror(errno) << std::endl;
	return (1);
}

int	ft_replace(std::string str, std::string str_replace, std::string filename)
{
	std::string line;
	std::size_t found;
	std::ifstream file_in(filename.c_str());
	
	if (file_in.fail())
		return (ft_error_msg(filename));
	std::ofstream file_out((filename + ".replace").c_str());
	if (file_out.fail())
	{
		file_in.close();
		return (ft_error_msg(filename + ".replace"));
	}
	std::getline(file_in, line);
	while (1)
	{
		if (line.empty() && file_in.eof())
			break ;
		found = line.find(str);
		while (found!=std::string::npos)
		{
			file_out << line.substr(0, found);
			file_out << str_replace;
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

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "Error: Wrong number of argument" << std::endl;
		return (1);
	}
	std::string filename = argv[1];
	std::string str = argv[2];
	std::string str_replace = argv[3];
	
	if (filename.empty())
	{
		std::cerr << "Error: Wrong file name" << std::endl;
		return (1);
	}
	if (ft_replace(str, str_replace, filename))
		return (1);
	return (0);
}
