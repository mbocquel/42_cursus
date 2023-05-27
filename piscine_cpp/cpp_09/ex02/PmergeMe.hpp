/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 15:48:42 by mbocquel          #+#    #+#             */
/*   Updated: 2023/05/27 18:38:12 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef P_MERGE_ME_HPP
# define P_MERGE_ME_HPP
# include <iostream>
# include <string>
# include <vector>
# include <deque>
# include <cstdlib>
# include <utility>
	
class	PmergeMe
{
public:
	PmergeMe(void);
	PmergeMe(PmergeMe const & copy);
	~PmergeMe(void);

	PmergeMe & operator=(PmergeMe const & p_mergeme);

	void	add_vector(char **argv);
	void	add_deque(char **argv);
	void	sort_vector(void);
	void	sort_deque(void);
	void	view_deque(void);
	void	view_vector(void);

	class input_error : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};

private:
	std::vector<int>	_my_vector;
	std::deque<int>		_my_deque;
};

#endif