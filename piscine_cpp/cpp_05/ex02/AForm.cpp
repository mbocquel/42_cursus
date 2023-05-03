/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:22:58 by mbocquel          #+#    #+#             */
/*   Updated: 2023/05/03 18:40:02 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

/* ************************************************************************** */
/*                     Constructeurs et destructeurs                          */
/* ************************************************************************** */
bool	AForm::_verbose = false;

AForm::AForm(void) :
_name(""), _signed(false), _grade_to_sign(1), _grade_to_execute(1)
{
	if (AForm::_verbose)
		std::cout << "AForm constructor called" << std::endl;
}

AForm::AForm(std::string const form_name, int const grade_to_sign, int const grade_to_execute) :
_name(form_name), _signed(false), _grade_to_sign(grade_to_sign), _grade_to_execute(grade_to_execute)
{
	if (AForm::_verbose)
		std::cout << "AForm constructor called" << std::endl;
}

AForm::AForm(AForm const & copy) :
_name(copy.getName()),
_signed(copy.getSigned()),
_grade_to_sign(copy.getGrade_to_sign()),
_grade_to_execute(copy.getGrade_to_execute())
{
	if (AForm::_verbose)
		std::cout << "AForm copy constructor called" << std::endl;
}

AForm::~AForm(void)
{
	if (AForm::_verbose)
		std::cout << "AForm destructor called" << std::endl;
}

/* ************************************************************************** */
/*                     Surcharge d'operateur                                  */
/* ************************************************************************** */

AForm & AForm::operator=(AForm const & form)
{
	(void)form;
	if (AForm::_verbose)
	{
		std::cout << "Form assignement operator called. " 
		<<"Warning, nothing changed because const param..." << std::endl;
	}
	return (*this);
}

std::ostream & operator<<(std::ostream & o, AForm const & form)
{
	o << "Form " << form.getName() << (form.getSigned() ? " (signed) | " : " (not signed) | ")
	<< "Minimum grade to sign: "<< form.getGrade_to_sign() << " | Minimum grade to execute: "
	<< form.getGrade_to_execute();
	return o;
}

/* ************************************************************************** */
/*                     Methodes                                               */
/* ************************************************************************** */

std::string const	AForm::getName(void) const
{
	return (this->_name);
}

bool	AForm::getSigned(void) const
{
	return (this->_signed);
}

int	AForm::getGrade_to_sign(void) const
{
	return (this->_grade_to_sign);
}

int AForm::getGrade_to_execute(void) const
{
	return (this->_grade_to_execute);
}

void	AForm::beSigned(Bureaucrat const & bur_to_sng)
{
	if (bur_to_sng.getGrade() <= this->_grade_to_sign)
		this->_signed = true;
	else
		throw GradeTooLowException();
}

/* ************************************************************************** */
/*                     Exceptions                                             */
/* ************************************************************************** */

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("Form grade too low exception");
}