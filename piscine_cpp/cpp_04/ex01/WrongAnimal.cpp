/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 14:18:02 by mbocquel          #+#    #+#             */
/*   Updated: 2023/04/27 16:06:06 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

/* ************************************************************************** */
/*                     Constructeurs et destructeurs                          */
/* ************************************************************************** */

WrongAnimal::WrongAnimal(void)
{
	std::cout << "\e[34mWrongAnimal default constructor called\e[0m" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const & copie)
{
	std::cout << "\e[34mWrongAnimal copie constructor called\e[0m" << std::endl;
	*this = copie;
}

WrongAnimal::WrongAnimal(std::string type) : _type(type)
{
	std::cout << "\e[34mWrongAnimal type constructor called\e[0m" << std::endl;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "\e[34mWrongAnimal destructor called\e[0m" << std::endl;
}

/* ************************************************************************** */
/*                     Surcharge d'operateur                                  */
/* ************************************************************************** */
WrongAnimal & WrongAnimal::operator=(WrongAnimal const & WrongAnimal)
{
	this->_type = WrongAnimal.get_type();
	std::cout << "\e[34mWrongAnimal assignation operator called\e[0m" << std::endl;
	return (*this);
}

/* ************************************************************************** */
/*                     Methodes                                               */
/* ************************************************************************** */
void	WrongAnimal::makeSound(void) const
{
	std::cout << "\e[34m******* Random WrongAnimal sound *******\e[0m" << std::endl;
}

std::string		WrongAnimal::get_type(void) const
{
	return (this->_type);	
}
