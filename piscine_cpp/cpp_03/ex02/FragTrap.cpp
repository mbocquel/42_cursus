/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 17:51:01 by mbocquel          #+#    #+#             */
/*   Updated: 2023/04/26 18:57:34 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

/* ************************************************************************** */
/*                     Constructeurs et destructeurs                          */
/* ************************************************************************** */

FragTrap::FragTrap(void) : ClapTrap::ClapTrap()
{
	this->ClapTrap::_hit_points = 100;
	this->ClapTrap::_energy_points = 100;
	this->ClapTrap::_attack_damage = 30;
	std::cout << "\e[31mFragTrap default constructor called\e[0m" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap::ClapTrap(name)
{
	this->ClapTrap::_hit_points = 100;
	this->ClapTrap::_energy_points = 100;
	this->ClapTrap::_attack_damage = 30;
	std::cout << "\e[31mFragTrap constructor called for "<< this->get_name() << "\e[0m" << std::endl;
}

FragTrap::FragTrap(FragTrap const & copie) : ClapTrap::ClapTrap(copie.get_name())
{
	this->ClapTrap::_hit_points = copie.get_hit_points();
	this->ClapTrap::_energy_points = copie.get_energy_point();
	this->ClapTrap::_attack_damage = copie.get_attack_damage();
	std::cout << "\e[31mFragTrap copie constructor called\e[0m" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "\e[31mFragTrap destructor called for " << this->get_name() << "\e[0m" << std::endl; 
}

/* ************************************************************************** */
/*                     Surchage d'opperateur                                  */
/* ************************************************************************** */

FragTrap & FragTrap::operator=(FragTrap const & frag_trap)
{
	this->ClapTrap::_name = frag_trap.get_name();
	this->ClapTrap::_hit_points = frag_trap.get_hit_points();
	this->ClapTrap::_energy_points = frag_trap.get_energy_point();
	this->ClapTrap::_attack_damage = frag_trap.get_attack_damage();
	std::cout << "\e[31mFragTrap assignation operator called\e[0m" << std::endl;
	return (*this);
}

/* ************************************************************************** */
/*                     Fonction membre                                        */
/* ************************************************************************** */

void	FragTrap::highFivesGuys(void)
{
	std::cout << "\e[31mFragTrap " << this->get_name() << " is asking to high fives !\e[0m" << std::endl;
}