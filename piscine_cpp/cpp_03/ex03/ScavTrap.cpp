/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 10:29:20 by mbocquel          #+#    #+#             */
/*   Updated: 2023/04/26 18:57:04 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

/* ************************************************************************** */
/*                     Constructeurs et destructeurs                          */
/* ************************************************************************** */

ScavTrap::ScavTrap(void) : ClapTrap::ClapTrap()
{
	this->ClapTrap::_hit_points = 100;
	this->ClapTrap::_energy_points = 50;
	this->ClapTrap::_attack_damage = 20;
	std::cout << "\e[32mScavTrap default constructor called\e[0m" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap::ClapTrap(name)
{
	this->ClapTrap::_hit_points = 100;
	this->ClapTrap::_energy_points = 50;
	this->ClapTrap::_attack_damage = 20;
	std::cout << "\e[32mScavTrap constructor called for "<< this->get_name() << "\e[0m" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const & copie) : ClapTrap::ClapTrap(copie.get_name())
{
	this->ClapTrap::_hit_points = copie.get_hit_points();
	this->ClapTrap::_energy_points = copie.get_energy_point();
	this->ClapTrap::_attack_damage = copie.get_attack_damage();
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
	this->ClapTrap::_name = scav_trap.get_name();
	this->ClapTrap::_hit_points = scav_trap.get_hit_points();
	this->ClapTrap::_energy_points = scav_trap.get_energy_point();
	this->ClapTrap::_attack_damage = scav_trap.get_attack_damage();
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