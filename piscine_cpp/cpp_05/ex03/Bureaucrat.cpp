/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 10:46:15 by mbocquel          #+#    #+#             */
/*   Updated: 2023/05/04 15:50:13 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/* ************************************************************************** */
/*                     Constructeurs et destructeurs                          */
/* ************************************************************************** */
bool Bureaucrat::_verbose = true;

Bureaucrat::Bureaucrat(void) : _name("")
{
	if (Bureaucrat::_verbose)
		std::cout << "\e[34mBureaucrat constructor called\e[0m" << std::endl; 
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	if (grade >= 1 && grade <= 150)
		this->_grade = grade;
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		throw Bureaucrat::GradeTooHighException();
	if (Bureaucrat::_verbose)
		std::cout << "\e[34mBureaucrat constructor called for " << this->_name << "\e[0m" << std::endl; 
}

Bureaucrat::Bureaucrat(Bureaucrat const & copy) :
_name(copy.getName()), _grade(copy.getGrade())
{
	if (Bureaucrat::_verbose)
		std::cout << "\e[34mBureaucrat copy constructor called\e[0m" << std::endl; 
}

Bureaucrat::~Bureaucrat(void)
{
	if (Bureaucrat::_verbose)
		std::cout << "\e[34mBureaucrat destructor called\e[0m" << std::endl; 
}

/* ************************************************************************** */
/*                     Surcharge d'operateur                                  */
/* ************************************************************************** */
Bureaucrat & Bureaucrat::operator=(Bureaucrat const & bureaucrat)
{
	this->_grade = bureaucrat.getGrade();
	if (Bureaucrat::_verbose)
		std::cout << "\e[34mBureaucrat assignement operator called. Warning, name is const and cannot be changed\e[0m"
		<< std::endl;
	return (*this);
}

std::ostream & operator<<(std::ostream & o, Bureaucrat const & bureaucrat)
{
	o << "\e[34m" << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".\e[0m";
	return o;
}

/* ************************************************************************** */
/*                     Methodes                                               */
/* ************************************************************************** */

std::string const	Bureaucrat::getName(void) const
{
	return (this->_name);
}

int	Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

void	Bureaucrat::increment_grade(void)
{
	if (this->_grade > 1)
		this->_grade--;
	else
		throw GradeTooHighException();
}

void	Bureaucrat::decrement_grade(void)
{
	if (this->_grade < 150)
		this->_grade++;
	else
		throw GradeTooLowException();
}

void	Bureaucrat::signForm(AForm & form)
{
	try
	{
		form.beSigned(*this);
		std::cout << "\e[34m" << this->_name << " signed " << form.getName() << "\e[0m" << std::endl;
	}
	catch (AForm::GradeTooLowException &e)
	{
		std::cout << "\e[91m" << this->_name << " couldn't sign " << form.getName() 
		<< " because his/her grade is not high enouth.\e[0m" << std::endl;
	}
}

void	Bureaucrat::executeForm(AForm const & form)
{
	try
	{
		form.execute(*this);
		std::cout << "\e[34m" << this->_name << " executed " << form.getName() << "\e[0m" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
}

/* ************************************************************************** */
/*                     Exceptions                                             */
/* ************************************************************************** */

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("\e[91mBureaucrat grade too high\e[0m");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("\e[91mBureaucrat grade too low\e[0m");
}
