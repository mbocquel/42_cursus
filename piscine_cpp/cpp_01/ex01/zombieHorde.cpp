/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 18:23:23 by mbocquel          #+#    #+#             */
/*   Updated: 2023/04/21 19:10:57 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name)
{
	int	i = 0;

	if (N <= 0)
		return (NULL);
	Zombie* zombieHorde = new Zombie[N];
	while (i < N)
	{
		zombieHorde[i].set_zombie_name(name);
		i++;
	}
	return (zombieHorde);
}