/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 19:23:47 by mbocquel          #+#    #+#             */
/*   Updated: 2023/04/25 10:40:11 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP
# include "Fixed.hpp"

class	Point
{
public:
	Point();
	Point(float const x, float const y);
	Point(Point const & copie);
	~Point();
	
	Point	&operator=(Point const &point);
	Fixed 	get_x(void) const;
	Fixed	get_y(void)const;
	
private:
	Fixed const	_x;
	Fixed const	_y;

};

std::ostream & operator<<(std::ostream & o, Point const & p);

#endif