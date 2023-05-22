/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 11:13:47 by mbocquel          #+#    #+#             */
/*   Updated: 2023/05/22 11:51:22 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP
# include <algorithm>
# include <stdexcept>

template<typename T>

typename T::const_reference easyfind(const T & container, const int to_find)
{
	typename T::const_iterator it;

	it = find(container.begin(), container.end(), to_find);
	
	if (it == container.end())
		throw std::runtime_error("Error: value not found");
	return (*it);	
}

#endif