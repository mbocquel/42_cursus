/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 16:45:08 by mbocquel          #+#    #+#             */
/*   Updated: 2023/04/23 16:09:13 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>

int	maim(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Wrong number of argument" << std::endl;
		return (1);
	}
	
	std::ifstream file(argv[1]);
	std::string str = argv[2];
	std::string str1 = argv[3];
	std::string line;
	std::size_t found;

	std::getline(file, line);
	while (!line.empty())
	{
		found = line.find(str);
		while (found!=std::string::npos)
		{
			
		}
	}
	
	
	
}
