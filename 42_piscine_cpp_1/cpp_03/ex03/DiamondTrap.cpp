/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 18:09:27 by mbocquel          #+#    #+#             */
/*   Updated: 2023/04/27 12:38:56 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

/* ************************************************************************** */
/*                     Constructeurs et destructeurs                          */
/* ************************************************************************** */

DiamondTrap::DiamondTrap(void)
{
	this->ClapTrap::_name = "_clap_name";
	this->_hit_points = this->FragTrap::get_hit_points();
	this->_energy_points = this->ScavTrap::get_energy_point();
	this->_attack_damage = this->FragTrap::get_attack_damage();
	std::cout << "\e[34mDiamondTrap default constructor called\e[0m" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap::ClapTrap(name + "_clap_name")
{
	this->_name = name;
	this->_hit_points = this->FragTrap::get_hit_points();
	this->_energy_points = this->ScavTrap::get_energy_point();
	this->_attack_damage = this->FragTrap::get_attack_damage();
	std::cout << "\e[34mDiamondTrap name constructor called for "<< this->_name <<"\e[0m" << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const & copie)
{
	*this = copie;
	std::cout << "\e[34mDiamondTrap copie constructor called\e[0m" << std::endl;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "\e[34mDiamondTrap destructor called for " << this->_name << "\e[0m" << std::endl;
}

/* ************************************************************************** */
/*                     Surchage d'opperateur                                  */
/* ************************************************************************** */

DiamondTrap & DiamondTrap::operator=(DiamondTrap const & diamond_trap)
{
	this->_name = diamond_trap.get_name();
	this->ClapTrap::_name = diamond_trap.ClapTrap::get_name();
	this->_hit_points = diamond_trap.get_hit_points();
	this->_energy_points = diamond_trap.get_energy_point();
	this->_attack_damage = diamond_trap.get_attack_damage();
	std::cout << "\e[34mDiamondTrap assignation operator called\e[0m" << std::endl;
	return (*this);
}

/* ************************************************************************** */
/*                     Fonctions membres                                      */
/* ************************************************************************** */

void	DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI(void) const
{
	std::cout << "\e[34mMy DiamondTrap name is \"" << this->_name << "\" and my ClapTrap name is \""
	<< this->ClapTrap::_name << "\".\e[0m" << std::endl;
}

std::string	DiamondTrap::get_name(void) const
{
	return (this->_name);
}
