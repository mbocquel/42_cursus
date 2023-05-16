/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 10:45:03 by mbocquel          #+#    #+#             */
/*   Updated: 2023/05/16 10:54:48 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP
# include <iostream>

template<typename T>
void	swap(T &a, T &b)
{
	T temp = a;
	a = b;
	b = temp;
	return ;
}

template<typename T>
T const &	min(T const & a, T const & b)
{
	return ((a < b) ? a : b);
}

template<typename T>
T const &	max(T const & a, T const & b)
{
	return ((a > b) ? a : b);
}

#endif
