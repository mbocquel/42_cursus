/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 17:39:53 by mbocquel          #+#    #+#             */
/*   Updated: 2023/04/26 17:28:11 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

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

	clap_trap_1.display_status(); // 10
	clap_trap_1.attack("Tom");
	clap_trap_1.display_status(); // 9
	clap_trap_1.attack("Tom");
	clap_trap_1.display_status(); // 8
	clap_trap_1.attack("Tom");
	clap_trap_1.display_status(); // 7
	clap_trap_1.attack("Tom");
	clap_trap_1.display_status(); // 6
	clap_trap_1.attack("Tom");
	clap_trap_1.display_status(); // 5
	clap_trap_1.attack("Tom");
	clap_trap_1.display_status(); // 4
	clap_trap_1.attack("Tom");
	clap_trap_1.display_status(); // 3
	clap_trap_1.attack("Tom");
	clap_trap_1.display_status(); // 2
	clap_trap_1.attack("Tom");
	clap_trap_1.display_status(); // 1
	clap_trap_1.attack("Tom");
	clap_trap_1.display_status(); // 0
	clap_trap_1.attack("Tom");
	clap_trap_1.display_status(); // 0
	clap_trap_1.attack("Tom");
	clap_trap_1.display_status(); // 0
	clap_trap_1.attack("Tom");

	// Copie de 3 -> retour des points d'energie.
	std::cout << std::endl;
	clap_trap_1 = clap_trap_3;
	clap_trap_1.display_status();
	clap_trap_1.takeDamage(5);
	clap_trap_1.display_status();
	clap_trap_1.takeDamage(5);
	clap_trap_1.display_status();
	clap_trap_1.takeDamage(5);
	clap_trap_1.display_status();
	std::cout << std::endl;
	
	clap_trap_1 = clap_trap_3;
	clap_trap_1.display_status();
	clap_trap_1.takeDamage(5);
	clap_trap_1.display_status();
	clap_trap_1.beRepaired(5);
	clap_trap_1.display_status();
	
	std::cout << std::endl;
	return (0);
}