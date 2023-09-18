/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 15:46:28 by mbocquel          #+#    #+#             */
/*   Updated: 2023/04/24 17:26:28 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_n_bit_fact = 8;

Fixed::Fixed(void) : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const & copie)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copie;	
}

Fixed::Fixed(int const val_int)
{
	std::cout << "Int constructor called" << std::endl;
	this->_value = val_int << this->_n_bit_fact;
}

Fixed::Fixed(float const val_float)
{
	std::cout << "Float constructor called" << std::endl;
	this->_value = roundf(val_float * (1 << this->_n_bit_fact));
}


Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

int		Fixed::getRawBits(void) const
{
	return (this->_value);
}

void	Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}

float	Fixed::toFloat(void) const
{
	return ((float)((float)this->_value / (float)(1 << this->_n_bit_fact)));
}

int		Fixed::toInt(void) const
{	
	return (this->_value / (1 << this->_n_bit_fact));
}

Fixed & Fixed::operator=(Fixed const & f)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_value = f.getRawBits();
	return (*this);
}

std::ostream & operator<<(std::ostream & o, Fixed const & f)
{
	o << f.toFloat();
	return o;
}
