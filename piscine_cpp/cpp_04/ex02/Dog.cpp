/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 15:24:54 by mbocquel          #+#    #+#             */
/*   Updated: 2023/05/02 11:36:59 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

/* ************************************************************************** */
/*                     Constructeurs et destructeurs                          */
/* ************************************************************************** */

Dog::Dog(void) : AAnimal::AAnimal("Dog")
{
	std::cout << "\e[32mDog default constructor called\e[0m" << std::endl;
	this->_my_brain = new Brain();
}

Dog::Dog(Dog const & copie)
{
	this->_my_brain = new Brain();
	*this = copie;
	std::cout << "\e[32mDog copie constructor called\e[0m" << std::endl;
}

Dog::~Dog(void)
{
	delete this->_my_brain;
	std::cout << "\e[32mDog destructor called\e[0m" << std::endl;
}

/* ************************************************************************** */
/*                     Surcharge d'operateur                                  */
/* ************************************************************************** */
Dog & Dog::operator=(Dog const & dog)
{
	int	i = 0;
	this->_type = dog.getType();
	while (i < 100)
	{
		std::string idea = (dog.getBrain())->get_idea(i);
		(this->_my_brain)->add_idea(idea, i);
		i++;
	}
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

Brain 			*Dog::getBrain(void) const
{
	return (this->_my_brain);
}

void			Dog::set_new_idea(std::string new_idea)
{
	this->_my_brain->add_idea(new_idea);
}