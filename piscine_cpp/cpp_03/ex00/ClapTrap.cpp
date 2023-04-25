/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 17:39:40 by mbocquel          #+#    #+#             */
/*   Updated: 2023/04/25 19:26:13 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) :
_hit_points(10),
_energy_points(10),
_attack_damage(0)
{
	std::cout << "Default constructor called for ClapTrap" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const & copie)
{
	*this = copie;
	std::cout << "Copie constructor called for ClapTrap" << std::endl;
}

ClapTrap::ClapTrap(std::string name) :
_name(name),
_hit_points(10),
_energy_points(10),
_attack_damage(0)
{
	std::cout << "Name constructor called for ClapTrap " << this->_name << std::endl;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "Destructor called for ClapTrap " << this->_name << std::endl;
}

std::string	ClapTrap::get_name(void) const
{
	return (this->_name);
}

unsigned int	ClapTrap::get_hit_points(void) const
{
	return (this->_hit_points);
}

unsigned int	ClapTrap::get_energy_point(void) const
{
	return (this->_energy_points);
}

unsigned int	ClapTrap::get_attack_damage(void) const
{
	return (this->_attack_damage);
}

void		ClapTrap::attack(const std::string& target)
{
	if (this->_energy_points > 0 && this->_hit_points > 0)
	{
		std::cout << "ClapTrap " << this->_name << " attacks " 
		<< target << ", causing " << this->_attack_damage 
		<< " points of damage!" << std::endl;
		this->_energy_points--;
	}
	else
	{
		std::cout << "ClapTrap " << this->_name
		<< " doesn't have enouth points (energy or hit) to attack..." << std::endl;
	}
}

void		ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hit_points == 0)
	{
		std::cout << "ClapTrap " << this->_name << " is already down and cannot recieve anymore damages." << std::endl;
		return ;
	}
	else if (this->_hit_points - amount < 0)
		this->_hit_points = 0;
	else
		this->_hit_points -= amount;
	std::cout << "ClapTrap " << this->_name << " got some damage and now have "
	<< this->_hit_points << " hit points left." << std::endl;
}

void		ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energy_points > 0 && this->_hit_points > 0)
	{
		std::cout << "ClapTrap " << this->_name << " repaired himself and gained " 
		<< amount << " hit points." << std::endl;
		this->_energy_points--;
		this->_hit_points += amount;
	}
	else
	{
		std::cout << "ClapTrap " << this->_name
		<< " doesn't have enouth points (energy or hit) to repair himself..." << std::endl;
	}
}

ClapTrap & ClapTrap::operator=(ClapTrap const & clap_trap)
{
	this->_name = clap_trap.get_name();
	this->_hit_points = clap_trap.get_hit_points();
	this->_energy_points = clap_trap.get_energy_point();
	this->_attack_damage = clap_trap.get_attack_damage();
	std::cout << "ClapTrap assignation operator called" << std::endl;
	return (*this);
}