/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 11:21:46 by mbocquel          #+#    #+#             */
/*   Updated: 2023/05/23 14:16:59 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP
# include <iostream>
# include <string>
# include <set>
# include <vector>
# include <list>
# include <deque>
# include <algorithm>
# include <iterator>

class	Span
{
public:
	Span(unsigned int N);	
	Span(Span const & copy);
	~Span(void);
	
	Span & operator=(Span const & span);
	
	void			addNumber(int num); 
	void			addNumber(std::set<int>::iterator begin_it, std::set<int>::iterator end_it);
	void			addNumber(std::vector<int>::iterator begin_it, std::vector<int>::iterator end_it);
	void			addNumber(std::list<int>::iterator begin_it, std::list<int>::iterator end_it);
	void			addNumber(std::deque<int>::iterator begin_it, std::deque<int>::iterator end_it);
	int				shortestSpan(void);
	int				longestSpan(void);
	void			printSet(std::ostream & o);
	void			printSpan(std::ostream & o);
	unsigned int	getSize(void);

	class TooManyNumbersException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
	class NotEnoughNumberException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
	
private:
	Span(void);
	unsigned int 	_max_size;
	std::set<int> 	_set;
	static bool		_verbose;
};

#endif