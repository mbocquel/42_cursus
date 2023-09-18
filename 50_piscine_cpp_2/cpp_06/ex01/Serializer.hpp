/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 10:54:11 by mbocquel          #+#    #+#             */
/*   Updated: 2023/05/15 11:06:19 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP
# include <iostream>
# include <string>
# include <stdint.h>

typedef struct s_Data {
	int			a;
	std::string	str;
}				Data;

class	Serializer
{
private:
	Serializer(void);
	Serializer(Serializer const & copy);

public:
	~Serializer(void);
	Serializer & operator=(Serializer const & serial);
	
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);
};

#endif