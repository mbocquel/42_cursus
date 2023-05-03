/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 17:20:03 by mbocquel          #+#    #+#             */
/*   Updated: 2023/04/28 18:10:49 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

/* ************************************************************************** */
/*                     Constructeurs et destructeurs                          */
/* ************************************************************************** */

Brain::Brain(void) : _idea_index(-1)
{
	std::cout << "\e[35mBrain default constructor called\e[0m" << std::endl;
}

Brain::Brain(Brain const & copie)
{
	*this = copie;
	std::cout << "\e[35mBrain copie constructor called\e[0m" << std::endl;
}

Brain::~Brain(void)
{
	std::cout << "\e[35mBrain destructor called\e[0m" << std::endl;
}

/* ************************************************************************** */
/*                     Surcharge d'operateur                                  */
/* ************************************************************************** */

Brain & Brain::operator=(Brain const & brain)
{
	int	i = 0;
	while (i < 100)
	{
		this->_ideas[i] = brain.get_idea(i);
		i++;
	}
	this->_idea_index = brain.get_idea_index();
	std::cout << "\e[35mBrain assignation operator called\e[0m" << std::endl;
	return (*this);
}

/* ************************************************************************** */
/*                     Methodes                                               */
/* ************************************************************************** */
std::string	Brain::get_idea(int i) const
{
	if (i < 100 && i >= 0)
		return (this->_ideas[i]);
	else
		return ("");
}

void		Brain::add_idea(std::string & new_idea)
{
	if (this->_idea_index < 99)
	{
		this->_idea_index++;
		this->_ideas[this->_idea_index] = new_idea;
	}
	else
	{
		this->_idea_index = 0;
		this->_ideas[this->_idea_index] = new_idea;
	}
}
void		Brain::add_idea(std::string & new_idea, int index)
{
	if (index >= 0 && index < 100)
		this->_ideas[index] = new_idea;
}

int			Brain::get_idea_index(void) const
{
	return (this->_idea_index);
}
