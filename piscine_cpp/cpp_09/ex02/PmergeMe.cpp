/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 15:48:44 by mbocquel          #+#    #+#             */
/*   Updated: 2023/05/26 18:49:24 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/* ************************************************************************** */
/*                     Constructeurs et destructeurs                          */
/* ************************************************************************** */
PmergeMe::PmergeMe(void)
{
}

PmergeMe::PmergeMe(PmergeMe const & copy)
{
	*this = copy;
}

PmergeMe::~PmergeMe(void)
{
}

/* ************************************************************************** */
/*                     Surcharge d'operateur                                  */
/* ************************************************************************** */

PmergeMe & PmergeMe::operator=(PmergeMe const & p_mergeme)
{
	if (this != &p_mergeme)
	{
		this->_my_vector = p_mergeme._my_vector;
		this->_my_deque = p_mergeme._my_deque;
	}
	return (*this);
}

/* ************************************************************************** */
/*                     Methodes                                               */
/* ************************************************************************** */
void	PmergeMe::add_vector(char **argv)
{
	int i = 0;
	int j;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if ((argv[i][j] < '0' || argv[i][j] > '9') && argv[i][j] != '+')
				throw input_error();
			j++;
		}
		this->_my_vector.push_back(atoi(argv[i]));
		i++;
	}
}

void	PmergeMe::add_deque(char **argv)
{
	int i = 0;
	int j;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if ((argv[i][j] < '0' || argv[i][j] > '9') && argv[i][j] != '+')
				throw input_error();
			j++;
		}
		this->_my_deque.push_back(atoi(argv[i]));
		i++;
	}
}

void	PmergeMe::sort_vector(void)
{
	std::vector< std::pair<int, int> >	vect;
	std::vector<int>::iterator			it = this->_my_vector.begin();
	int last = -1;
	if (this->_my_vector.size() % 2 != 0)
	{
		last = this->_my_vector.back();
		this->_my_vector.pop_back();
	}
	while (it != this->_my_vector.end())
	{
		vect.push_back(std::make_pair(*it, *(++it)));
		++it;
	}
	//A finir https://codereview.stackexchange.com/questions/116367/ford-johnson-merge-insertion-sort
}

void	PmergeMe::sort_deque(void)
{
	
}

void	PmergeMe::view_deque(void)
{
	std::deque<int>::iterator it = this->_my_deque.begin();
	while (it != this->_my_deque.end())
	{
		std::cout << *it << " ";
		++it;
	}
	std::cout << std::endl;
}

void	PmergeMe::view_vector(void)
{
	std::vector<int>::iterator it = this->_my_vector.begin();
	while (it != this->_my_vector.end())
	{
		std::cout << *it << " ";
		++it;
	}
	std::cout << std::endl;
}

/* ************************************************************************** */
/*                     Exceptions                                             */
/* ************************************************************************** */
const char* PmergeMe::input_error::what() const throw()
{
	return ("Error");
}