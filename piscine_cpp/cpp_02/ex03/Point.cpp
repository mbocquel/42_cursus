/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 19:23:49 by mbocquel          #+#    #+#             */
/*   Updated: 2023/04/25 11:05:21 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(Fixed(0)), _y(Fixed(0))
{
}

Point::Point(float const x, float const y) : _x(Fixed(x)), _y(Fixed(y))
{
}

Point::Point(Point const & copie) : _x(copie.get_x()), _y(copie.get_y())
{
}

Point::~Point()
{	
}

Fixed Point::get_x(void) const
{
	return (this->_x);
}

Fixed Point::get_y(void) const
{
	return (this->_y);
}

Point	& Point::operator=(Point const &point)
{
	(void)point;
	std::cout << "Assignement impossible, the point's values are const. Nothing will change" << std::endl;
	return(*this);
}

std::ostream & operator<<(std::ostream & o, Point const & p)
{
	o << "(" << p.get_x().toFloat() << ", " << p.get_y().toFloat() << ")";
	return o;
}