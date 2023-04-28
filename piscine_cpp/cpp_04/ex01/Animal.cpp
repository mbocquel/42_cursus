/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 14:18:02 by mbocquel          #+#    #+#             */
/*   Updated: 2023/04/28 18:15:48 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

/* ************************************************************************** */
/*                     Constructeurs et destructeurs                          */
/* ************************************************************************** */

Animal::Animal(void)
{
	std::cout << "\e[33mAnimal default constructor called\e[0m" << std::endl;
}

Animal::Animal(Animal const & copie)
{
	std::cout << "\e[33mAnimal copie constructor called\e[0m" << std::endl;
	*this = copie;
}

Animal::Animal(std::string type) : _type(type)
{
	std::cout << "\e[33mAnimal type constructor called\e[0m" << std::endl;
}

Animal::~Animal(void)
{
	std::cout << "\e[33mAnimal destructor called\e[0m" << std::endl;
}

/* ************************************************************************** */
/*                     Surcharge d'operateur                                  */
/* ************************************************************************** */
Animal & Animal::operator=(Animal const & animal)
{
	this->_type = animal.getType();
	std::cout << "\e[33mAnimal assignation operator called\e[0m" << std::endl;
	return (*this);
}

/* ************************************************************************** */
/*                     Methodes                                               */
/* ************************************************************************** */
void	Animal::makeSound(void) const
{
	std::cout << "\e[33m******* Random animal sound *******\e[0m" << std::endl;
}

std::string		Animal::getType(void) const
{
	return (this->_type);	
}
/*
Brain 			*Animal::getBrain(void) const
{
	return (NULL);
}

void			Animal::set_new_idea(std::string new_idea)
{
	(void)new_idea;
}
*/