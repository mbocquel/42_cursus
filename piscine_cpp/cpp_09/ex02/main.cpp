/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 15:48:47 by mbocquel          #+#    #+#             */
/*   Updated: 2023/05/26 18:10:06 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <time.h>
#include <math.h>  

int	main(int argc, char **argv)
{
	clock_t time_vector;
	clock_t time_deque;
	int i = 0;
	if (argc == 1)
	{
		std::cerr << "Error" << std::endl;
		return (1);
	}
	argv++;
	PmergeMe	p_merge_me;
	try
	{
		time_vector = clock();
		p_merge_me.add_vector(argv);
		p_merge_me.sort_vector();
		time_vector = clock() - time_vector;

		time_deque = clock();
		p_merge_me.add_deque(argv);
		p_merge_me.sort_deque();
		time_deque = clock() - time_deque;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error" << std::endl;
		return (1);
	}
	std::cout << "Before:		";
	while (argv[i])
	{
		std::cout << argv[i] << " ";
		i++;
	}
	std::cout << std::endl << std::endl;
	std::cout << "After vector:	";
	p_merge_me.view_vector();

	std::cout << std::endl << "After deque:	";
	p_merge_me.view_deque();
	
	std::cout << "Time to process a range of " << argc- 1 << " elements with std::vector<int> : ";
	std::cout << (double)(1000000 * time_vector) / CLOCKS_PER_SEC << " us" << std::endl;
	std::cout << "Time to process a range of " << argc- 1 << " elements with std::deque<int>  : ";
	std::cout << (double)(1000000 * time_deque) / CLOCKS_PER_SEC << " us" << std::endl;
	return (0);
}
