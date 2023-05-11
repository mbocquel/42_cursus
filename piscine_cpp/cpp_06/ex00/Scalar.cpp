/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scalar.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 10:29:01 by mbocquel          #+#    #+#             */
/*   Updated: 2023/05/11 16:15:16 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Scalar.hpp"
#include <string>

bool	Scalar::_verbose = true;
/* ************************************************************************** */
/*                     Constructeurs et destructeurs                          */
/* ************************************************************************** */
Scalar::Scalar(void)
{
	if (Scalar::_verbose)
		std::cout << "Scalar default constructor called" << std::endl;
}

Scalar::Scalar(Scalar const & copy)
{
	*this = copy;
	if (Scalar::_verbose)
		std::cout << "Scalar copy constructor called" << std::endl;
}

Scalar::Scalar(const char *str)
{
	this->_double = std::atof(str);
	this->_float = static_cast<float>(this->_double);
	this->_int = static_cast<int>(this->_double);
	this->_char = static_cast<int>(this->_double);

	if (Scalar::_verbose)
		std::cout << "Scalar string constructor called" << std::endl;
}

Scalar::~Scalar(void)
{
	if (Scalar::_verbose)
		std::cout << "Scalar destructor called" << std::endl;
}

/* ************************************************************************** */
/*                     Surcharge d'operateur                                  */
/* ************************************************************************** */
Scalar & Scalar::operator=(Scalar const & scalar)
{
	this->_char = scalar.getChar();
	this->_int = scalar.getInt();
	this->_float = scalar.getFloat();
	this->_double = scalar.getDouble();
	if (Scalar::_verbose)
		std::cout << "Scalar copy operator called." << std::endl;
	return (*this);
}

std::ostream & operator<<(std::ostream & o, Scalar const & scalar)
{
	return (o);
}

/* ************************************************************************** */
/*                     Methodes                                               */
/* ************************************************************************** */
char		Scalar::getChar(void) const
{
	return (this->_char);
}

int			Scalar::getInt(void) const
{
	return (this->_int);
}

float		Scalar::getFloat(void) const
{
	return (this->_float);
}

double		Scalar::getDouble(void) const
{
	return (this->_double);
}

/* ************************************************************************** */
/*                     Exceptions                                             */
/* ************************************************************************** */

