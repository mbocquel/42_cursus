/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 13:31:06 by mbocquel          #+#    #+#             */
/*   Updated: 2023/04/24 13:43:09 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(void)
{
	Harl	mon_harl;

	std::cout << "Test de Harl avec DEBUG" << std::endl;
	mon_harl.complain("DEBUG");
	std::cout << std::endl << "Test de Harl avec INFO" << std::endl;
	mon_harl.complain("INFO");
	std::cout << std::endl << "Test de Harl avec WARNING" << std::endl;
	mon_harl.complain("WARNING");
	std::cout << std::endl << "Test de Harl avec ERROR" << std::endl;
	mon_harl.complain("ERROR");
	std::cout << std::endl << "Test de Harl avec autre chose" << std::endl;
	mon_harl.complain("test");
	return (0);
}