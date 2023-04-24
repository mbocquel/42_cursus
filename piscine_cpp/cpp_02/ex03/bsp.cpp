/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 19:28:55 by mbocquel          #+#    #+#             */
/*   Updated: 2023/04/24 20:01:56 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	(void)a;
	(void)b;
	(void)c;
	(void)point;
	return (false);
}

int main(void)
{
	Point a(2.5f, 3.54f);
	Point b(0, 2);
	Point c;

	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;
	//c = a;
	//std::cout << c << std::endl;
	
	return (0);
}

