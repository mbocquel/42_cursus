/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 11:21:48 by mbocquel          #+#    #+#             */
/*   Updated: 2023/05/23 15:19:53 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <ctime>
#include <cstdlib>
#include <fstream>

int	randomnumber(void)
{
	return (std::rand()%1000000000);
}

std::vector<int> generate_vector_filled(unsigned int N)
{
	std::vector<int>	myvector(N);
	
	std::srand(unsigned(std::time(0)));
	std::generate(myvector.begin(), myvector.end(), randomnumber);
	return (myvector);
}

std::list<int> generate_list_filled(unsigned int N)
{
	std::list<int>	my_list(N);
	
	std::srand(unsigned(std::time(0)) + 1);
	std::generate(my_list.begin(), my_list.end(), randomnumber);
	return (my_list);
}

std::set<int> generate_set_filled(unsigned int N)
{
	std::vector<int>	myvector(N);
	std::set<int>		my_set;
	
	std::srand(unsigned(std::time(0)) + 15);
	std::generate(myvector.begin(), myvector.end(), randomnumber);
	my_set.insert(myvector.begin(), myvector.end());
	return (my_set);
}

std::deque<int> generate_deque_filled(unsigned int N)
{
	std::deque<int>	my_deque(N);
	
	std::srand(unsigned(std::time(0)) + 2);
	std::generate(my_deque.begin(), my_deque.end(), randomnumber);
	return (my_deque);
}


void	test_add_number_individuel(void)
{
	std::cout << "\e[34mTest fonctionnel:\e[0m" << std::endl;
	try
	{
		Span	span_1(5);
		
		span_1.addNumber(6);
		span_1.addNumber(3);
		span_1.addNumber(17);
		span_1.addNumber(9);
		span_1.addNumber(11);
		std::cout << "span_1:";
		span_1.printSet(std::cout);
		std::cout << "span_1.shortestSpan(): " << span_1.shortestSpan() << std::endl;
		std::cout << "span_1.longestSpan(): " << span_1.longestSpan() << std::endl;
	}
	catch (const std::exception &e )
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl << "\e[34mTest avec exception Too many number:\e[0m" << std::endl;
	try
	{
		Span	span_2(5);
		
		span_2.addNumber(6);
		span_2.addNumber(3);
		span_2.addNumber(17);
		span_2.addNumber(9);
		span_2.addNumber(11);
		std::cout << "span_2:";
		span_2.printSet(std::cout);
		std::cout << "Je rajoute une valeur" << std::endl;
		span_2.addNumber(25);
	}
	catch (const std::exception &e )
	{
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << std::endl << "\e[34mTest avec exception Not enough number:\e[0m" << std::endl;
	try
	{
		Span	span_3(5);
		
		span_3.addNumber(6);
		std::cout << "span_3:";
		span_3.printSet(std::cout);
		std::cout << "span_3.shortestSpan(): " << span_3.shortestSpan() << std::endl;
	}
	catch (const std::exception &e )
	{
		std::cerr << std::endl << e.what() << std::endl;
	}
}

void	test_add_number_set(void)
{
	std::set<int>	my_set = generate_set_filled(20000);
	
	std::cout << "\e[34mTest with a Span initialisation using a set of 20 000 random values:\e[0m" << std::endl;
	Span	span_1_set(20000);
	try
	{
		span_1_set.addNumber(my_set.begin(), my_set.end());
		
		std::ofstream file_out1("span_1_set_content.txt");
		if (!file_out1.fail())
		{
			span_1_set.printSet(file_out1);
			file_out1.close();
			std::cout << "span_1_set content visible in file span_1_set_content.txt" << std::endl;
		}
		
		std::ofstream file_out2("span_1_set_distance.txt");
		if (!file_out2.fail())
		{
			span_1_set.printSpan(file_out2);
			file_out2.close();
			std::cout << "span_1_set distance visible in file span_1_set_distance.txt" << std::endl;
		}
		
		std::cout << "span_1_set.shortestSpan(): " << span_1_set.shortestSpan() << std::endl;
		std::cout << "span_1_set.longestSpan(): " << span_1_set.longestSpan() << std::endl;
	}
	catch (const std::exception &e )
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl << "\e[34mTest too many numbers in the vector :\e[0m" << std::endl;
	Span	span_2_set(100);
	try
	{
		span_2_set.addNumber(my_set.begin(), my_set.end());
	}
	catch (const std::exception &e )
	{
		std::cerr << e.what() << std::endl;
	}
}

void	test_add_number_vector(void)
{
	std::vector<int>	my_vector = generate_vector_filled(20000);
	
	std::cout << "\e[34mTest with a Span initialisation using a vector of 20 000 random values:\e[0m" << std::endl;
	Span	span_1_vector(20000);
	try
	{
		span_1_vector.addNumber(my_vector.begin(), my_vector.end());
		
		std::ofstream file_out1("span_1_vector_content.txt");
		if (!file_out1.fail())
		{
			span_1_vector.printSet(file_out1);
			file_out1.close();
			std::cout << "span_1_vector content visible in filespan_1_vector_content.txt" << std::endl;
		}
		
		std::ofstream file_out2("span_1_vector_distance.txt");
		if (!file_out2.fail())
		{
			span_1_vector.printSpan(file_out2);
			file_out2.close();
			std::cout << "span_1_vector distance visible in file span_1_vector_distance.txt" << std::endl;
		}
		
		std::cout << "span_1_vector.shortestSpan(): " << span_1_vector.shortestSpan() << std::endl;
		std::cout << "span_1_vector.longestSpan(): " << span_1_vector.longestSpan() << std::endl;
	}
	catch (const std::exception &e )
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl << "\e[34mTest too many numbers in the vector :\e[0m" << std::endl;
	Span	span_2_vector(100);
	try
	{
		span_2_vector.addNumber(my_vector.begin(), my_vector.end());
	}
	catch (const std::exception &e )
	{
		std::cerr << e.what() << std::endl;
	}
}

void	test_add_number_list(void)
{
	std::list<int>	my_list = generate_list_filled(20000);
	
	std::cout << "\e[34mTest with a Span initialisation using a list of 20 000 random values:\e[0m" << std::endl;
	Span	span_1_list(20000);
	try
	{
		span_1_list.addNumber(my_list.begin(), my_list.end());
		
		std::ofstream file_out1("span_1_list_content.txt");
		if (!file_out1.fail())
		{
			span_1_list.printSet(file_out1);
			file_out1.close();
			std::cout << "span_1_list content visible in file span_1_list_content.txt" << std::endl;
		}
		
		std::ofstream file_out2("span_1_list_distance.txt");
		if (!file_out2.fail())
		{
			span_1_list.printSpan(file_out2);
			file_out2.close();
			std::cout << "span_1_list distance visible in file span_1_list_distance.txt" << std::endl;
		}
		
		std::cout << "span_1_list.shortestSpan(): " << span_1_list.shortestSpan() << std::endl;
		std::cout << "span_1_list.longestSpan(): " << span_1_list.longestSpan() << std::endl;
	}
	catch (const std::exception &e )
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout <<  std::endl << "\e[34mTest too many numbers in the list :\e[0m" << std::endl;
	Span	span_2_list(100);
	try
	{
		span_2_list.addNumber(my_list.begin(), my_list.end());
	}
	catch (const std::exception &e )
	{
		std::cerr << e.what() << std::endl;
	}
}

void	test_add_number_deque(void)
{
	std::deque<int>	my_deque = generate_deque_filled(20000);
	
	std::cout << "\e[34mTest with a Span initialisation using a deque of 20 000 random values:\e[0m" << std::endl;
	Span	span_1_deque(20000);
	try
	{
		span_1_deque.addNumber(my_deque.begin(), my_deque.end());
		
		std::ofstream file_out1("span_1_deque_content.txt");
		if (!file_out1.fail())
		{
			span_1_deque.printSet(file_out1);
			file_out1.close();
			std::cout << "span_1_deque content visible in file span_1_deque_content.txt" << std::endl;
		}
		
		std::ofstream file_out2("span_1_deque_distance.txt");
		if (!file_out2.fail())
		{
			span_1_deque.printSpan(file_out2);
			file_out2.close();
			std::cout << "span_1_deque distance visible in file span_1_deque_distance.txt" << std::endl;
		}
		
		std::cout << "span_1_deque.shortestSpan(): " << span_1_deque.shortestSpan() << std::endl;
		std::cout << "span_1_deque.longestSpan(): " << span_1_deque.longestSpan() << std::endl;
	}
	catch (const std::exception &e )
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl << "\e[34mTest too many numbers in the deque :\e[0m" << std::endl;
	Span	span_2_deque(100);
	try
	{
		span_2_deque.addNumber(my_deque.begin(), my_deque.end());
	}
	catch (const std::exception &e )
	{
		std::cerr << e.what() << std::endl;
	}
}

int	main(void)
{
	std::cout << "	\e[32mTEST ADDING EACH NUMBER INDIVIDUALY\e[0m" << std::endl;
	test_add_number_individuel();
	std::cout << std::endl;
	std::cout << "	\e[32mTEST USING SET AS INITIALISER\e[0m" << std::endl;
	test_add_number_set();
	std::cout << std::endl;
	std::cout << "	\e[32mTEST USING VECTOR AS INITIALISER\e[0m" << std::endl;
	test_add_number_vector();
	std::cout << std::endl;
	std::cout << "	\e[32mTEST USING LIST AS INITIALISER\e[0m" << std::endl;
	test_add_number_list();
	std::cout << std::endl;
	std::cout << "	\e[32mTEST USING DEQUE AS INITIALISER\e[0m" << std::endl;
	test_add_number_deque();
	
	return (0);
}