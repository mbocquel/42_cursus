/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 17:39:53 by mbocquel          #+#    #+#             */
/*   Updated: 2023/04/27 13:59:27 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	std::cout << "	ScavTrap scav_trap1(\"Tom\");" << std::endl;
	ScavTrap scav_trap1("Tom");

	std::cout << std::endl << "	ScavTrap scav_trap2;" << std::endl;
	ScavTrap scav_trap2;

	std::cout << std::endl << "	ScavTrap scav_trap3(scav_trap1);" << std::endl;
	ScavTrap scav_trap3(scav_trap1);

	std::cout << std::endl << "	ScavTrap scav_trap4(\"John\");" << std::endl;
	ScavTrap scav_trap4("John");

	std::cout << std::endl << "	scav_trap2 = scav_trap1;" << std::endl;
	scav_trap2 = scav_trap1;
	
	std::cout << std::endl << "	scav_trap2.display_status();" << std::endl;
	scav_trap2.display_status();
	
	std::cout << std::endl << "	scav_trap1.guardGate();" << std::endl;
	scav_trap1.guardGate();
	
	std::cout << std::endl << "	scav_trap4.attack(\"Tom\");" << std::endl;
	scav_trap4.attack("Tom");

	std::cout << std::endl << "	scav_trap1.takeDamage(scav_trap4.get_attack_damage());" << std::endl;
	scav_trap1.takeDamage(scav_trap4.get_attack_damage());

	std::cout << std::endl << "	scav_trap4.display_status();" << std::endl;
	scav_trap4.display_status();
	
	std::cout << std::endl << "	scav_trap1.display_status();" << std::endl;
	scav_trap1.display_status();

	std::cout << std::endl << "	scav_trap1.beRepaired(5);" << std::endl;
	scav_trap1.beRepaired(5);

	std::cout << std::endl << "	scav_trap1.display_status();" << std::endl;
	scav_trap1.display_status();

	std::cout << std::endl << "	END OF PROGRAM" << std::endl;
	return (0);
}