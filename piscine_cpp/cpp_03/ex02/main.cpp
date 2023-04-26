/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 17:39:53 by mbocquel          #+#    #+#             */
/*   Updated: 2023/04/26 18:04:41 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void)
{
	FragTrap frag_trap1("Tom");
	FragTrap frag_trap2;
	FragTrap frag_trap3(frag_trap1);
	FragTrap frag_trap4("John");

	
	frag_trap2 = frag_trap1;
	frag_trap2.display_status();
	std::cout << std::endl;

	frag_trap1.highFivesGuys();
	std::cout << std::endl;
	
	frag_trap4.attack("Tom");
	frag_trap1.takeDamage(frag_trap4.get_attack_damage());
	frag_trap4.display_status();
	frag_trap1.display_status();
	frag_trap1.beRepaired(5);
	frag_trap1.display_status();
	std::cout << std::endl;

	frag_trap2 = frag_trap4;
	frag_trap2.display_status();
	std::cout << std::endl;
	
	return (0);
}