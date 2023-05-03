/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 10:46:15 by mbocquel          #+#    #+#             */
/*   Updated: 2023/05/03 15:13:21 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/* ************************************************************************** */
/*                     Constructeurs et destructeurs                          */
/* ************************************************************************** */
Bureaucrat::Bureaucrat(void)
{
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	if (grade >= 1 && grade <= 150)
		this->_grade = grade;
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		throw Bureaucrat::GradeTooHighException();
	std::cout << "\e[33mBureaucrat constructor called for " << this->_name << "\e[0m" << std::endl; 
}

Bureaucrat::Bureaucrat(Bureaucrat const & copy) :
_name(copy.getName()), _grade(copy.getGrade())
{
	std::cout << "\e[33mBureaucrat copy constructor called\e[0m" << std::endl; 
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "\e[33mBureaucrat destructor called\e[0m" << std::endl; 
}

/* ************************************************************************** */
/*                     Surcharge d'operateur                                  */
/* ************************************************************************** */
Bureaucrat & Bureaucrat::operator=(Bureaucrat const & bureaucrat)
{
	this->_grade = bureaucrat.getGrade();
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
		throw Bureaucrat::GradeTooHighException();
}

void	Bureaucrat::decrement_grade(void)
{
	if (this->_grade < 150)
		this->_grade++;
	else
		throw Bureaucrat::GradeTooLowException();
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
