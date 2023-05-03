/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 13:12:12 by mbocquel          #+#    #+#             */
/*   Updated: 2023/05/02 16:55:23 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

/* ************************************************************************** */
/*                     Constructeurs et destructeurs                          */
/* ************************************************************************** */
Ice::Ice(void) : AMateria("ice")
{
	std::cout << "\e[34mIce default constructor called.\e[0m" << std::endl;
}

Ice::Ice(Ice const & copy) : AMateria(copy.getType())
{
	std::cout << "\e[34mIce copy constructor called.\e[0m" << std::endl;
}

Ice::~Ice(void)
{
	std::cout << "\e[34mIce destructor called.\e[0m" << std::endl;
}

/* ************************************************************************** */
/*                     Surcharge d'operateur                                  */
/* ************************************************************************** */
Ice & Ice::operator=(Ice const & ice)
{
	std::cout << "\e[34mWarning: copying an ice is pretty useless as the type is const...\e[0m"
	<< std::endl;
	(void)ice;
	return (*this);
}

/* ************************************************************************** */
/*                     Methodes                                               */
/* ************************************************************************** */
AMateria* Ice::clone() const
{
	AMateria* new_ice = new Ice();
	return (new_ice);
}

void Ice::use(ICharacter& target)
{
	std::cout << "	\e[34m* shoots an ice bolt at " << target.getName() << " *\e[0m" << std::endl;
}
