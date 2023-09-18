/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:22:58 by mbocquel          #+#    #+#             */
/*   Updated: 2023/05/09 16:07:18 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

/* ************************************************************************** */
/*                     Constructeurs et destructeurs                          */
/* ************************************************************************** */
bool	Form::_verbose = true;

Form::Form(void) :
_name(""), _signed(false), _grade_to_sign(1), _grade_to_execute(1)
{
	if (Form::_verbose)
		std::cout << "Form constructor called" << std::endl;
}

Form::Form(std::string const form_name, int const grade_to_sign, int const grade_to_execute) :
_name(form_name), _signed(false), _grade_to_sign(grade_to_sign), _grade_to_execute(grade_to_execute)
{
	if (grade_to_sign <= 0 || grade_to_execute <= 0)
		throw GradeTooHighException();
	else if (grade_to_sign > 150 || grade_to_execute > 150)
		throw GradeTooLowException();
	if (Form::_verbose)
		std::cout << "Form constructor called" << std::endl;
}

Form::Form(Form const & copy):
_name(copy.getName()),
_signed(copy.getSigned()),
_grade_to_sign(copy.getGrade_to_sign()),
_grade_to_execute(copy.getGrade_to_execute())
{
	if (Form::_verbose)
		std::cout << "Form copy constructor called" << std::endl;
}

Form::~Form(void)
{
	if (Form::_verbose)
		std::cout << "Form destructor called" << std::endl;
}

/* ************************************************************************** */
/*                     Surcharge d'operateur                                  */
/* ************************************************************************** */

Form & Form::operator=(Form const & form)
{
	(void)form;
	if (Form::_verbose)
	{
		std::cout << "Form assignement operator called. " 
		<<"Warning, nothing changed because const param..." << std::endl;
	}
	return (*this);
}

std::ostream & operator<<(std::ostream & o, Form const & form)
{
	o << "Form " << form.getName() << (form.getSigned() ? " (signed) | " : " (not signed) | ")
	<< "Minimum grade to sign: "<< form.getGrade_to_sign() << " | Minimum grade to execute: "
	<< form.getGrade_to_execute();
	return o;
}

/* ************************************************************************** */
/*                     Methodes                                               */
/* ************************************************************************** */

std::string const	Form::getName(void) const
{
	return (this->_name);
}

bool	Form::getSigned(void) const
{
	return (this->_signed);
}

int	Form::getGrade_to_sign(void) const
{
	return (this->_grade_to_sign);
}

int Form::getGrade_to_execute(void) const
{
	return (this->_grade_to_execute);
}

void				Form::beSigned(Bureaucrat const & bur_to_sng)
{
	if (bur_to_sng.getGrade() <= this->_grade_to_sign)
		this->_signed = true;
	else
		throw GradeTooLowException();
}

/* ************************************************************************** */
/*                     Exceptions                                             */
/* ************************************************************************** */

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Form grade too low exception");
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("Form grade too high exception");
}
