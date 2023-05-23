/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 11:21:43 by mbocquel          #+#    #+#             */
/*   Updated: 2023/05/23 14:28:01 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

bool	Span::_verbose = false;


/* ************************************************************************** */
/*                     Constructeurs et destructeurs                          */
/* ************************************************************************** */
Span::Span(void)
{
	if (Span::_verbose)
		std::cout << "Span default constructor called." << std::endl;
}

Span::Span(unsigned int N) : _max_size(N)
{
	if (Span::_verbose)
		std::cout << "Span constructor called for " << N << " max size." << std::endl;
}

Span::Span(Span const & copy) : _max_size(copy._max_size)
{
	this->_set.insert(copy._set.begin(), copy._set.end());
	if (Span::_verbose)
		std::cout << "Span copy constuctor called." << std::endl;
}

Span::~Span(void)
{
	if (Span::_verbose)
		std::cout << "Span destructor called." << std::endl;
}

/* ************************************************************************** */
/*                     Surcharge d'operateur                                  */
/* ************************************************************************** */
Span & Span::operator=(Span const & span)
{
	if (this != &span)
	{
		this->_set.clear();
		this->_set.insert(span._set.begin(), span._set.end());
		this->_max_size = span._max_size;
	}
	return (*this);
}

/* ************************************************************************** */
/*                     Methodes                                               */
/* ************************************************************************** */
void	Span::addNumber(int num)
{
	if (this->_set.size() >= this->_max_size)
		throw TooManyNumbersException();
	this->_set.insert(num);
}

void	Span::addNumber(std::set<int>::iterator begin_it, std::set<int>::iterator end_it)
{
	if (std::distance(begin_it, end_it) + this->_set.size() > this->_max_size)
		throw TooManyNumbersException();
	this->_set.insert(begin_it, end_it);
}

void	Span::addNumber(std::vector<int>::iterator begin_it, std::vector<int>::iterator end_it)
{
	if (std::distance(begin_it, end_it) + this->_set.size() > this->_max_size)
		throw TooManyNumbersException();
	this->_set.insert(begin_it, end_it);
}

void	Span::addNumber(std::list<int>::iterator begin_it, std::list<int>::iterator end_it)
{
	if (std::distance(begin_it, end_it) + this->_set.size() > this->_max_size)
		throw TooManyNumbersException();
	this->_set.insert(begin_it, end_it);
}

void	Span::addNumber(std::deque<int>::iterator begin_it, std::deque<int>::iterator end_it)
{
	if (std::distance(begin_it, end_it) + this->_set.size() > this->_max_size)
		throw TooManyNumbersException();
	this->_set.insert(begin_it, end_it);
}

int	Span::shortestSpan(void)
{
	int	min = this->longestSpan();
	
	if (this->_set.size() < 2)
		throw NotEnoughNumberException();
	for (std::set<int>::iterator it = this->_set.begin(); it != --(this->_set.end()); it++)
	{
		if (*(this->_set.upper_bound(*it)) - *it < min)
			min = *(this->_set.upper_bound(*it)) - *it;
	}
	return (min);
}

int	Span::longestSpan(void)
{
	return (*(--this->_set.end()) - *(this->_set.begin()));
}

void	Span::printSpan(std::ostream & o)
{
	if (this->_set.size() >= 2)
	{
		for (std::set<int>::iterator it = this->_set.begin(); it != --(this->_set.end()); ++it)
		{
			o << *it << " -> " << *(this->_set.upper_bound(*it)) << " : " << *(this->_set.upper_bound(*it)) - *it << " " << std::endl;
		}
	}
	o << std::endl;
}

void	Span::printSet(std::ostream & o)
{
	for (std::set<int>::iterator it = this->_set.begin(); it != this->_set.end(); ++it)
		o << ' ' << *it;
	o << std::endl;
}

unsigned int	Span::getSize(void)
{
	return (this->_set.size());
}

/* ************************************************************************** */
/*                     Exceptions                                             */
/* ************************************************************************** */

const char* Span::TooManyNumbersException::what() const throw()
{
	return ("\e[91mError: Too many numbers in the span\e[0m");
}

const char* Span::NotEnoughNumberException::what() const throw()
{
	return ("\e[91mError: Not enough numbers in the span\e[0m");
}
