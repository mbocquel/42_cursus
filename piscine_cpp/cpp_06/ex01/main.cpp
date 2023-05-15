/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 10:45:47 by mbocquel          #+#    #+#             */
/*   Updated: 2023/05/15 11:43:33 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int	main(void)
{
	uintptr_t	temp;
	Data		data_original;
	Data 		*result_deserialize;

	data_original.a = 545;
	data_original.str = "Bonjour";

	std::cout << "&data_original : " << &data_original << std::endl;
	std::cout << "data_original.a : " << data_original.a << std::endl;
	std::cout << "data_original.str : " << data_original.str << std::endl << std::endl;

	temp = Serializer::serialize(&data_original);
	std::cout << "&temp : " << &temp << std::endl;
	std::cout << "temp : " << temp << std::endl << std::endl;

	result_deserialize = Serializer::deserialize(temp);
	std::cout << "result_deserialize : " << result_deserialize << std::endl;
	std::cout << "result_deserialize->a : " << result_deserialize->a << std::endl;
	std::cout << "result_deserialize->str : " << result_deserialize->str << std::endl;
	return (0);	
}

