/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 15:42:22 by mbocquel          #+#    #+#             */
/*   Updated: 2023/04/22 16:39:23 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name)
{
	this->_weapon = NULL;
}

HumanB::~HumanB()
{
}

void	HumanB::attack() const
{
	if (this->_weapon != NULL)
	{
		std::cout << this->_name << " attacks with their " << this->_weapon->getType()
		<< std::endl;
	}	
}
void	HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
}