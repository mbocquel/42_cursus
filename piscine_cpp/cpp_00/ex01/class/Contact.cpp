/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 11:45:23 by mbocquel          #+#    #+#             */
/*   Updated: 2023/04/19 17:35:46 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/Contact.hpp"

Contact::Contact()
{
	//std::cout << "	Contact constructor called" << std::endl;
}

Contact::~Contact()
{
	//std::cout << "	Contact destructor called" << std::endl;
}

void	Contact::set_contact(void)
{
	this->_firstname.clear();
	this->_lastname.clear();
	this->_nickname.clear();
	this->_phone.clear();
	this->_secret.clear();
	std::cout << std::endl;
	while(this->_firstname.length() == 0 && !std::cin.eof())
	{
		std::cout << "	First name: ";
		std::getline(std::cin, this->_firstname);
	}
	while(this->_lastname.length() == 0 && !std::cin.eof())
	{
		std::cout << "	Last name: ";
		std::getline(std::cin, this->_lastname);
	}
	while(this->_nickname.length() == 0 && !std::cin.eof())
	{
		std::cout << "	Nickname: ";
		std::getline(std::cin, this->_nickname);
	}
	while(this->_phone.length() == 0 && !std::cin.eof())
	{
		std::cout << "	Phone number: ";
		std::getline(std::cin, this->_phone);
	}
	while(this->_secret.length() == 0 && !std::cin.eof())
	{
		std::cout << "	Darkest secret: ";
		std::getline(std::cin, this->_secret);
	}
}

void	Contact::display_contact(void)
{
	std::cout << "	----------------------------------------------------" << std::endl;
	std::cout << "	First name: " << this->_firstname << std::endl;
	std::cout << "	Last name: " << this->_lastname << std::endl;
	std::cout << "	Nickname: " << this->_nickname << std::endl;
	std::cout << "	Phone number: " << this->_phone << std::endl;
	std::cout << "	Darkest secret: " << this->_secret << std::endl;
	std::cout << "	----------------------------------------------------" << std::endl;
}

std::string Contact::get_info(std::string info)
{
	if (info.compare("firstname") == 0)
		return (this->_firstname);
	if (info.compare("lastname") == 0)
		return (this->_lastname);
	if (info.compare("nickname") == 0)
		return (this->_nickname);
	return ("error");
}

