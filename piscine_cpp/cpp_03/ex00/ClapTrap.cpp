/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 17:39:40 by mbocquel          #+#    #+#             */
/*   Updated: 2023/04/27 12:22:00 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

/* ************************************************************************** */
/*                     Constructeurs et destructeurs                          */
/* ************************************************************************** */

ClapTrap::ClapTrap(void) : _hit_points(10), _energy_points(10), _attack_damage(0)
{
	std::cout << "\e[33mClapTrap default constructor called\e[0m" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const & copie)
{
	*this = copie;
	std::cout << "\e[33mClapTrap copie constructor called\e[0m" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hit_points(10), _energy_points(10),
_attack_damage(0)
{
	std::cout << "\e[33mClapTrap name constructor called for " << this->_name << "\e[0m" << std::endl;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "\e[33mClapTrap destructor called for " << this->_name << "\e[0m" << std::endl;
}

/* ************************************************************************** */
/*                     Surchage d'opperateur                                  */
/* ************************************************************************** */

ClapTrap & ClapTrap::operator=(ClapTrap const & clap_trap)
{
	this->_name = clap_trap.get_name();
	this->_hit_points = clap_trap.get_hit_points();
	this->_energy_points = clap_trap.get_energy_point();
	this->_attack_damage = clap_trap.get_attack_damage();
	std::cout << "\e[33mClapTrap assignation operator called\e[0m" << std::endl;
	return (*this);
}

/* ************************************************************************** */
/*                     Fonctions membres                                      */
/* ************************************************************************** */

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
		std::cout << "\e[33mClapTrap " << this->_name << " attacks " 
		<< target << ", causing " << this->_attack_damage 
		<< " points of damage!\e[0m" << std::endl;
		this->_energy_points--;
	}
	else
	{
		std::cout << "\e[33mClapTrap " << this->_name
		<< " doesn't have enouth points (energy or hit) to attack...\e[0m" << std::endl;
	}
}

void		ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hit_points == 0)
	{
		std::cout << "\e[33mClapTrap " << this->_name << " is already down and cannot recieve anymore damages.\e[0m" << std::endl;
		return ;
	}
	else if (this->_hit_points - amount < 0)
		this->_hit_points = 0;
	else
		this->_hit_points -= amount;
	std::cout << "\e[33mClapTrap " << this->_name << " got some damage and now have "
	<< this->_hit_points << " hit points left.\e[0m" << std::endl;
}

void		ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energy_points > 0 && this->_hit_points > 0)
	{
		std::cout << "\e[33mClapTrap " << this->_name << " repaired himself and gained " 
		<< amount << " hit points.\e[0m" << std::endl;
		this->_energy_points--;
		this->_hit_points += amount;
	}
	else
	{
		std::cout << "\e[33mClapTrap " << this->_name
		<< " doesn't have enouth points (energy or hit) to repair himself...\e[0m" << std::endl;
	}
}

void		ClapTrap::display_status(void) const
{
	std::cout << "\e[33m" << this->_name << " has :" << std::endl;
	std::cout << "	-" << this->_hit_points << " hit points left" << std::endl;
	std::cout << "	-" << this->_energy_points << " energy points left" << std::endl;
	std::cout << "	-" << this->_attack_damage << " attack damage\e[0m" << std::endl;
}
