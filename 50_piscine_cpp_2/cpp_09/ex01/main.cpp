/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 10:44:10 by mbocquel          #+#    #+#             */
/*   Updated: 2023/05/26 16:06:45 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <sstream>

int	main(int argc, char **argv)
{
	std::stringstream 	input;
	std::string			elem;
	RPN					my_rpn;

	if (argc < 2)
	{
		std::cout << "Error" << std::endl;
		return (1);
	}
	while (*(++argv))
		input << *argv << ' ';
	try
	{
		while (std::getline(input, elem, ' '))
		{
			if (elem.size())
				my_rpn.rpn_add(elem);
		}
		std::cout << my_rpn.result() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		return (1);
	}
	return (0);	
}
