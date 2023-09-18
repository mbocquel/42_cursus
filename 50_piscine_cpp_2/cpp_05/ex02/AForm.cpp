/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:22:58 by mbocquel          #+#    #+#             */
/*   Updated: 2023/05/09 16:15:38 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

/* ************************************************************************** */
/*                     Constructeurs et destructeurs                          */
/* ************************************************************************** */
bool	AForm::_verbose = true;

AForm::AForm(void) :
_name(""), _signed(false), _grade_to_sign(1), _grade_to_execute(1)
{
	if (AForm::_verbose)
		std::cout << "\e[93mAForm constructor called\e[0m" << std::endl;
}

AForm::AForm(std::string const form_name, int const grade_to_sign, int const grade_to_execute) :
_name(form_name), _signed(false), _grade_to_sign(grade_to_sign), _grade_to_execute(grade_to_execute)
{
	if (grade_to_sign <= 0 || grade_to_execute <= 0)
		throw GradeTooHighException();
	else if (grade_to_sign > 150 || grade_to_execute > 150)
		throw GradeTooLowException();
	if (AForm::_verbose)
		std::cout << "\e[93mAForm constructor called\e[0m" << std::endl;
}

AForm::AForm(AForm const & copy) :
_name(copy.getName()),
_signed(copy.getSigned()),
_grade_to_sign(copy.getGrade_to_sign()),
_grade_to_execute(copy.getGrade_to_execute())
{
	if (AForm::_verbose)
		std::cout << "\e[93mAForm copy constructor called\e[0m" << std::endl;
}

AForm::~AForm(void)
{
	if (AForm::_verbose)
		std::cout << "\e[93mAForm destructor called\e[0m" << std::endl;
}

/* ************************************************************************** */
/*                     Surcharge d'operateur                                  */
/* ************************************************************************** */

AForm & AForm::operator=(AForm const & form)
{
	(void)form;
	if (AForm::_verbose)
	{
		std::cout << "\e[93mForm assignement operator called. " 
		<<"Warning, nothing changed because const param...\e[0m" << std::endl;
	}
	return (*this);
}

std::ostream & operator<<(std::ostream & o, AForm const & form)
{
	o << "\e[93mForm " << form.getName() << (form.getSigned() ? " (signed) | " : " (not signed) | ")
	<< "Minimum grade to sign: "<< form.getGrade_to_sign() << " | Minimum grade to execute: "
	<< form.getGrade_to_execute() << "\e[0m";
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

void	AForm::check_executable(Bureaucrat const & executor) const
{
	if (this->getSigned() == false)
		throw FormNotSigned();
	else if (this->getGrade_to_execute() < executor.getGrade())
		throw Bureaucrat::GradeTooLowException();
}


/* ************************************************************************** */
/*                     Exceptions                                             */
/* ************************************************************************** */

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("\e[91mForm grade too low exception\e[0m");
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("\e[91mForm grade too high exception\e[0m");
}

const char* AForm::FormNotSigned::what() const throw()
{
	return ("\e[91mThe form is not signed\e[0m");
}

const char* AForm::ExecutionFailed::what() const throw()
{
	return ("\e[91mThe form execution failed\e[0m");
}
