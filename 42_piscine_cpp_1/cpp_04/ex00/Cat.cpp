/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 15:54:08 by mbocquel          #+#    #+#             */
/*   Updated: 2023/04/27 16:05:53 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

/* ************************************************************************** */
/*                     Constructeurs et destructeurs                          */
/* ************************************************************************** */

Cat::Cat(void) : Animal::Animal("Cat")
{
	std::cout << "\e[31mCat default constructor called\e[0m" << std::endl;
}

Cat::Cat(Cat const & copie)
{
	*this = copie;
	std::cout << "\e[31mCat copie constructor called\e[0m" << std::endl;
}

Cat::~Cat(void)
{
	std::cout << "\e[31mCat destructor called\e[0m" << std::endl;
}

/* ************************************************************************** */
/*                     Surcharge d'operateur                                  */
/* ************************************************************************** */
Cat & Cat::operator=(Cat const & cat)
{
	this->_type = cat.getType();
	std::cout << "\e[31mCat assignation operator called\e[0m" << std::endl;
	return (*this);
}

/* ************************************************************************** */
/*                     Methodes                                               */
/* ************************************************************************** */
void	Cat::makeSound(void) const
{
	std::cout << "\e[31m*** Miaou Miaou ! *** (Cat's sound if it wasn't clear enouth)\e[0m" << std::endl;
}
