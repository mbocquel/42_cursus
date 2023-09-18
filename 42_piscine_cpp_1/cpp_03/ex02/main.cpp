/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 17:39:53 by mbocquel          #+#    #+#             */
/*   Updated: 2023/04/27 13:56:54 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void)
{
	std::cout << "	FragTrap frag_trap1(\"Tom\"); " << std::endl;
	FragTrap frag_trap1("Tom");
	
	std::cout << std::endl << "	FragTrap frag_trap2;" << std::endl;
	FragTrap frag_trap2;
	
	std::cout << std::endl << "	FragTrap frag_trap3(frag_trap1); " << std::endl;
	FragTrap frag_trap3(frag_trap1);
	
	std::cout << std::endl << "	FragTrap frag_trap4(\"John\"); " << std::endl;
	FragTrap frag_trap4("John");

	std::cout << std::endl << "	frag_trap2 = frag_trap1; " << std::endl;
	frag_trap2 = frag_trap1;
	
	std::cout << std::endl << "	frag_trap2.display_status(); " << std::endl;
	frag_trap2.display_status();

	std::cout << std::endl << "	frag_trap1.highFivesGuys(); " << std::endl;
	frag_trap1.highFivesGuys();
	
	std::cout << std::endl << "	frag_trap4.attack(\"Tom\"); " << std::endl;
	frag_trap4.attack("Tom");
	
	std::cout << std::endl << "	frag_trap1.takeDamage(frag_trap4.get_attack_damage());" << std::endl;
	frag_trap1.takeDamage(frag_trap4.get_attack_damage());
	
	std::cout << std::endl << "	frag_trap4.display_status();" << std::endl;
	frag_trap4.display_status();
	
	std::cout << std::endl << "	frag_trap1.display_status();" << std::endl;
	frag_trap1.display_status();
	
	std::cout << std::endl << "	frag_trap1.beRepaired(5);" << std::endl;
	frag_trap1.beRepaired(5);

	std::cout << std::endl << "	frag_trap1.display_status();" << std::endl;
	frag_trap1.display_status();
	
	std::cout << std::endl << "	frag_trap2 = frag_trap4;" << std::endl;
	frag_trap2 = frag_trap4;
	
	std::cout << std::endl << "	frag_trap2.display_status();" << std::endl;
	frag_trap2.display_status();
	
	std::cout << std::endl << "	END OF PROGRAM" << std::endl;
	return (0);
}