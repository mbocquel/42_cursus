/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 17:39:53 by mbocquel          #+#    #+#             */
/*   Updated: 2023/04/25 19:28:40 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

void	print_message(ClapTrap const & clap_trap)
{	
	std::cout << "	-" << clap_trap.get_name() << " has "
	<< clap_trap.get_energy_point() << " energy points left." << std::endl;
	std::cout << "	-" << clap_trap.get_name() << " has "
	<< clap_trap.get_hit_points() << " hit points left." << std::endl;
}

int	main(void)
{
	ClapTrap clap_trap_1("Max");
	ClapTrap clap_trap_2("Tom");
	ClapTrap clap_trap_3(clap_trap_1);

	std::cout << std::endl;
	std::cout << "clap_trap_1 name: " << clap_trap_1.get_name() << std::endl;
	std::cout << "clap_trap_2 name: " << clap_trap_2.get_name() << std::endl;
	std::cout << "clap_trap_3 name: " << clap_trap_3.get_name() << std::endl;
	std::cout << std::endl;

	print_message(clap_trap_1); // 10
	clap_trap_1.attack("Tom");
	print_message(clap_trap_1); // 9
	clap_trap_1.attack("Tom");
	print_message(clap_trap_1); // 8
	clap_trap_1.attack("Tom");
	print_message(clap_trap_1); // 7
	clap_trap_1.attack("Tom");
	print_message(clap_trap_1); // 6
	clap_trap_1.attack("Tom");
	print_message(clap_trap_1); // 5
	clap_trap_1.attack("Tom");
	print_message(clap_trap_1); // 4
	clap_trap_1.attack("Tom");
	print_message(clap_trap_1); // 3
	clap_trap_1.attack("Tom");
	print_message(clap_trap_1); // 2
	clap_trap_1.attack("Tom");
	print_message(clap_trap_1); // 1
	clap_trap_1.attack("Tom");
	print_message(clap_trap_1); // 0
	clap_trap_1.attack("Tom");
	print_message(clap_trap_1); // 0
	clap_trap_1.attack("Tom");
	print_message(clap_trap_1); // 0
	clap_trap_1.attack("Tom");

	// Copie de 3 -> retour des points d'energie.
	std::cout << std::endl;
	clap_trap_1 = clap_trap_3;
	print_message(clap_trap_1); 
	clap_trap_1.takeDamage(5);
	print_message(clap_trap_1); 
	clap_trap_1.takeDamage(5);
	print_message(clap_trap_1); 
	clap_trap_1.takeDamage(5);
	print_message(clap_trap_1); 
	std::cout << std::endl;
	
	clap_trap_1 = clap_trap_3;
	print_message(clap_trap_1); 
	clap_trap_1.takeDamage(5);
	print_message(clap_trap_1); 
	clap_trap_1.beRepaired(5);
	print_message(clap_trap_1); 
	
	std::cout << std::endl;
	return (0);
}