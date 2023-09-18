/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 12:06:48 by mbocquel          #+#    #+#             */
/*   Updated: 2023/05/02 16:26:32 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

/* ************************************************************************** */
/*                     Constructeurs et destructeurs                          */
/* ************************************************************************** */

AMateria::AMateria(std::string const & type) : _type(type)
{
	std::cout << "\e[31mAMateria constructor called with type "<< this->_type 
	<< "\e[0m" << std::endl;
}

AMateria::AMateria(void)
{
	std::cout << "\e[31mAMateria default constructor called.\e[0m" << std::endl;
}

AMateria::AMateria(AMateria const & copy) : _type(copy.getType())
{
	std::cout << "\e[31mAMateria copy constructor called.\e[0m" << std::endl;
}

AMateria::~AMateria(void)
{
	std::cout << "\e[31mAMateria destructor called.\e[0m" << std::endl;
}

/* ************************************************************************** */
/*                     Surcharge d'operateur                                  */
/* ************************************************************************** */

AMateria & AMateria::operator=(AMateria const & amateria)
{
	(void)amateria;
	std::cout << "\e[31mWarning: copying a AMateria is pretty useless as the type is const...\e[0m"
	<< std::endl;
	return (*this);
}

/* ************************************************************************** */
/*                     Methodes                                               */
/* ************************************************************************** */

std::string const & AMateria::getType() const
{
	return (this->_type);
}

void AMateria::use(ICharacter& target)
{
	(void)target;
	std::cout << "\e[31mSorry, using a pure AMateria doesn't do much ...\e[0m"<< std::endl;
}
