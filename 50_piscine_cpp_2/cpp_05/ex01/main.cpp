/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 10:45:47 by mbocquel          #+#    #+#             */
/*   Updated: 2023/05/09 16:11:58 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	// Grade to sign too high
	std::cout << "	Form form1(\"A28b\", 0, 20);" << std::endl;
	try
	{
		Form form1("A28b", 0, 20);
		std::cout << form1 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "\e[31mException: " <<e.what() << "\e[0m" << std::endl;
	}
	std::cout << std::endl;
	
	// Grade to execute too high
	std::cout << "	Form form1(\"A28b\", 15, 0);" << std::endl;
	try
	{
		Form form1("A28b", 15, 0);
		std::cout << form1 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "\e[31mException: " <<e.what() << "\e[0m" << std::endl;
	}
	std::cout << std::endl;

	// Grade to sign too low
	std::cout << "	Form form1(\"A28b\", 5, 154);" << std::endl;
	try
	{
		Form form1("A28b", 5, 154);
		std::cout << form1 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "\e[31mException: " <<e.what() << "\e[0m" << std::endl;
	}
	std::cout << std::endl;
	
	// Grade to execute too low
	std::cout << "	Form form1(\"A28b\", 15, 155);" << std::endl;
	try
	{
		Form form1("A28b", 15, 155);
		std::cout << form1 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "\e[31mException: " <<e.what() << "\e[0m" << std::endl;
	}
	std::cout << std::endl;
	
	// Test de signature
	try
	{
		Form form1("A28b", 10, 20);
		Form form2("A32", 8, 5);
		
		std::cout << form1 << std::endl << std::endl;

		Bureaucrat bur_1("John", 9);
		std::cout << bur_1 << std::endl << std::endl;
	
		bur_1.signForm(form1);
		std::cout << form1 << std::endl << std::endl;
		
		//Cas avec un bureaucrate pas assez haut place pour signer.
		bur_1.signForm(form2);
		std::cout << form2 << std::endl << std::endl;

		bur_1.increment_grade();
		std::cout << bur_1 << std::endl << std::endl;
	
		//Maintenant il est assez haut pour signer. 
		bur_1.signForm(form2);
		std::cout << form2 << std::endl << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "\e[31mException: " <<e.what() << "\e[0m" << std::endl;
	}
	return (0);
}
