/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 17:49:04 by mbocquel          #+#    #+#             */
/*   Updated: 2023/05/04 15:53:40 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

bool	PresidentialPardonForm::_verbose = true;
/* ************************************************************************** */
/*                     Constructeurs et destructeurs                          */
/* ************************************************************************** */
PresidentialPardonForm::PresidentialPardonForm(void) : 
AForm::AForm("PresidentialPardonForm", 25, 5)
{
	if (PresidentialPardonForm::_verbose)
		std::cout << "\e[32mDefault constructor called for PresidentialPardonForm\e[0m"<< std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : 
AForm::AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	if (PresidentialPardonForm::_verbose)
		std::cout << "\e[32mPresidentialPardonForm constructor called with target.\e[0m"<< std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & copy) :
AForm::AForm("PresidentialPardonForm", 25, 5), _target(copy.getTarget())
{
	if (PresidentialPardonForm::_verbose)
		std::cout << "\e[32mPresidentialPardonForm constructor called with target.\e[0m"<< std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	if (PresidentialPardonForm::_verbose)
		std::cout << "\e[32mPresidentialPardonForm destructor called\e[0m"<< std::endl;
}


/* ************************************************************************** */
/*                     Surcharge d'operateur                                  */
/* ************************************************************************** */

PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm const & form)
{
	if (PresidentialPardonForm::_verbose)
	{
		this->_target = form.getTarget();
		std::cout << "\e[32mPresidentialPardonForm assignement operator called.\e[0m" << std::endl;
	}
	return (*this);
}

std::ostream & operator<<(std::ostream & o, PresidentialPardonForm const & form)
{
	o << "\e[32mForm " << form.getName() << (form.getSigned() ? " (signed) | " : " (not signed) | ")
	<< "Minimum grade to sign: "<< form.getGrade_to_sign() << " | Minimum grade to execute: "
	<< form.getGrade_to_execute() << " | Target: " << form.getTarget() << "\e[0m";
	return o;
}

/* ************************************************************************** */
/*                     Methodes                                               */
/* ************************************************************************** */
std::string PresidentialPardonForm::getTarget(void) const
{
	return (this->_target);
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	try
	{
		this->check_executable(executor);
		std::cout << "\e[32m	" << this->_target << " has been forgiven by Zaphod Beeblebrox\e[0m" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		throw AForm::ExecutionFailed();
	}
}
