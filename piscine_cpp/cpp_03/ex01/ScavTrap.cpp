/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 10:29:20 by mbocquel          #+#    #+#             */
/*   Updated: 2023/04/26 13:55:48 by mbocquel         ###   ########.fr       */
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
ScavTrap::ScavTrap(void) : ClapTrap::ClapTrap()
{
	this->_hit_points = 100;
	this->_energy_points = 50;
	this->_attack_damage = 20;
	std::cout << "ScavTrap default constructor called" << std::endl;
	std::cout << "	Hit point : " << this->_hit_points << std::endl;
	std::cout << "	Energy points : " << this->_energy_points << std::endl;
	std::cout << "	Attack damage : " << this->_attack_damage << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap::ClapTrap(name)
{
	this->_hit_points = 100;
	this->_energy_points = 50;
	this->_attack_damage = 20;
	std::cout << "ScavTrap constructor called for "<< this->_name << std::endl;
	std::cout << "	Hit point : " << this->_hit_points << std::endl;
	std::cout << "	Energy points : " << this->_energy_points << std::endl;
	std::cout << "	Attack damage : " << this->_attack_damage << std::endl;
}


ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called" << std::endl; 
	ClapTrap::~ClapTrap();
}