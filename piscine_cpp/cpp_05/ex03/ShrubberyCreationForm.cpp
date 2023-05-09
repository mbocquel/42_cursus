/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 17:48:52 by mbocquel          #+#    #+#             */
/*   Updated: 2023/05/04 15:55:36 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

bool	ShrubberyCreationForm::_verbose = true;
/* ************************************************************************** */
/*                     Constructeurs et destructeurs                          */
/* ************************************************************************** */
ShrubberyCreationForm::ShrubberyCreationForm(void) : 
AForm::AForm("ShrubberyCreationForm", 145, 137)
{
	if (ShrubberyCreationForm::_verbose)
		std::cout << "\e[96mDefault constructor called for ShrubberyCreationForm\e[0m"<< std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : 
AForm::AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	if (ShrubberyCreationForm::_verbose)
		std::cout << "\e[96mShrubberyCreationForm constructor called with target.\e[0m"<< std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & copy) :
AForm::AForm("ShrubberyCreationForm", 145, 137), _target(copy.getTarget())
{
	if (ShrubberyCreationForm::_verbose)
		std::cout << "\e[96mShrubberyCreationForm constructor called with target.\e[0m"<< std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	if (ShrubberyCreationForm::_verbose)
		std::cout << "\e[96mShrubberyCreationForm destructor called\e[0m"<< std::endl;
}


/* ************************************************************************** */
/*                     Surcharge d'operateur                                  */
/* ************************************************************************** */

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const & form)
{
	if (ShrubberyCreationForm::_verbose)
	{
		this->_target = form.getTarget();
		std::cout << "\e[96mShrubberyCreationForm assignement operator called.\e[0m" << std::endl;
	}
	return (*this);
}

std::ostream & operator<<(std::ostream & o, ShrubberyCreationForm const & form)
{
	o << "\e[96mForm " << form.getName() << (form.getSigned() ? " (signed) | " : " (not signed) | ")
	<< "Minimum grade to sign: "<< form.getGrade_to_sign() << " | Minimum grade to execute: "
	<< form.getGrade_to_execute() << " | Target: " << form.getTarget() << "\e[0m";
	return o;
}

/* ************************************************************************** */
/*                     Methodes                                               */
/* ************************************************************************** */
std::string ShrubberyCreationForm::getTarget(void) const
{
	return (this->_target);
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	try
	{
		this->check_executable(executor);
		std::ofstream file_out((this->_target + "_shrubbery").c_str());
		if (file_out.fail())
			throw ShrubberyCreationFileFailed();
		file_out << "            .        +          .      .          .     " << std::endl
		<< "     .            _        .                    .                " << std::endl
		<< "  ,              /;-._,-.____        ,-----.__                   " << std::endl
		<< " ((        .    (_:#::_.:::. `-._   /:, /-._, `._,               " << std::endl
		<< "  `                 \\   _|`\"=:_::.`.);  \\ __/ /               " << std::endl
		<< "                      ,    `./  \\:. `.   )==-'  .               " << std::endl
		<< "    .      ., ,-=-.  ,\\, +#./`   \\:.  / /           .          " << std::endl
		<< ".           \\/:/`-' , ,\\ '` ` `   ): , /_  -o                  " << std::endl
		<< "       .    /:+- - + +- : :- + + -:'  /(o-) \\)     .            " << std::endl
		<< "  .      ,=':  \\    ` `/` ' , , ,:' `'--\".--\"---._/`7         " << std::endl
		<< "   `.   (    \\: \\,-._` ` + '\\, ,\"   _,--._,---\":.__/        " << std::endl
		<< "              \\:  `  X` _| _,\\/'   .-'                         " << std::endl
		<< ".               \":._:`\\____  /:'  /      .           .         " << "          &&& &&  & &&          " << std::endl
		<< "                    \\::.  :\\/:'  /              +              " << "      && &\\/&\\|& ()|/ @, &&   " << std::endl
		<< "   .                 `.:.  /:'  }      .                         " << "  &\\/(/&/&||/& /_/)_&/_&       " << std::endl
		<< "           .           ):_(:;   \\           .                   " << " &() &\\/&|()|/&\\/ '% & ()     " << std::endl
		<< "                      /:. _/ ,  |                                " << "&_\\_&&_\\ |& |&&/&__%_/_& &&   " << std::endl
		<< "                   . (|::.     ,`                  .             " << "&&   && & &| &| /& & % ()& /&&  " << std::endl
		<< "     .                |::.    {\\                                " << " ()&_---()&\\&\\|&&-&&--%---()~ " << std::endl
		<< "                      |::.\\  \\ `.                              " << "     &&     \\|||               " << std::endl
		<< "                      |:::(\\    |                               " << "            |||                 " << std::endl
		<< "              O       |:::/{ }  |                  (o            " << "           |||                  " << std::endl
		<< "               )  ___/#\\::`/ (O \"==._____   O, (O  /`          " << "             |||                " << std::endl
		<< "          ~~~w/w~\"~~,\\` `:/,-(~`\"~~~~~~~~\"~o~\\~/~w|/~       " << "       , -=-~  .-^- _           " << std::endl;
		file_out.close();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		throw AForm::ExecutionFailed();
	}
}

/* ************************************************************************** */
/*                     Exceptions                                             */
/* ************************************************************************** */

const char* ShrubberyCreationForm::ShrubberyCreationFileFailed::what() const throw()
{
	return ("\e[91mThe creation of the Shrubbery failed...\e[0m");
}
