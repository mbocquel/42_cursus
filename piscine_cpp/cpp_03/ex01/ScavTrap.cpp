/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 10:29:20 by mbocquel          #+#    #+#             */
/*   Updated: 2023/04/26 10:55:57 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
/*
	ScavTrap(void);
	ScavTrap(ScavTrap const & copie);
	ScavTrap & operator=(ScavTrap const & scav_trap);
	~ScavTrap();
	ScavTrap(std::string name);
	void	guardGate(void);

	Name, son nom, qui sera passé en paramètre d’un constructeur
• Hit points (100)
• Energy points (50)
• Attack damage (20)
*/
ScavTrap::ScavTrap(void) :
_hit_points(100), 
_energy_points(50),
_attack_damage(20)
{
}

ScavTrap::ScavTrap(void)
{
}

ScavTrap::~ScavTrap()
{
}