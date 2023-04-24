/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 13:31:06 by mbocquel          #+#    #+#             */
/*   Updated: 2023/04/24 14:12:00 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char **argv)
{
	Harl	mon_harl;

	if (argc != 2)
	{
		std::cout << "Wrong number of argument" << std::endl;
		return (1);
	}
	mon_harl.complain(argv[1]);
	return (0);
}