/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 15:48:44 by mbocquel          #+#    #+#             */
/*   Updated: 2023/05/29 12:36:11 by mbocquel         ###   ########.fr       */
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

int		PmergeMe::ft_atoi(char *str)
{
	int i = 0;
	while (str[i])
	{
		if ((str[i] < '0' || str[i] > '9') && str[i] != '+')
			throw input_error();
		i++;
	}
	return (atoi(str));
}

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


void	PmergeMe::sort_vector(char **argv, int len)
{
	std::vector< std::pair<int, int> >	vect;
	int last = -1;
	
	/* Je sauvegarde le dernier si besoin*/
	if (len % 2 != 0)
	{
		last = this->ft_atoi(argv[len - 1]);
		len--;
	}
	/*On cree les paires */
	for (int i = 0; i < len - 1; i = i + 2)
		vect.push_back(std::make_pair(this->ft_atoi(argv[i]), this->ft_atoi(argv[i + 1])));

	/*On trie chaque pair */
	for (std::vector< std::pair<int,int> >::iterator it = vect.begin(); it != vect.end(); ++it)
	{
		if (it->first > it->second)
		{
			int tmp = it->first;
			it->first = it->second;
			it->second = tmp;
		}
		std::cout << "[" << it->first << " , " << it->second << "]" << std::endl;
	}
	std::cout <<  std::endl;
	/*J'odronnes les pairs en fonctions de leur plus grand nombre*/
	this->merge_sort_recursion_vector(vect, 0, vect.size() - 1);
	for (std::vector< std::pair<int,int> >::iterator it = vect.begin(); it != vect.end(); ++it)
		std::cout << "[" << it->first << " , " << it->second << "]" << std::endl;
	
	/*Je rajoute les grands nombres dans le vecteurs final*/
	for (std::vector< std::pair<int,int> >::iterator it = vect.begin(); it != vect.end(); ++it)
		this->_my_vector.push_back(it->second);
	
	/*J'insert le plus petit elements dans le vecteur*/
	this->_my_vector.insert(this->_my_vector.begin(), vect.begin()->first);

	std::cout << "PmergeMe::find_element_index_vector(int val) : " << this->find_element_index_vector(*(this->_my_vector.begin()++)) << std::endl;
	




	
	
	// puis on utilise un binary search insertion algo pour ajouter les autres valeurs dans la chaine principale. 
	// et si jamais il reste une last elem, il faut aussi le rajouter.
	(void)last;
	//A finir https://codereview.stackexchange.com/questions/116367/ford-johnson-merge-insertion-sort
}

int		PmergeMe::find_element_index_vector(int val)
{

	//A fix
	int left = 0;
	int right = this->_my_vector.size() - 1;
	int mid;
	
	while (left != right)
	{
		mid = (left + right) / 2;
		if (this->_my_vector[mid] > val)
			right = mid - 1;
		else
			left = mid;
	}
    return (left);
}

void 	PmergeMe::merge_sort_recursion_vector(std::vector< std::pair<int, int> > & vect_pair,
		int left, int right)
{
	if (left < right)
	{
		int	middle = left + (right - left) / 2;

		this->merge_sort_recursion_vector(vect_pair, left, middle);
		this->merge_sort_recursion_vector(vect_pair, middle + 1, right);
		this->merge_sorted_arrays_vector(vect_pair, left, middle, right);
	}
}

void 	PmergeMe::merge_sorted_arrays_vector(std::vector< std::pair<int, int> > & vect_pair,
			int left, int middle, int right)
{
	int	left_length = middle - left + 1;
	int	right_length = right - middle;

	std::vector< std::pair<int, int> > temp_left;
	std::vector< std::pair<int, int> > temp_right;

	for (int i = 0; i < left_length; i++)
		temp_left.push_back(vect_pair[left + i]);
	for (int i = 0; i < right_length; i++)
		temp_right.push_back(vect_pair[middle + 1 + i]);
	for (int i = 0, j = 0, k = left; k <= right; k++)
	{
		if ((i < left_length) &&
			(j >= right_length || temp_left[i].second <= temp_right[j].second))
		{
			vect_pair[k] = temp_left[i];
			i++;
		}
		else
		{
			vect_pair[k] = temp_right[j];
			j++;
		}
	}
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