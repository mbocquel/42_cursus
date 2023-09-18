/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 10:45:47 by mbocquel          #+#    #+#             */
/*   Updated: 2023/05/03 17:03:43 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	//Test avec un grade too low (> 150)
	try 
	{
		std::cout << "\e[32m	1. Bureaucrat mon_bureaucrat_0(\"Henry\", 160);\e[0m" << std::endl;
		Bureaucrat mon_bureaucrat_0("Henry", 160);
	}
	catch (std::exception &e)
	{
		std::cout << "\e[31mException: " << e.what() << "\e[0m" << std::endl;
	}
	//Test avec un grade too hight (< 1)
	try
	{
		std::cout << "\e[32m	2. Bureaucrat mon_bureaucrat_1(\"John\", 0);\e[0m" << std::endl;
		Bureaucrat mon_bureaucrat_1("John", 0);
	}
	catch (std::exception &e)
	{
		std::cerr << "\e[31mException: " << e.what() << "\e[0m" << std::endl;
	}
	//Test de decrement jusqu'a ce que son grade soit trop bas
	try 
	{
		std::cout << "\e[32m	3. Bureaucrat mon_bureaucrat_2(\"Dan\", 148);\e[0m" << std::endl;
		Bureaucrat mon_bureaucrat_2("Dan", 148);
		std::cout << mon_bureaucrat_2 << std::endl;

		std::cout << "\e[32m	4. mon_bureaucrat_2.decrement_grade();\e[0m" << std::endl;
		mon_bureaucrat_2.decrement_grade();
		std::cout << mon_bureaucrat_2 << std::endl;
		
		std::cout << "\e[32m	5. mon_bureaucrat_2.decrement_grade();\e[0m" << std::endl;
		mon_bureaucrat_2.decrement_grade();
		std::cout << mon_bureaucrat_2 << std::endl;

		std::cout << "\e[32m	6. mon_bureaucrat_2.increment_grade();\e[0m" << std::endl;
		mon_bureaucrat_2.increment_grade();
		std::cout << mon_bureaucrat_2 << std::endl;

		std::cout << "\e[32m	7. mon_bureaucrat_2.decrement_grade();\e[0m" << std::endl;
		mon_bureaucrat_2.decrement_grade();
		std::cout << mon_bureaucrat_2 << std::endl;
		
		std::cout << "\e[32m	8. mon_bureaucrat_2.decrement_grade();\e[0m" << std::endl;
		mon_bureaucrat_2.decrement_grade();
		//lignes suivantes jamais appelees car la fonction precedente a envoyee une execption
		std::cout << mon_bureaucrat_2 << std::endl;
		
	}
	catch (std::exception &e)
	{
		std::cerr << "\e[31mException: " << e.what() << "\e[0m" << std::endl;
	}
	//Test de increment jusqu'a ce que son grade soit trop haut
	try 
	{
		std::cout << "\e[32m	9. Bureaucrat mon_bureaucrat_3(\"Jason\", 2);\e[0m" << std::endl;
		Bureaucrat mon_bureaucrat_3("Jason", 2);
		std::cout << mon_bureaucrat_3 << std::endl;

		std::cout << "\e[32m	10. mon_bureaucrat_3.decrement_grade();\e[0m" << std::endl;
		mon_bureaucrat_3.increment_grade();
		std::cout << mon_bureaucrat_3 << std::endl;
		
		std::cout << "\e[32m	11. mon_bureaucrat_3.decrement_grade();\e[0m" << std::endl;
		mon_bureaucrat_3.decrement_grade();
		std::cout << mon_bureaucrat_3 << std::endl;

		std::cout << "\e[32m	12. mon_bureaucrat_3.increment_grade();\e[0m" << std::endl;
		mon_bureaucrat_3.increment_grade();
		std::cout << mon_bureaucrat_3 << std::endl;

		std::cout << "\e[32m	13. mon_bureaucrat_3.decrement_grade();\e[0m" << std::endl;
		mon_bureaucrat_3.increment_grade();
		//lignes suivantes jamais appelees car la fonction precedente a envoyee une execption
		std::cout << mon_bureaucrat_3 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "\e[31mException: " << e.what() << "\e[0m" << std::endl;
	}
	
	return (0);
}
