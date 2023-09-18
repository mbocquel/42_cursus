/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 10:45:47 by mbocquel          #+#    #+#             */
/*   Updated: 2023/05/16 12:55:15 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main( void )
{
	std::string string_tab[5] = {"Bonjour ", "comment ", "ca ", "va ", "aujourd'hui ?"};
	int			int_tab[3] = {1, 2, 3};
	float		float_tab[4] = {42.42, 8.09, 54.3, 41.5};
	
	std::cout << "iter with std::string :" << std::endl;
	iter(string_tab, 5, &my_function);
	std::cout << std::endl;
	std::cout << "iter with int array :" << std::endl;
	iter(int_tab, 3, &my_function);
	std::cout << std::endl;
	std::cout << "iter with float array :" << std::endl;
	iter(float_tab, 4, &my_function);
	
	return (0);
}
