/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 15:54:08 by mbocquel          #+#    #+#             */
/*   Updated: 2023/04/27 15:56:42 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

/* ************************************************************************** */
/*                     Constructeurs et destructeurs                          */
/* ************************************************************************** */

WrongCat::WrongCat(void) : WrongAnimal::WrongAnimal("WrongCat")
{
	std::cout << "\e[35mWrongCat default constructor called\e[0m" << std::endl;
}

WrongCat::WrongCat(WrongCat const & copie)
{
	*this = copie;
	std::cout << "\e[35mWrongCat copie constructor called\e[0m" << std::endl;
}

WrongCat::~WrongCat(void)
{
	std::cout << "\e[35mWrongCat destructor called\e[0m" << std::endl;
}

/* ************************************************************************** */
/*                     Surcharge d'operateur                                  */
/* ************************************************************************** */
WrongCat & WrongCat::operator=(WrongCat const & wrong_cat)
{
	this->_type = wrong_cat.get_type();
	std::cout << "\e[35mWrongCat assignation operator called\e[0m" << std::endl;
	return (*this);
}

/* ************************************************************************** */
/*                     Methodes                                               */
/* ************************************************************************** */
void	WrongCat::makeSound(void) const
{
	std::cout << "\e[35m*** Miaou Miaou ! *** (WrongCat's sound if it wasn't clear enouth)\e[0m" << std::endl;
}
