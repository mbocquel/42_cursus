/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 15:25:46 by mbocquel          #+#    #+#             */
/*   Updated: 2023/05/24 14:43:02 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list>
#include <stack>
#include <iostream>
#include "MutanStack.hpp"
#include <vector>

void	test_list_from_subject(void)
{
	std::cout << "\e[32mTEST USING A LIST - SUBJECT TEST\e[0m" << std::endl;
	std::list<int>	mlist;
	
	mlist.push_back(5);
	mlist.push_back(17);
	std::cout << "mlist.back() " << mlist.back() << std::endl;
	mlist.pop_back();
	std::cout << "mlist.size() " << mlist.size() << std::endl;
	mlist.push_back(3);
	mlist.push_back(5);
	mlist.push_back(737);
	mlist.push_back(0);
	std::list<int>::iterator it = mlist.begin();
	std::list<int>::iterator ite = mlist.end();
	++it;
	--it;
	
	std::cout << std::endl;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::cout << std::endl << std::endl;
}

void	test_mutant_default_from_subject(void)
{
	std::cout << "\e[32mTEST USING MY MUTANTSTACK WITH SUBJECT TEST\e[0m" << std::endl;
	MutantStack< int>	mstack;
	
	mstack.push(5);
	mstack.push(17);
	std::cout << "mstack.top(): " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "mstack.size(): " << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator ms_it = mstack.begin();
	MutantStack<int>::iterator ms_ite = mstack.end();
	++ms_it;
	--ms_it;
	
	std::cout << std::endl;
	while (ms_it != ms_ite)
	{
		std::cout << *ms_it << std::endl;
		++ms_it;
	}
	std::stack<int> s(mstack);
}

void	test_mutantstack_default(void)
{
	std::cout << "\e[32mTEST USING MY MUTANTSTACK DEFAULT CONTAINER\e[0m" << std::endl;
	MutantStack<int>	mstack;
	
	mstack.push(1);
	mstack.push(3);
	mstack.push(5);
	mstack.push(7);
	mstack.push(9);
	mstack.push(11);
	mstack.push(13);
	mstack.push(15);
	std::cout << "mstack.top(): " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "mstack.size(): " << mstack.size() << std::endl;
	std::cout << "mstack.top(): " << mstack.top() << std::endl;
	std::cout << std::endl;
	
	std::cout << "Test with iterator" << std::endl;
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	for(;it != ite; ++it)
	{
		std::cout << *it << " -> ";
		(*it)++;
		std::cout << *it << std::endl;
	}
	std::cout << std::endl;
	
	std::cout << "Test with reverse iterator" << std::endl;
	MutantStack<int>::reverse_iterator r_it = mstack.rbegin();
	MutantStack<int>::reverse_iterator r_ite = mstack.rend();
	for(;r_it != r_ite; ++r_it)
	{
		std::cout << *r_it << " -> ";
		(*r_it)--;
		std::cout << *r_it << std::endl;
	}
	std::cout << std::endl;
}

void	test_mutantstack_vector(void)
{
	std::cout << "\e[32mTEST USING MY MUTANTSTACK WITH VECTOR CONTAINER\e[0m" << std::endl;
	MutantStack<int, std::vector<int> >	mstack;
	
	mstack.push(1);
	mstack.push(3);
	mstack.push(5);
	mstack.push(7);
	mstack.push(9);
	mstack.push(11);
	mstack.push(13);
	mstack.push(15);
	std::cout << "mstack.top(): " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "mstack.size(): " << mstack.size() << std::endl;
	std::cout << "mstack.top(): " << mstack.top() << std::endl;
	std::cout << std::endl;
	
	std::cout << "Test with iterator" << std::endl;
	MutantStack<int, std::vector<int> >::iterator it = mstack.begin();
	MutantStack<int, std::vector<int> >::iterator ite = mstack.end();
	for(;it != ite; ++it)
	{
		std::cout << *it << " -> ";
		(*it)++;
		std::cout << *it << std::endl;
	}
	std::cout << std::endl;
	
	std::cout << "Test with reverse iterator" << std::endl;
	MutantStack<int, std::vector<int> >::reverse_iterator r_it = mstack.rbegin();
	MutantStack<int, std::vector<int> >::reverse_iterator r_ite = mstack.rend();
	for(;r_it != r_ite; ++r_it)
	{
		std::cout << *r_it << " -> ";
		(*r_it)--;
		std::cout << *r_it << std::endl;
	}
	std::cout << std::endl;
}

void	test_mutantstack_list(void)
{
	std::cout << "\e[32mTEST USING MY MUTANTSTACK WITH LIST CONTAINER\e[0m" << std::endl;
	MutantStack<int, std::list<int> >	mstack;
	
	mstack.push(1);
	mstack.push(3);
	mstack.push(5);
	mstack.push(7);
	mstack.push(9);
	mstack.push(11);
	mstack.push(13);
	mstack.push(15);
	std::cout << "mstack.top(): " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "mstack.size(): " << mstack.size() << std::endl;
	std::cout << "mstack.top(): " << mstack.top() << std::endl;
	std::cout << std::endl;
	
	std::cout << "Test with iterator" << std::endl;
	MutantStack<int, std::list<int> >::iterator it = mstack.begin();
	MutantStack<int, std::list<int> >::iterator ite = mstack.end();
	for(;it != ite; ++it)
	{
		std::cout << *it << " -> ";
		(*it)++;
		std::cout << *it << std::endl;
	}
	std::cout << std::endl;
	
	std::cout << "Test with reverse iterator" << std::endl;
	MutantStack<int, std::list<int> >::reverse_iterator r_it = mstack.rbegin();
	MutantStack<int, std::list<int> >::reverse_iterator r_ite = mstack.rend();
	for(;r_it != r_ite; ++r_it)
	{
		std::cout << *r_it << " -> ";
		(*r_it)--;
		std::cout << *r_it << std::endl;
	}
	std::cout << std::endl;
}

int main(void)
{
	test_list_from_subject();
	test_mutant_default_from_subject();
	test_mutantstack_default();
	test_mutantstack_vector();
	test_mutantstack_list();
	
	return (0);
}
