/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 13:12:07 by mbocquel          #+#    #+#             */
/*   Updated: 2023/05/16 14:27:03 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP
#include <stdlib.h>

template<typename T>
class Array
{
private:
	T				*_array;
	unsigned int	_size;
	
public:
	Array(void);
	Array(Array<T> const & copy);
	Array(unsigned int n);
	~Array(void);

	Array<T> & 		operator=(Array<T> const & arr);
	T & 			operator[](unsigned int n) const;
	unsigned int	size(void) const;

	class InvalidIndex : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
};

# include "Array.tpp"

#endif