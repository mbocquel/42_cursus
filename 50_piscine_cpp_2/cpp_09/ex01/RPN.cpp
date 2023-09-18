/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 10:43:35 by mbocquel          #+#    #+#             */
/*   Updated: 2023/05/26 15:17:16 by mbocquel         ###   ########.fr       */
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
	std::string	token("+-/*");
	
	if (elem.size() != 1
		|| (token.find(elem.at(0)) != std::string::npos && this->_my_stack.size() < 2)
		|| !(token.find(elem.at(0)) != std::string::npos || (elem.at(0) >= '0' && elem.at(0) <= '9')))
	{
		throw rpn_error();
	}
	if (token.find(elem.at(0)) != std::string::npos)
	{
		int	a = this->_my_stack.top();
		this->_my_stack.pop();
		int	b = this->_my_stack.top();
		this->_my_stack.pop();
		switch (token.find(elem.at(0)))
		{
		case 0:
			this->_my_stack.push(b + a);
			break;
		case 1:
			this->_my_stack.push(b - a);
			break;
		case 2:
			if (a == 0)
				throw rpn_error();
			this->_my_stack.push(b / a);
			break;
		default:
			this->_my_stack.push(b * a);
			break;
		}
	}
	else
		this->_my_stack.push(elem.at(0) - '0');
}

int		RPN::result(void) const
{
	if (this->_my_stack.size() != 1)
	{
		throw rpn_error();
	}
	return (this->_my_stack.top());
}


/* ************************************************************************** */
/*                     Exceptions                                             */
/* ************************************************************************** */
const char* RPN::rpn_error::what() const throw()
{
	return ("Error");
}
