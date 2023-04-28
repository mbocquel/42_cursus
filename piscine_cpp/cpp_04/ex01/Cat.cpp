/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 15:54:08 by mbocquel          #+#    #+#             */
/*   Updated: 2023/04/28 17:01:09 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

/* ************************************************************************** */
/*                     Constructeurs et destructeurs                          */
/* ************************************************************************** */

Cat::Cat(void) : Animal::Animal("Cat")
{
	std::cout << "\e[31mCat default constructor called\e[0m" << std::endl;
	this->_my_brain = new Brain();
}

Cat::Cat(Cat const & copie)
{
	this->_my_brain = new Brain();
	*this = copie;
	std::cout << "\e[31mCat copie constructor called\e[0m" << std::endl;
}

Cat::~Cat(void)
{
	delete this->_my_brain;
	std::cout << "\e[31mCat destructor called\e[0m" << std::endl;
}

/* ************************************************************************** */
/*                     Surcharge d'operateur                                  */
/* ************************************************************************** */
Cat & Cat::operator=(Cat const & cat)
{
	int	i = 0;
	this->_type = cat.getType();
	while (i < 100)
	{
		std::string idea = (cat.getBrain())->get_idea(i);
		(this->_my_brain)->add_idea(idea, i);
		i++;
	}
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

Brain 			*Cat::getBrain(void) const
{
	return (this->_my_brain);
}

void			Cat::set_new_idea(std::string new_idea)
{
	this->_my_brain->add_idea(new_idea);
}