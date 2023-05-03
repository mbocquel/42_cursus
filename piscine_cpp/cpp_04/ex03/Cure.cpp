/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 13:12:17 by mbocquel          #+#    #+#             */
/*   Updated: 2023/05/02 16:55:33 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// \e[33m \e[0m

#include "Cure.hpp"

/* ************************************************************************** */
/*                     Constructeurs et destructeurs                          */
/* ************************************************************************** */
Cure::Cure(void) : AMateria("cure")
{
	std::cout << "\e[33mCure default constructor called.\e[0m" << std::endl;
}

Cure::Cure(Cure const & copy) : AMateria(copy.getType())
{
	std::cout << "\e[33mCure copy constructor called.\e[0m" << std::endl;
}

Cure::~Cure(void)
{
	std::cout << "\e[33mCure destructor called.\e[0m" << std::endl;
}

/* ************************************************************************** */
/*                     Surcharge d'operateur                                  */
/* ************************************************************************** */
Cure & Cure::operator=(Cure const & cure)
{
	std::cout << "\e[33mWarning: copying a cure is pretty useless as the type is const...\e[0m"
	<< std::endl;
	(void)cure;
	return (*this);
}

/* ************************************************************************** */
/*                     Methodes                                               */
/* ************************************************************************** */
AMateria* Cure::clone() const
{
	AMateria* new_cure = new Cure();
	return (new_cure);
}

void Cure::use(ICharacter& target)
{
	std::cout <<  "	\e[33m* heals "<< target.getName() << "'s wounds *\e[0m" << std::endl;
}
