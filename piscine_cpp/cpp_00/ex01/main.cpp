/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 14:02:13 by mbocquel          #+#    #+#             */
/*   Updated: 2023/04/19 17:36:57 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/Contact.hpp"
#include "header/PhoneBook.hpp"

int	main(void)
{
	PhoneBook phonebook;
	std::string instruction;

	while (1)
	{
		std::cout << "Please enter command (ADD, SEARCH or EXIT): ";
		std::getline(std::cin, instruction);
		if (std::cin.eof())
			return (1);
		if (instruction.compare("ADD") == 0)
			phonebook.add_contact();
		else if (instruction.compare("SEARCH") == 0)
			phonebook.search();
		else if (instruction.compare("EXIT") == 0)
			return (0) ;
		else
			std::cout << "Invalid command" << std::endl;
		if (std::cin.eof())
			return (1);
		std::cin.clear();
		std::cout.clear();
		instruction.clear();
	}
	return (0);
}