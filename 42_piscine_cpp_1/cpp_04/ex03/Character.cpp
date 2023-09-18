/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 13:12:22 by mbocquel          #+#    #+#             */
/*   Updated: 2023/05/02 17:01:01 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

/* ************************************************************************** */
/*                     Constructeurs et destructeurs                          */
/* ************************************************************************** */
Character::Character(void)
{
	std::cout << "\e[32mCharacter default constructor callled\e[0m" << std::endl;
	for (int i = 0; i < 4; i++)
		this->_materia_tab[i] = NULL;
}

Character::Character(std::string name) : _name(name)
{
	std::cout << "\e[32mCharacter constructor callled for "<< this->_name
	<< "\e[0m" << std::endl;
	for (int i = 0; i < 4; i++)
		this->_materia_tab[i] = NULL;
}

Character::Character(Character const & copy) : _name(copy.getName())
{
	AMateria*	materia_ptr = NULL;
	
	for (int i = 0; i < 4; i++)
	{
		materia_ptr = copy.getAMateria(i);
		if (materia_ptr)
			this->_materia_tab[i] = materia_ptr->clone();
		else
			this->_materia_tab[i] = NULL;
	}
	std::cout << "\e[32mCharacter copy constructor callled for "<< this->_name 
	<< "\e[0m" << std::endl;
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_materia_tab[i])
			delete this->_materia_tab[i];
	}
	std::cout << "\e[32mCharacter destructor callled for "<< this->_name
	<< "\e[0m" << std::endl;
}

/* ************************************************************************** */
/*                     Surcharge d'operateur                                  */
/* ************************************************************************** */

Character & Character::operator=(Character const & character)
{
	AMateria*	materia_ptr = NULL;
	
	this->_name = character.getName();
	for (int i = 0; i < 4; i++)
	{
		if (this->_materia_tab[i])
			delete this->_materia_tab[i];
		materia_ptr = character.getAMateria(i);
		if  (materia_ptr == NULL)
			this->_materia_tab[i] = NULL;
		else
			this->_materia_tab[i] = materia_ptr->clone();
	}
	std::cout << "\e[32mCharacter assignation operator called\e[0m" << std::endl;
	return (*this);
}

/* ************************************************************************** */
/*                     Methodes                                               */
/* ************************************************************************** */
std::string const & Character::getName() const
{
	return (this->_name);
}

void Character::equip(AMateria* m)
{
	int i = 0;
	while (i < 4)
	{
		if (this->_materia_tab[i] == NULL)
		{
			this->_materia_tab[i] = m;
			std::cout << "\e[32mMateria added in position " << i 
			<< "\e[0m" << std::endl;
			break;
		}
		i++;
	}
	if (i == 4)
		std::cout << "\e[32mSorry, no empty space to add materia...\e[0m" << std::endl;
}

void Character::unequip(int idx)
{
	this->_materia_tab[idx] = NULL;
	std::cout << "\e[32mMateria in position " 
	<< idx << " removed from the character inventory\e[0m"<< std::endl;
}

void Character::use(int idx, ICharacter& target)
{
	if (this->_materia_tab[idx])
		this->_materia_tab[idx]->use(target);
	else
		std::cout << "	\e[32m* That's a shame, I don't have an equipement to use on index "
		<< idx << " *\e[0m" << std::endl;
}

AMateria*	Character::getAMateria(int idx) const
{
	if (idx < 0 || idx > 3)
		return (NULL);
	else
		return (this->_materia_tab[idx]);
}
