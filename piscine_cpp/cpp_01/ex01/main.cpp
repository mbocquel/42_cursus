/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 18:21:54 by mbocquel          #+#    #+#             */
/*   Updated: 2023/04/21 19:21:17 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name);

int	main(void)
{
	int		N = 100;
	Zombie *zombie_horde;

	zombie_horde = zombieHorde(N, "tom");
	if (zombie_horde == NULL)
		return (1);
	for (int i = 0; i < N; i++)
	{
		zombie_horde[i].announce();
	}
	delete [] zombie_horde;
	return (0);
}