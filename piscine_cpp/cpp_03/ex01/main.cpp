/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 17:39:53 by mbocquel          #+#    #+#             */
/*   Updated: 2023/04/26 17:49:09 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap scav_trap1("Tom");
	ScavTrap scav_trap2;
	ScavTrap scav_trap3(scav_trap1);
	ScavTrap scav_trap4("John");

	
	scav_trap2 = scav_trap1;
	scav_trap2.display_status();
	std::cout << std::endl;

	scav_trap1.guardGate();
	std::cout << std::endl;
	
	scav_trap4.attack("Tom");
	scav_trap1.takeDamage(scav_trap4.get_attack_damage());
	scav_trap4.display_status();
	scav_trap1.display_status();
	scav_trap1.beRepaired(5);
	scav_trap1.display_status();
	std::cout << std::endl;
	
	return (0);
}