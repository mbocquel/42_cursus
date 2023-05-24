/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutanStack.tpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 15:25:37 by mbocquel          #+#    #+#             */
/*   Updated: 2023/05/24 14:40:10 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTAN_STACK_TPP
# define MUTAN_STACK_TPP

/* ************************************************************************** */
/*                     Constructeurs et destructeurs                          */
/* ************************************************************************** */

template <typename T, typename Container>
MutantStack<T, Container>::MutantStack(void)
{
}

template <typename T, typename Container>
MutantStack<T, Container>::MutantStack(MutantStack<T, Container> const & copy)
{
	this->c = copy.c;
}

template <typename T, typename Container>
MutantStack<T, Container>::~MutantStack(void)
{
}

/* ************************************************************************** */
/*                     Surcharge d'operateur                                  */
/* ************************************************************************** */
template <typename T, typename Container>
MutantStack<T, Container> & MutantStack<T, Container>::operator=(MutantStack<T, Container> const & m_stack)
{
	if (this != &m_stack)
	{
		while (this->size() > 0)
			this->pop();
		this->c = m_stack.c;
	}
	return (*this);
}


/* ************************************************************************** */
/*                     Methodes                                               */
/* ************************************************************************** */
template <typename T, typename Container>
typename MutantStack<T, Container>::iterator	MutantStack<T, Container>::begin(void)
{
	return (this->c.begin());	
}

template <typename T, typename Container>
typename MutantStack<T, Container>::iterator	MutantStack<T, Container>::end(void)
{
	return (this->c.end());
}

template <typename T, typename Container>
typename MutantStack<T, Container>::reverse_iterator	MutantStack<T, Container>::rbegin(void)
{
	return (this->c.rbegin());
}

template <typename T, typename Container>
typename MutantStack<T, Container>::reverse_iterator	MutantStack<T, Container>::rend(void)
{
	return (this->c.rend());
}


#endif