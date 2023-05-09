/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 10:11:03 by mbocquel          #+#    #+#             */
/*   Updated: 2023/05/09 11:05:15 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

/* ************************************************************************** */
/*                     Constructeurs et destructeurs                          */
/* ************************************************************************** */
bool Intern::_verbose = true;

Intern::Intern(void)
{
	if (Intern::_verbose)
		std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(Intern const & copy)
{
	(void)copy;
	if (Intern::_verbose)
		std::cout << "Intern copy constructor called" << std::endl;
}
// nothiong to be done to copy an intern because they are all the same...

Intern::~Intern(void)
{
	if (Intern::_verbose)
		std::cout << "Intern destructor called" << std::endl;
}

/* ************************************************************************** */
/*                     Surcharge d'operateur                                  */
/* ************************************************************************** */
Intern & Intern::operator=(Intern const & intern)
{
	(void)intern;
	if (Intern::_verbose)
		std::cout << "Intern assignation operator called but nothing to do, every interns are the same."
		<< std::endl;
	return (*this);
}

/* ************************************************************************** */
/*                     Methodes                                               */
/* ************************************************************************** */
AForm *Intern::makeForm(std::string request, std::string target)
{
	std::string	tab[3] = {"robotomy request", "presidential pardon", "shrubbery creation"};
	int			i = 0;
	AForm		*form_created;

	while (i < 3)
	{
		if (request == tab[i])
			break ;
		i++;
	}
	switch(i)
	{
		case 0:
			form_created = new RobotomyRequestForm(target);
			std::cout << "Ok boss I am making a Robotomy Request Form"<< std::endl;
			break ;
		case 1:
			form_created = new PresidentialPardonForm(target);
			std::cout << "Ok boss I am making a Presidential Pardon Form"<< std::endl;
			break ;
		case 2:
			form_created = new ShrubberyCreationForm(target);
			std::cout << "Ok boss I am making a Shrubbery Creation Form"<< std::endl;
			break ;
		default:
			form_created = NULL;
			std::cout << "I am so so sorry boss but I don't know what form you are talking about..."
			<< std::endl;
			break ;
	}
	return (form_created);
}
