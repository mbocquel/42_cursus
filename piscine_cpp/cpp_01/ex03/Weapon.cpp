/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 15:42:38 by mbocquel          #+#    #+#             */
/*   Updated: 2023/04/22 16:23:55 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string weapon_type) : _type(weapon_type)
{
}

Weapon::~Weapon()
{
}

std::string &Weapon::getType(void)
{
	return ( this->_type);
}

void	Weapon::setType(std::string type)
{
	this->_type = type;
}
