/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 17:48:59 by mbocquel          #+#    #+#             */
/*   Updated: 2023/05/04 17:15:04 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

bool	RobotomyRequestForm::_verbose = true;
unsigned char	RobotomyRequestForm::_count = 0;

/* ************************************************************************** */
/*                     Constructeurs et destructeurs                          */
/* ************************************************************************** */
RobotomyRequestForm::RobotomyRequestForm(void) : 
AForm::AForm("RobotomyRequestForm", 72, 45)
{
	if (RobotomyRequestForm::_verbose)
		std::cout << "\e[95mDefault constructor called for RobotomyRequestForm\e[0m"<< std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : 
AForm::AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	if (RobotomyRequestForm::_verbose)
		std::cout << "\e[95mRobotomyRequestForm constructor called with target.\e[0m"<< std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & copy) :
AForm::AForm("RobotomyRequestForm", 72, 45), _target(copy.getTarget())
{
	if (RobotomyRequestForm::_verbose)
		std::cout << "\e[95mRobotomyRequestForm constructor called with target.\e[0m"<< std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	if (RobotomyRequestForm::_verbose)
		std::cout << "\e[95mRobotomyRequestForm destructor called\e[0m"<< std::endl;
}


/* ************************************************************************** */
/*                     Surcharge d'operateur                                  */
/* ************************************************************************** */

RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm const & form)
{
	if (RobotomyRequestForm::_verbose)
	{
		this->_target = form.getTarget();
		std::cout << "\e[95mRobotomyRequestForm assignement operator called.\e[0m" << std::endl;
	}
	return (*this);
}

std::ostream & operator<<(std::ostream & o, RobotomyRequestForm const & form)
{
	o << "\e[95mForm " << form.getName() << (form.getSigned() ? " (signed) | " : " (not signed) | ")
	<< "Minimum grade to sign: "<< form.getGrade_to_sign() << " | Minimum grade to execute: "
	<< form.getGrade_to_execute() << " | Target: " << form.getTarget() << "\e[0m";
	return o;
}

/* ************************************************************************** */
/*                     Methodes                                               */
/* ************************************************************************** */
std::string RobotomyRequestForm::getTarget(void) const
{
	return (this->_target);
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	try
	{
		this->check_executable(executor);
		if (RobotomyRequestForm::_count % 2 == 0)
			std::cout << "\e[95m	*#*#*###*** BRRROOUUUM BRRRRRRRRRRROOOOOOMM ***###*#*#*"
			<< std::endl << this->_target << " has been robotised\e[0m" << std::endl;
		else
			std::cout << "\e[95m	*#*#*###*** BRRRO..... Damn the robotization of "<< this->_target << " failed\e[0m" << std::endl;
		(RobotomyRequestForm::_count)++;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		throw AForm::ExecutionFailed();
	}
}
