/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 10:43:35 by mbocquel          #+#    #+#             */
/*   Updated: 2023/05/26 11:50:19 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

bool	RPN::_verbose = false;

/* ************************************************************************** */
/*                     Constructeurs et destructeurs                          */
/* ************************************************************************** */
RPN::RPN(void)
{
	if (RPN::_verbose)
		std::cout << "RPN default constructor called." << std::endl;
}

RPN::RPN(RPN const & copy)
{
	if (RPN::_verbose)
		std::cout << "RPN copy constructor called." << std::endl;
	*this = copy;
}

RPN::~RPN(void)
{
	if (RPN::_verbose)
		std::cout << "RPN destructor called." << std::endl;
}

/* ************************************************************************** */
/*                     Surcharge d'operateur                                  */
/* ************************************************************************** */
RPN &	RPN::operator=(RPN const & rpn)
{
	if (this != &rpn)
	{
		while (this->_my_stack.size() > 0)
			this->_my_stack.pop();
		this->_my_stack = rpn._my_stack;
	}
	if (RPN::_verbose)
		std::cout << "RPN copy assignment operator called" << std::endl;
	return (*this);
}

/* ************************************************************************** */
/*                     Methodes                                               */
/* ************************************************************************** */
void	RPN::rpn_add(std::string elem)
{
	
}

int		RPN::result(void) const
{
	if (this->_my_stack.size() != 1)
		throw rpn_error();
	return (this->_my_stack.top());
}

/* ************************************************************************** */
/*                     Exceptions                                             */
/* ************************************************************************** */
const char* RPN::rpn_error::what() const throw()
{
	return ("Error");
}
