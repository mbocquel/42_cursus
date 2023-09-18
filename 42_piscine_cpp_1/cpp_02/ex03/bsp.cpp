/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 19:28:55 by mbocquel          #+#    #+#             */
/*   Updated: 2023/04/25 11:20:42 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	if (((a.get_x() - point.get_x()) * (b.get_y()- point.get_y())
		- (a.get_y() - point.get_y()) * (b.get_x() - point.get_x())) < 0
		&&
		((b.get_x() - point.get_x()) * (c.get_y()- point.get_y())
		- (b.get_y() - point.get_y()) * (c.get_x() - point.get_x())) < 0
		&&
		((c.get_x() - point.get_x()) * (a.get_y()- point.get_y())
		- (c.get_y() - point.get_y()) * (a.get_x() - point.get_x())) < 0
	)
		return (true);
	if (((a.get_x() - point.get_x()) * (b.get_y()- point.get_y())
		- (a.get_y() - point.get_y()) * (b.get_x() - point.get_x())) > 0
		&&
		((b.get_x() - point.get_x()) * (c.get_y()- point.get_y())
		- (b.get_y() - point.get_y()) * (c.get_x() - point.get_x())) > 0
		&&
		((c.get_x() - point.get_x()) * (a.get_y()- point.get_y())
		- (c.get_y() - point.get_y()) * (a.get_x() - point.get_x())) > 0
	)
		return (true);
	return (false);
}

int main(void)
{
	const Point a(7, 0);
	const Point b(5, 7);
	const Point c(0, 0);
	const Point p1(4.25f, 3.02f); // dans le triangle
	const Point p2(3.5f, 0); // sur un cote du triangle
	const Point p3(3, -1.5f); // hors du triangle
	const Point p4(5, 7); // sur un sommet (b)

	std::cout << "p1 is " << (bsp(a, b, c, p1) ? "in" : "not in") << " the triangle" << std::endl;
	std::cout << "p2 is " << (bsp(a, b, c, p2) ? "in" : "not in") << " the triangle" << std::endl;
	std::cout << "p3 is " << (bsp(a, b, c, p3) ? "in" : "not in") << " the triangle" << std::endl;
	std::cout << "p4 is " << (bsp(a, b, c, p4) ? "in" : "not in") << " the triangle" << std::endl;
	return (0);
}

