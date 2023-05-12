/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scalar.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 10:29:01 by mbocquel          #+#    #+#             */
/*   Updated: 2023/05/12 16:21:24 by mbocquel         ###   ########.fr       */
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

Scalar::Scalar(std::string str) : _string(str)
{
	char	*remain = NULL;
	this->_double = strtod(str.c_str(), &remain);
	std::string remain_string(remain);

	if (str.find('.') == std::string::npos && remain_string.empty())
		this->_origin_type = "int";
	else if (str.find('.') != std::string::npos && remain_string == "f")
		this->_origin_type = "float";
	else if (str.find('.') != std::string::npos && remain_string.empty())
		this->_origin_type = "double";
	else if (str == "-inff" || str == "+inff" || str == "inff" )
	{
		this->_origin_type = "float";
		this->_pseudo = str;
	}
	else if (str == "-inf" || str == "+inf" || str == "inf")
	{
		this->_origin_type = "double";
		this->_pseudo = str;
	}
	else
		this->_pseudo = "nan";
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
	if (this != &scalar)
	{
		this->_double = scalar._double;
		this->_origin_type = scalar._origin_type;
		this->_string = scalar._string;
		this->_pseudo = scalar._pseudo;
	}
	if (Scalar::_verbose)
		std::cout << "Scalar assignement operator called." << std::endl;
	return (*this);
}

std::ostream & operator<<(std::ostream & o, Scalar const & scalar)
{
	double db = scalar.getDouble();
	char	ch = static_cast<char>(db);
	int		it = static_cast<int>(db);
	float	ft = static_cast<float>(db);
	std::string	pseudo = scalar.getPseudo();
	
	if (pseudo == "nan")
	{
		o << "char: impossible" << std::endl << "int: impossible" << std::endl
		<< "float: nanf" << std::endl << "double: nan" << std::endl;
	}
	//Besoin de tester les overflow des int, des char, des float
	if (db < static_cast<double>(CHAR_MIN) || db > static_cast<double>(CHAR_MAX))
	
	return (o);
}

/* ************************************************************************** */
/*                     Methodes                                               */
/* ************************************************************************** */

double		Scalar::getDouble(void) const
{
	return (this->_double);
}

std::string		Scalar::getPseudo(void) const
{
	return (this->_pseudo);
}

/* ************************************************************************** */
/*                     Exceptions                                             */
/* ************************************************************************** */

