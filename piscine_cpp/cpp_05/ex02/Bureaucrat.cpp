/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 10:46:15 by mbocquel          #+#    #+#             */
/*   Updated: 2023/05/03 17:42:19 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/* ************************************************************************** */
/*                     Constructeurs et destructeurs                          */
/* ************************************************************************** */
bool Bureaucrat::_verbose = false;

Bureaucrat::Bureaucrat(void) : _name("")
{
	if (Bureaucrat::_verbose)
		std::cout << "\e[33mBureaucrat constructor called\e[0m" << std::endl; 
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
		std::cout << "\e[33mBureaucrat constructor called for " << this->_name << "\e[0m" << std::endl; 
}

Bureaucrat::Bureaucrat(Bureaucrat const & copy) :
_name(copy.getName()), _grade(copy.getGrade())
{
	if (Bureaucrat::_verbose)
		std::cout << "\e[33mBureaucrat copy constructor called\e[0m" << std::endl; 
}

Bureaucrat::~Bureaucrat(void)
{
	if (Bureaucrat::_verbose)
		std::cout << "\e[33mBureaucrat destructor called\e[0m" << std::endl; 
}

/* ************************************************************************** */
/*                     Surcharge d'operateur                                  */
/* ************************************************************************** */
Bureaucrat & Bureaucrat::operator=(Bureaucrat const & bureaucrat)
{
	this->_grade = bureaucrat.getGrade();
	if (Bureaucrat::_verbose)
		std::cout << "\e[33mBureaucrat assignement operator called. Warning, name is const and cannot be changed\e[0m"
		<< std::endl;
	return (*this);
}

std::ostream & operator<<(std::ostream & o, Bureaucrat const & bureaucrat)
{
	o << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
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

void	Bureaucrat::signForm(Form & form)
{
	try
	{
		form.beSigned(*this);
		std::cout << this->_name << " signed " << form.getName() << std::endl;
	}
	catch (Form::GradeTooLowException &e)
	{
		std::cout << this->_name << " couldn't sign " << form.getName() 
		<< " because his/her grade is not high enouth." << std::endl;
	}
}

/* ************************************************************************** */
/*                     Exceptions                                             */
/* ************************************************************************** */

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too high to initialise or increment...");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too low to initialise or decrement...");
}
