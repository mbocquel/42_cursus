/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 14:18:02 by mbocquel          #+#    #+#             */
/*   Updated: 2023/05/02 11:36:13 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

/* ************************************************************************** */
/*                     Constructeurs et destructeurs                          */
/* ************************************************************************** */

AAnimal::AAnimal(void)
{
	std::cout << "\e[33mAAnimal default constructor called\e[0m" << std::endl;
}

AAnimal::AAnimal(AAnimal const & copie)
{
	std::cout << "\e[33mAAnimal copie constructor called\e[0m" << std::endl;
	*this = copie;
}

AAnimal::AAnimal(std::string type) : _type(type)
{
	std::cout << "\e[33mAAnimal type constructor called\e[0m" << std::endl;
}

AAnimal::~AAnimal(void)
{
	std::cout << "\e[33mAAnimal destructor called\e[0m" << std::endl;
}

/* ************************************************************************** */
/*                     Surcharge d'operateur                                  */
/* ************************************************************************** */
AAnimal & AAnimal::operator=(AAnimal const & animal)
{
	this->_type = animal.getType();
	std::cout << "\e[33mAAnimal assignation operator called\e[0m" << std::endl;
	return (*this);
}

/* ************************************************************************** */
/*                     Methodes                                               */
/* ************************************************************************** */
std::string		AAnimal::getType(void) const
{
	return (this->_type);	
}
