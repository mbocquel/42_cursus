/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutanStack.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 15:24:58 by mbocquel          #+#    #+#             */
/*   Updated: 2023/05/24 14:39:56 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTAN_STACK_HPP
# define MUTAN_STACK_HPP
# include <stack>
# include <deque>

template <typename T, typename Container = std::deque<T> >
class	MutantStack : public std::stack<T, Container>
{
public:	
	
	typedef typename std::stack<T, Container>::container_type::iterator iterator;
	typedef typename std::stack<T, Container>::container_type::reverse_iterator reverse_iterator;
	
	MutantStack(void);
	MutantStack(MutantStack<T, Container> const & copy);
	~MutantStack(void);

	MutantStack<T, Container> & 		operator=(MutantStack<T, Container> const & m_stack);

	iterator				begin(void);
	iterator				end(void);
	reverse_iterator		rbegin(void);
	reverse_iterator		rend(void);

private:
	
};

# include "MutanStack.tpp"

#endif