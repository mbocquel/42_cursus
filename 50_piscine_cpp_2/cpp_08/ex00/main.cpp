/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 11:13:07 by mbocquel          #+#    #+#             */
/*   Updated: 2023/05/22 11:56:02 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <list>

void	test_vector(void)
{
	std::vector<int>	my_vector;
	int					result = 0;

	my_vector.push_back(1);
	my_vector.push_back(2);
	my_vector.push_back(3);
	my_vector.push_back(4);
	my_vector.push_back(5);
	my_vector.push_back(6);
	my_vector.push_back(7);

	std::vector<int>::const_iterator it = my_vector.begin();
	std::cout << "Just to be sure, what do I have in my vector" << std::endl;
	while (it != my_vector.end())
	{
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;
	
	std::cout << "I am looking for a 3" << std::endl;
	try
	{
		result = easyfind< std::vector<int> >(my_vector, 3);
		std::cout << result << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << "I am looking for a 15" << std::endl;
	try
	{
		result = easyfind< std::vector<int> >(my_vector, 15);
		std::cout << result << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void	test_list(void)
{
	std::list<int>	my_list;
	int				result = 0;

	my_list.push_back(1);
	my_list.push_back(2);
	my_list.push_back(3);
	my_list.push_back(4);
	my_list.push_back(5);
	my_list.push_back(6);
	my_list.push_back(7);

	std::list<int>::const_iterator it = my_list.begin();
	std::cout << "Just to be sure, what do I have in my list" << std::endl;
	while (it != my_list.end())
	{
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;
	
	std::cout << "I am looking for a 3" << std::endl;
	try
	{
		result = easyfind< std::list<int> >(my_list, 3);
		std::cout << result << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << "I am looking for a 15" << std::endl;
	try
	{
		result = easyfind< std::list<int> >(my_list, 15);
		std::cout << result << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

int	main(void)
{
	std::cout << "---- TEST VECTOR ----" << std::endl;
	test_vector();
	std::cout << std::endl << "---- TEST LIST ----" << std::endl;
	test_list();
	return (0);	
}
