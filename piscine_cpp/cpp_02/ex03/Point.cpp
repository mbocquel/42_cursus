/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 19:23:49 by mbocquel          #+#    #+#             */
/*   Updated: 2023/04/24 20:01:40 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(Fixed(0)), _y(Fixed(0))
{
}

Point::Point(float const x, float const y) : _x(Fixed(x)), _y(Fixed(y))
{
}

Point::Point(Point const & copie)
{
	*this = copie;
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

/*Point	& Point::operator=(Point const &point) const
{
	//return(Point(point));
}*/

std::ostream & operator<<(std::ostream & o, Point const & p)
{
	o << "(" << p.get_x().toFloat() << ", " << p.get_y().toFloat() << ")";
	return o;
}