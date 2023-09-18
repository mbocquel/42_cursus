/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 15:24:54 by mbocquel          #+#    #+#             */
/*   Updated: 2023/04/27 16:05:59 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

/* ************************************************************************** */
/*                     Constructeurs et destructeurs                          */
/* ************************************************************************** */

Dog::Dog(void) : Animal::Animal("Dog")
{
	std::cout << "\e[32mDog default constructor called\e[0m" << std::endl;
}

Dog::Dog(Dog const & copie)
{
	*this = copie;
	std::cout << "\e[32mDog copie constructor called\e[0m" << std::endl;
}

Dog::~Dog(void)
{
	std::cout << "\e[32mDog destructor called\e[0m" << std::endl;
}

/* ************************************************************************** */
/*                     Surcharge d'operateur                                  */
/* ************************************************************************** */
Dog & Dog::operator=(Dog const & dog)
{
	this->_type = dog.getType();
	std::cout << "\e[32mDog assignation operator called\e[0m" << std::endl;
	return (*this);
}

/* ************************************************************************** */
/*                     Methodes                                               */
/* ************************************************************************** */
void	Dog::makeSound(void) const
{
	std::cout << "\e[32m*** Whafff Whaff ! *** (Dog's sound if it wasn't clear enouth)\e[0m" << std::endl;
}
