/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 13:11:59 by mbocquel          #+#    #+#             */
/*   Updated: 2023/05/02 16:30:50 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

/* ************************************************************************** */
/*                     Constructeurs et destructeurs                          */
/* ************************************************************************** */
MateriaSource::MateriaSource(void)
{
	for (int i = 0; i < 4; i++)
		this->_materia_tab[i] = NULL;
	std::cout << "\e[35mMateriaSource default constructor called\e[0m" << std::endl;
}

MateriaSource::MateriaSource(MateriaSource const & copy)
{
	AMateria *materia_ptr =  NULL;
	
	for (int i = 0; i < 4; i++)
	{
		materia_ptr = copy.get_amateria(i);
		if (materia_ptr)
			this->_materia_tab[i] = materia_ptr->clone();
		else
			this->_materia_tab[i] = NULL;
	}
	std::cout << "\e[35mMateriaSource copy constructor called\e[0m" << std::endl;
}

MateriaSource::~MateriaSource(void)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_materia_tab[i])
			delete this->_materia_tab[i];
	}
	std::cout << "\e[35mMateriaSource destructor called\e[0m" << std::endl;
}

/* ************************************************************************** */
/*                     Surcharge d'operateur                                  */
/* ************************************************************************** */
MateriaSource & MateriaSource::operator=(MateriaSource const & materia_source)
{
	AMateria *materia_ptr =  NULL;
	
	for (int i = 0; i < 4; i++)
	{
		materia_ptr = materia_source.get_amateria(i);
		if (this->_materia_tab[i])
			delete this->_materia_tab[i];
		if (materia_ptr)
			this->_materia_tab[i] = materia_ptr->clone();
		else
			this->_materia_tab[i] = NULL;
	}
	return (*this);
}

/* ************************************************************************** */
/*                     Methodes                                               */
/* ************************************************************************** */
void MateriaSource::learnMateria(AMateria* amateria)
{
	int i = 0;
	
	while (i < 4)
	{
		if (this->_materia_tab[i] == NULL)
			break;
		i++;
	}
	if (i == 4)
	{
		std::cout << "\e[35mNo more room in my MateriaSource to add new materia\e[0m" << std::endl;
		return;
	}
	if (amateria == NULL)
	{
		std::cout << "\e[35mWarning, I cannot learn form a NULL Materia...\e[0m" << std::endl;
		return ;
	}
	this->_materia_tab[i] = amateria;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	int	i = 0;

	while (i < 4)
	{
		if (this->_materia_tab[i] && this->_materia_tab[i]->getType() == type)
			return (this->_materia_tab[i]->clone());
		i++;
	}
	std::cout << "\e[35mWarning, no materia found for required type...\e[0m" << std::endl;
	return (NULL);
}

AMateria*	MateriaSource::get_amateria(int idx) const
{
	if (idx < 0 || idx > 3)
		return (NULL);
	else 
		return (this->_materia_tab[idx]);
}
