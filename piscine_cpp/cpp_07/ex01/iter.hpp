/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 11:11:11 by mbocquel          #+#    #+#             */
/*   Updated: 2023/05/16 12:51:01 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP
# include <cstddef>
# include <string>
# include <iostream>

template<typename T>
void	iter(T *array, std::size_t size, void (*f)(T & elem))
{
	std::size_t i = 0;

	while (i < size)
	{
		(*f)(array[i]);
		i++;
	}
}

template<typename T>
void	my_function(T & elem)
{
	std::cout << elem << std::endl;
}

#endif

/*Implement a function template iter that takes 3 parameters and returns nothing.
•The first parameter is the address of an array.
•The second one is the length of the array.
•The third one is a function that will be call on every element of the array*/