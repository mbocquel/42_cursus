/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 15:48:42 by mbocquel          #+#    #+#             */
/*   Updated: 2023/05/29 15:03:06 by mbocquel         ###   ########.fr       */
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

	void	view_vector(void);
	void	sort_vector(char **argv, int len);
	void 	merge_sort_recursion_vector(std::vector< std::pair<int, int> > & vect_pair,
			int left, int right);
	void 	merge_sorted_arrays_vector(std::vector< std::pair<int, int> > & vect_pair,
			int left, int middle, int right);
	int		find_element_index_vector(int val);
	
	void	sort_deque(char **argv, int len);
	void	view_deque(void);
	void 	merge_sort_recursion_deque(std::deque< std::pair<int, int> > & deque_pair,
			int left, int right);
	void 	merge_sorted_arrays_deque(std::deque< std::pair<int, int> > & deque_pair,
			int left, int middle, int right);
	int		find_element_index_deque(int val);
	
	int		ft_atoi(char *str);

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