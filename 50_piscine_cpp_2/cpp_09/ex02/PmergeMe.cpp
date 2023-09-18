/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 15:48:44 by mbocquel          #+#    #+#             */
/*   Updated: 2023/05/29 15:04:36 by mbocquel         ###   ########.fr       */
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

void	PmergeMe::sort_vector(char **argv, int len)
{
	std::vector< std::pair<int, int> >	vect;
	int 	last = 0;
	bool	even = true;
	
	/* Je sauvegarde le dernier si besoin */
	if (len % 2 != 0)
	{
		last = this->ft_atoi(argv[len - 1]);
		len--;
		even = false;
	}
	/*On cree les pairs */
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
	}
	/*J'odronnes les pairs en fonctions de leur plus grand nombre*/
	this->merge_sort_recursion_vector(vect, 0, vect.size() - 1);
	/*Je rajoute les grandes valeurs dans le vecteurs final*/
	for (std::vector< std::pair<int,int> >::iterator it = vect.begin(); it != vect.end(); ++it)
		this->_my_vector.push_back(it->second);
	/*J'insert les petites valeurs les valeurs*/
	for (std::vector< std::pair<int,int> >::iterator it = vect.begin(); it != vect.end(); ++it)
		this->_my_vector.insert(this->_my_vector.begin() + this->find_element_index_vector(it->first), it->first);
	/*Je rajoute le dernier si necessaire*/
	if (!even)
		this->_my_vector.insert(this->_my_vector.begin() + this->find_element_index_vector(last), last);
}

int		PmergeMe::find_element_index_vector(int val)
{
	int left = 0;
	int right = this->_my_vector.size();
	int mid;
	
	while (left < right)
	{
		mid = (left + right) / 2;
		if (this->_my_vector[mid] > val)
			right = mid;
		else
			left = mid + 1;
	}
	return (right);
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

/* Voir commentaires pour le vecteur */
void	PmergeMe::sort_deque(char **argv, int len)
{
	std::deque< std::pair<int, int> >	deque_pair;
	int 	last = 0;
	bool	even = true;
	
	if (len % 2 != 0)
	{
		last = this->ft_atoi(argv[len - 1]);
		len--;
		even = false;
	}
	for (int i = 0; i < len - 1; i = i + 2)
		deque_pair.push_back(std::make_pair(this->ft_atoi(argv[i]), this->ft_atoi(argv[i + 1])));
	for (std::deque< std::pair<int,int> >::iterator it = deque_pair.begin(); it != deque_pair.end(); ++it)
	{
		if (it->first > it->second)
		{
			int tmp = it->first;
			it->first = it->second;
			it->second = tmp;
		}
	}
	this->merge_sort_recursion_deque(deque_pair, 0, deque_pair.size() - 1);
	for (std::deque< std::pair<int,int> >::iterator it = deque_pair.begin(); it != deque_pair.end(); ++it)
		this->_my_deque.push_back(it->second);
	for (std::deque< std::pair<int,int> >::iterator it = deque_pair.begin(); it != deque_pair.end(); ++it)
		this->_my_deque.insert(this->_my_deque.begin() + this->find_element_index_deque(it->first), it->first);
	if (!even)
		this->_my_deque.insert(this->_my_deque.begin() + this->find_element_index_deque(last), last);
}

void 	PmergeMe::merge_sort_recursion_deque(std::deque< std::pair<int, int> > & deque_pair,
		int left, int right)
{
	if (left < right)
	{
		int	middle = left + (right - left) / 2;

		this->merge_sort_recursion_deque(deque_pair, left, middle);
		this->merge_sort_recursion_deque(deque_pair, middle + 1, right);
		this->merge_sorted_arrays_deque(deque_pair, left, middle, right);
	}
}

void 	PmergeMe::merge_sorted_arrays_deque(std::deque< std::pair<int, int> > & deque_pair,
		int left, int middle, int right)
{
	int	left_length = middle - left + 1;
	int	right_length = right - middle;

	std::deque< std::pair<int, int> > temp_left;
	std::deque< std::pair<int, int> > temp_right;

	for (int i = 0; i < left_length; i++)
		temp_left.push_back(deque_pair[left + i]);
	for (int i = 0; i < right_length; i++)
		temp_right.push_back(deque_pair[middle + 1 + i]);
	for (int i = 0, j = 0, k = left; k <= right; k++)
	{
		if ((i < left_length) &&
			(j >= right_length || temp_left[i].second <= temp_right[j].second))
		{
			deque_pair[k] = temp_left[i];
			i++;
		}
		else
		{
			deque_pair[k] = temp_right[j];
			j++;
		}
	}
}

int		PmergeMe::find_element_index_deque(int val)
{
	int left = 0;
	int right = this->_my_deque.size();
	int mid;
	
	while (left < right)
	{
		mid = (left + right) / 2;
		if (this->_my_deque[mid] > val)
			right = mid;
		else
			left = mid + 1;
	}
	return (right);
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