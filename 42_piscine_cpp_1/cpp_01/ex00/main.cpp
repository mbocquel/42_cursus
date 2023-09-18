/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 18:21:54 by mbocquel          #+#    #+#             */
/*   Updated: 2023/04/26 15:43:11 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void randomChump(std::string name);
Zombie* newZombie(std::string name);

int	main(void)
{
	Zombie	*z1;
	Zombie	*z2;

	std::cout << "	z1 = newZombie(\"jack\"):" << std::endl;
	z1 = newZombie("jack");
	std::cout << std::endl;
	
	std::cout << "	randomChump(\"jean\"):" << std::endl;
	randomChump("jean");
	std::cout << std::endl;
	
	std::cout << "	z2 = newZombie(\"paul\"):" << std::endl;
	z2 = newZombie("paul");
	std::cout << std::endl;
	
	std::cout << "	z1->announce():" << std::endl;
	z1->announce();
	std::cout << std::endl;
	
	std::cout << "	delete z1:" << std::endl;
	delete z1;
	std::cout << std::endl;
	
	std::cout << "	z2->announce():" << std::endl;
	z2->announce();
	std::cout << std::endl;
	
	std::cout << "	randomChump(\"tom\")" << std::endl;
	randomChump("tom");
	std::cout << std::endl;
	
	std::cout << "	delete z2:" << std::endl;
	delete z2;
	std::cout << std::endl;
	
	std::cout << "FIN DU TEST" << std::endl;
	return 0;
}