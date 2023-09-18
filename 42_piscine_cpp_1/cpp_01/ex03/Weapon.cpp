/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 15:42:38 by mbocquel          #+#    #+#             */
/*   Updated: 2023/04/26 16:36:05 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string weapon_type) : _type(weapon_type)
{
}

Weapon::Weapon(void)
{
}

Weapon::~Weapon()
{
}

const std::string	&Weapon::getType(void) const
{
	return ( this->_type);
}

void	Weapon::setType(std::string type)
{
	this->_type = type;
}
