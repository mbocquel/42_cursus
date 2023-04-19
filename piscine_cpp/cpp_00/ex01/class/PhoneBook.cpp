/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 11:39:59 by mbocquel          #+#    #+#             */
/*   Updated: 2023/04/19 17:35:51 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	this->_index = 0;
	this->_nb_contact = 0;
	//std::cout << "PhoneBook constructor called" << std::endl;
}

PhoneBook::~PhoneBook(void)
{
	//std::cout << "PhoneBook destructor called" << std::endl;
}

void	PhoneBook::add_contact()
{
	this->_tab_contact[this->_index].set_contact();
	(this->_index)++;
	if (this->_index == 8)
		this->_index = 0;
	if (this->_nb_contact < 8)
		(this->_nb_contact)++;
	std::cout << std::endl;
}

void	PhoneBook::_print_info_contact(int index)
{
	if (index < 0 || index > this->_index)
	{
		std::cout << "	Invalid index";
		return ;
	}
	else
	{
		(this->_tab_contact)[index].display_contact();
	}
}

std::string trim_string(std::string str, std::basic_string<char>::size_type len)
{
	std::string trimed;

	if (str.length() < len)
	{
		while (str.length() <= 9)
			str += " ";
		return (str);
	}
	else
	{
		trimed = str.substr(0,len - 1);
		while (trimed.length() < 9)
			trimed += " ";
		trimed += ".";
		return (trimed);
	}	
}

void	PhoneBook::search(void)
{
	int			i;
	std::string	index_string;
	
	i = 0;
	std::cout << std::endl << "	|index     |first name|last name |nickname  |" << std::endl;
	while (i < this->_nb_contact)
	{
		std::cout << "	|" << i << "         |" 
			<< trim_string(this->_tab_contact[i].get_info("firstname"), 10) << "|" 
			<< trim_string(this->_tab_contact[i].get_info("lastname"), 10) << "|"
			<< trim_string(this->_tab_contact[i].get_info("nickname"), 10) << "|"
			<< std::endl;
		i++;
	}
	std::cout << std::endl << "	Enter the contact index: ";
	std::getline(std::cin, index_string);
	if (index_string.length() == 1 && index_string.at(0) >= '0' && index_string.at(0) <= '9' && index_string.at(0) - '0' < this->_nb_contact)
	{
		_print_info_contact(index_string.at(0) - '0');
		std::cout << std::endl;
	}
	else if (!std::cin.eof())
		std::cout << "	Invalid index" << std::endl << std::endl;
}

