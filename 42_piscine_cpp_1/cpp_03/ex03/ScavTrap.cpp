/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 10:29:20 by mbocquel          #+#    #+#             */
/*   Updated: 2023/04/27 13:40:20 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

/* ************************************************************************** */
/*                     Constructeurs et destructeurs                          */
/* ************************************************************************** */

ScavTrap::ScavTrap(void) : ClapTrap::ClapTrap()
{
	this->_hit_points = 100;
	this->_energy_points = 50;
	this->_attack_damage = 20;
	std::cout << "\e[32mScavTrap default constructor called\e[0m" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap::ClapTrap(name)
{
	this->_hit_points = 100;
	this->_energy_points = 50;
	this->_attack_damage = 20;
	std::cout << "\e[32mScavTrap name constructor called for "<< this->get_name() << "\e[0m" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const & copie) : ClapTrap::ClapTrap(copie.get_name())
{
	*this = copie;
	std::cout << "\e[32mScavTrap copie constructor called\e[0m" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "\e[32mScavTrap destructor called for " << this->get_name() << "\e[0m" << std::endl; 
}

/* ************************************************************************** */
/*                     Surchage d'opperateur                                  */
/* ************************************************************************** */

ScavTrap & ScavTrap::operator=(ScavTrap const & scav_trap)
{
	this->_name = scav_trap.get_name();
	this->_hit_points = scav_trap.get_hit_points();
	this->_energy_points = scav_trap.get_energy_point();
	this->_attack_damage = scav_trap.get_attack_damage();
	std::cout << "\e[32mScavTrap assignation operator called\e[0m" << std::endl;
	return (*this);
}

/* ************************************************************************** */
/*                     Fonction membre                                        */
/* ************************************************************************** */

void	ScavTrap::guardGate(void)
{
	std::cout << "\e[32mScavTrap " << this->get_name() << " just entered his Gate kepper mode!\e[0m" << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	if (this->ClapTrap::_energy_points > 0 && this->ClapTrap::_hit_points > 0)
	{
		std::cout << "\e[32mScavTrap " << this->ClapTrap::_name << " attacks " 
		<< target << ", causing " << this->ClapTrap::_attack_damage 
		<< " points of damage!\e[0m" << std::endl;
		this->ClapTrap::_energy_points--;
	}
	else
	{
		std::cout << "\e[32mScavTrap " << this->ClapTrap::_name
		<< " doesn't have enouth points (energy or hit) to attack...\e[0m" << std::endl;
	}
}
