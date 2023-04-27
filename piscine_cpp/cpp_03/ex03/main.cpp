/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 17:39:53 by mbocquel          #+#    #+#             */
/*   Updated: 2023/04/27 13:59:50 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main(void)
{
	std::cout << "	DiamondTrap diamond_trap1(\"Tom\");" << std::endl;
	DiamondTrap diamond_trap1("Tom");

	std::cout << std::endl << "	DiamondTrap diamond_trap2(\"John\");" << std::endl;
	DiamondTrap diamond_trap2("John");

	std::cout << std::endl << "	DiamondTrap diamond_trap3;" << std::endl;
	DiamondTrap diamond_trap3;
	
	std::cout << std::endl << "	DiamondTrap diamond_trap4(diamond_trap1);" << std::endl;
	DiamondTrap diamond_trap4(diamond_trap1);

	std::cout << std::endl << "	diamond_trap1.display_status();" << std::endl;
	diamond_trap1.display_status();
		
	std::cout << std::endl << "	diamond_trap1.whoAmI();" << std::endl;
	diamond_trap1.whoAmI();

	std::cout << std::endl << "	diamond_trap1.attack(\"John\");" << std::endl;
	diamond_trap1.attack("John");

	std::cout << std::endl << "	diamond_trap1.highFivesGuys();" << std::endl;
	diamond_trap1.highFivesGuys();

	std::cout << std::endl << "	diamond_trap1.guardGate();" << std::endl;
	diamond_trap1.guardGate();
	
	std::cout << std::endl << "	diamond_trap3 = diamond_trap2;" << std::endl;
	diamond_trap3 = diamond_trap2;

	std::cout << std::endl << "	diamond_trap3.whoAmI();" << std::endl;
	diamond_trap3.whoAmI();

	std::cout << std::endl << "	diamond_trap4.whoAmI();" << std::endl;
	diamond_trap4.whoAmI();
	
	std::cout << std::endl << "	END OF PROGRAM" << std::endl;
	
	return (0);
}