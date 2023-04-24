/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 15:46:28 by mbocquel          #+#    #+#             */
/*   Updated: 2023/04/24 19:08:59 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_n_bit_fact = 8;

/* ------------------------- Constructeurs et destructeurs ------------------------- */

Fixed::Fixed(void) : _value(0)
{
}

Fixed::Fixed(Fixed const & copie)
{
	*this = copie;	
}

Fixed::Fixed(int const val_int)
{
	this->_value = val_int << this->_n_bit_fact;
}

Fixed::Fixed(float const val_float)
{
	this->_value = roundf(val_float * (1 << this->_n_bit_fact));
}

Fixed::~Fixed(void)
{
}

/* ------------------------- Fonctions membres ------------------------- */

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

Fixed & Fixed::min(Fixed & a, Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}

Fixed	& Fixed::max(Fixed & a, Fixed &b)
{
	if (a > b)
		return (a);
	return (b);
}

const Fixed	& Fixed::min(Fixed const & a, Fixed const & b)
{
	if (a < b)
		return (a);
	return (b);
}

const Fixed	& Fixed::max(Fixed const & a, Fixed const & b)
{
	if (a > b)
		return (a);
	return (b);
}

/* ------------------------- Operators ------------------------- */

Fixed & Fixed::operator=(Fixed const & f)
{
	//std::cout << "Copy assignment operator called" << std::endl;
	this->_value = f.getRawBits();
	return (*this);
}

std::ostream & operator<<(std::ostream & o, Fixed const & f)
{
	o << f.toFloat();
	return o;
}

Fixed	Fixed::operator+(Fixed const & f) const
{
	return (Fixed((float)(this->_value + f.getRawBits()) / (float)(1 << this->_n_bit_fact)));
}

Fixed	Fixed::operator-(Fixed const & f) const
{
	return (Fixed((float)(this->_value - f.getRawBits()) / (float)(1 << this->_n_bit_fact)));
}

Fixed	Fixed::operator*(Fixed const & f) const
{
	float	prod;

	prod = (float)(this->_value * f.getRawBits()) 
				/ (float)((1 << this->_n_bit_fact) * (1 << this->_n_bit_fact));
	return (Fixed(prod));
}

Fixed	Fixed::operator/(Fixed const & f) const
{
	float	div;

	div = (float)(this->_value) / (float)f.getRawBits();
	return (Fixed(div));
}

bool	Fixed::operator<(Fixed const & f) const
{
	if (this->_value < f.getRawBits())
		return (true);
	else
		return (false);
}

bool	Fixed::operator>(Fixed const & f) const
{
	if (this->_value > f.getRawBits())
		return (true);
	else
		return (false);
}

bool	Fixed::operator<=(Fixed const & f) const
{
	if (this->_value <= f.getRawBits())
		return (true);
	else
		return (false);
}

bool	Fixed::operator>=(Fixed const & f) const
{
	if (this->_value >= f.getRawBits())
		return (true);
	else
		return (false);
}

bool	Fixed::operator==(Fixed const & f) const
{
	if (this->_value == f.getRawBits())
		return (true);
	else
		return (false);
}

bool	Fixed::operator!=(Fixed const & f) const
{
	if (this->_value != f.getRawBits())
		return (true);
	else
		return (false);
}

Fixed &	Fixed::operator++(void)
{
	this->_value++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	old(*this);

	this->_value++;
	return (old);
}

Fixed & Fixed::operator--(void)
{
	this->_value--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	old(*this);

	this->_value--;
	return (old);
}

