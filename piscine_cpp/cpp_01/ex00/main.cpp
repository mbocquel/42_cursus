/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 18:21:54 by mbocquel          #+#    #+#             */
/*   Updated: 2023/04/21 18:57:34 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void randomChump(std::string name);
Zombie* newZombie(std::string name);

int	main(void)
{
	Zombie	*z1;
	Zombie	*z2;

	z1 = newZombie("jack");
	randomChump("jean");
	z2 = newZombie("paul");
	z1->announce();
	delete z1;
	z2->announce();
	randomChump("tom");
	delete z2;
	return 0;
}