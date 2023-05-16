/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 10:45:47 by mbocquel          #+#    #+#             */
/*   Updated: 2023/05/16 14:25:57 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Array.hpp"
#include "Array.tpp"

#define MAX_VAL 750

void	test_int_array(void)
{
	Array<int> numbers(MAX_VAL);
	int* mirror = new int[MAX_VAL];
	
	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}
	//SCOPE
	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);
	}
	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
		}
	}

	try
	{
		numbers[-2] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << ":  numbers[-2] = 0;" << std::endl;
	}
	
	try
	{
		numbers[MAX_VAL] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << ": numbers[MAX_VAL] = 0" << std::endl;
	}
	
	for (int i = 0; i < MAX_VAL; i++)
	{
		numbers[i] = rand();
	}
	
	delete [] mirror;
}

void test_string_array(void)
{
	Array<std::string> string_array(5);
	
	string_array[0] = "Coucou! ";
	string_array[1] = "comment ";
	string_array[2] = "ca ";
	string_array[3] = "va ";
	string_array[4] = "aujourd'hui ?";

	std::cout << string_array[0] 
	<< string_array[1] 
	<< string_array[2] 
	<< string_array[3] 
	<< string_array[4] 
	<< std::endl;
	try
	{
		std::cout << string_array[5] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << ": std::cout << string_array[5]" << std::endl;
	}
}

int main(void)
{
	std::cout << "test_int_array()" << std::endl;
	test_int_array();
	std::cout << std::endl;
	std::cout << "test_string_array()" << std::endl;
	test_string_array();
	
	return (0);
}
