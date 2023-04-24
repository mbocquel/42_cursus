/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 13:06:23 by mbocquel          #+#    #+#             */
/*   Updated: 2023/04/24 14:10:32 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void	Harl::_debug(void) const
{
	std::cout << "[ DEBUG ]"<< std::endl
	<< "I love having extra bacon for my "
	<< "7XL-double-cheese-triple-pickle-special-ketchup burger. "
	<< "I really do !" 
	<< std::endl << std::endl;
}

void	Harl::_info(void) const
{
	std::cout << "[ INFO ]"<< std::endl
	<< "I cannot believe adding extra bacon costs more money. "
	<< "You didn't put enough bacon in my burger ! If you did, I wouldn't be"
	<< " asking for more !" 
	<< std::endl << std::endl;
}

void	Harl::_warning(void) const
{
	std::cout << "[ WARNING ]"<< std::endl
	<< "I think I deserve to have some extra bacon for free. " << std::endl
	<< "I've been coming for years whereas you started working here "
	<< "since last month." 
	<< std::endl << std::endl;
}

void	Harl::_error(void) const
{
	std::cout << "[ ERROR ]"<< std::endl
	<< "This is unacceptable ! I want to speak to the manager now." 
	<< std::endl << std::endl;
}

Harl::Harl()
{
}

Harl::~Harl()
{
}

void	Harl::complain(std::string level)
{
	std::string		complain_tab[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int				i = 0;

	while (i < 4)
	{
		if (level.compare(complain_tab[i]) == 0)
			break;
		i++;
	}

	switch (i)
	{
	case 0:
		this->_debug();
		this->_info();
		this->_warning();
		this->_error();
		break;
	
	case 1:
		this->_info();
		this->_warning();
		this->_error();
		break;
		
	case 2:
		this->_warning();
		this->_error();
		break;
		
	case 3:
		this->_error();
		break;

	default:
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		break;
	}
}
