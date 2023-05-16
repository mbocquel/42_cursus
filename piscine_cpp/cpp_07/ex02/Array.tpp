/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 13:25:36 by mbocquel          #+#    #+#             */
/*   Updated: 2023/05/16 14:27:41 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
# define ARRAY_TPP

/* ************************************************************************** */
/*                     Constructeurs et destructeurs                          */
/* ************************************************************************** */
template<typename T>
Array<T>::Array(void)
{
	this->_size = 0;
	this->_array = NULL;
}

template<typename T>
Array<T>::Array(Array<T> const & copy) : _size(copy._size)
{
	this->_size = copy._size;
	if (this->_size == 0)
	{
		this->_array = NULL;
		return ;
	}
	else
	{
		this->_array = new T[this->_size];
		if (this->_array == NULL)
			throw std::exception();
		for (unsigned int i = 0; i < this->_size; i++)
			this->_array[i] = copy._array[i];
	}
}

template<typename T>
Array<T>::Array(unsigned int n)
{
	this->_size = n;
	this->_array = new T[n];
	if (this->_array == NULL)
		throw std::exception();
}

template<typename T>
Array<T>::~Array(void)
{
	if (this->_array != NULL)
		delete [] this->_array;
}

/* ************************************************************************** */
/*                     Surcharge d'operateur                                  */
/* ************************************************************************** */

template<typename T>
Array<T> & Array<T>::operator=(Array<T> const & arr)
{
	if (this->_array)
		delete this->_array;
	this->_size = arr._size;
	if (this->_size == 0)
		this->_array = NULL;
	else
	{
		this->_array = new T[this->_size];
		if (this->_array == NULL)
			throw std::exception();
		for (unsigned int i = 0; i < this->_size; i++)
			this->_array[i] = arr._array[i];
	}
	return (*this);
}

template<typename T>
T & 			Array<T>::operator[](unsigned int n) const
{
	if (n >= this->_size)
		throw Array<T>::InvalidIndex();
	return (this->_array[n]);
}

/* ************************************************************************** */
/*                     Methodes                                               */
/* ************************************************************************** */

template<typename T>
unsigned int	Array<T>::size(void) const
{
	return (this->_size);
}

/* ************************************************************************** */
/*                     Exception                                              */
/* ************************************************************************** */

template<class T> 
const char *Array<T>::InvalidIndex::what() const throw()
{
	return ("Invalid Index");
}

#endif