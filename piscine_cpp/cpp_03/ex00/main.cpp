/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 17:39:53 by mbocquel          #+#    #+#             */
/*   Updated: 2023/04/27 14:11:38 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	std::cout << "	ClapTrap clap_trap_1(\"Max\");" << std::endl;
	ClapTrap clap_trap_1("Max");
	
	std::cout << std::endl << "	ClapTrap clap_trap_2(\"Tom\");" << std::endl;
	ClapTrap clap_trap_2("Tom");

	std::cout << std::endl << "	ClapTrap clap_trap_3(clap_trap_1);" << std::endl;
	ClapTrap clap_trap_3(clap_trap_1);

	std::cout << std::endl << "	clap_trap_1.get_name();" << clap_trap_1.get_name() << std::endl;
	std::cout << "	clap_trap_2.get_name();" << clap_trap_2.get_name() << std::endl;
	std::cout << "	clap_trap_3.get_name();" << clap_trap_3.get_name() << std::endl;
	
	std::cout << std::endl << "	clap_trap_1.display_status(); // 10" << std::endl;
	clap_trap_1.display_status(); // 10
	std::cout << std::endl << "	clap_trap_1.attack(\"Tom\");" << std::endl;
	clap_trap_1.attack("Tom");
	std::cout << std::endl << "	clap_trap_1.display_status(); // 9" << std::endl;
	clap_trap_1.display_status(); // 9
	std::cout << std::endl << "	clap_trap_1.attack(\"Tom\");" << std::endl;
	clap_trap_1.attack("Tom");
	std::cout << std::endl << "	clap_trap_1.display_status(); // 8" << std::endl;
	clap_trap_1.display_status(); // 8
	std::cout << std::endl << "	clap_trap_1.attack(\"Tom\");" << std::endl;
	clap_trap_1.attack("Tom");
	std::cout << std::endl << "	clap_trap_1.display_status(); // 7" << std::endl;
	clap_trap_1.display_status(); // 7
	std::cout << std::endl << "	clap_trap_1.attack(\"Tom\");" << std::endl;
	clap_trap_1.attack("Tom");
	std::cout << std::endl << "	clap_trap_1.display_status(); // 6" << std::endl;
	clap_trap_1.display_status(); // 6
	std::cout << std::endl << "	clap_trap_1.attack(\"Tom\");" << std::endl;
	clap_trap_1.attack("Tom");
	std::cout << std::endl << "	clap_trap_1.display_status(); // 5" << std::endl;
	clap_trap_1.display_status(); // 5
	std::cout << std::endl << "	clap_trap_1.attack(\"Tom\");" << std::endl;
	clap_trap_1.attack("Tom");
	std::cout << std::endl << "	clap_trap_1.display_status(); // 4" << std::endl;
	clap_trap_1.display_status(); // 4
	std::cout << std::endl << "	clap_trap_1.attack(\"Tom\");" << std::endl;
	clap_trap_1.attack("Tom");
	std::cout << std::endl << "	clap_trap_1.display_status(); // 3" << std::endl;
	clap_trap_1.display_status(); // 3
	std::cout << std::endl << "	clap_trap_1.attack(\"Tom\");" << std::endl;
	clap_trap_1.attack("Tom");
	std::cout << std::endl << "	clap_trap_1.display_status(); // 2" << std::endl;
	clap_trap_1.display_status(); // 2
	std::cout << std::endl << "	clap_trap_1.attack(\"Tom\");" << std::endl;
	clap_trap_1.attack("Tom");
	std::cout << std::endl << "	clap_trap_1.display_status(); // 1" << std::endl;
	clap_trap_1.display_status(); // 1
	std::cout << std::endl << "	clap_trap_1.attack(\"Tom\");" << std::endl;
	clap_trap_1.attack("Tom");
	std::cout << std::endl << "	clap_trap_1.display_status(); // 0" << std::endl;
	clap_trap_1.display_status(); // 0
	std::cout << std::endl << "	clap_trap_1.attack(\"Tom\");" << std::endl;
	clap_trap_1.attack("Tom");
	std::cout << std::endl << "	clap_trap_1.display_status(); // 0" << std::endl;
	clap_trap_1.display_status(); // 0

	std::cout << std::endl << "	clap_trap_1 = clap_trap_3; //Copie de 3 -> retour des points d'energie." << std::endl;
	clap_trap_1 = clap_trap_3;

	std::cout << std::endl << "	clap_trap_1.display_status();" << std::endl;
	clap_trap_1.display_status();
	
	std::cout << std::endl << "	clap_trap_1.takeDamage(5);" << std::endl;
	clap_trap_1.takeDamage(5);
	
	std::cout << std::endl << "	clap_trap_1.display_status();" << std::endl;
	clap_trap_1.display_status();

	std::cout << std::endl << "	clap_trap_1.takeDamage(5);" << std::endl;
	clap_trap_1.takeDamage(5);

	std::cout << std::endl << "	clap_trap_1.display_status();" << std::endl;
	clap_trap_1.display_status();

	std::cout << std::endl << "	clap_trap_1.takeDamage(5);" << std::endl;
	clap_trap_1.takeDamage(5);

	std::cout << std::endl << "	clap_trap_1.display_status();" << std::endl;
	clap_trap_1.display_status();
	
	std::cout << std::endl << "	END OF PROGRAM" << std::endl;
	return (0);
}