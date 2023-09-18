/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 13:06:23 by mbocquel          #+#    #+#             */
/*   Updated: 2023/04/26 16:47:36 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void	Harl::_debug(void) const
{
	std::cout << "I love having extra bacon for my "
	<< "7XL-double-cheese-triple-pickle-special-ketchup burger. "
	<< "I really do !" << std::endl;
}

void	Harl::_info(void) const
{
	std::cout << "I cannot believe adding extra bacon costs more money. "
	<< "You didn't put enough bacon in my burger ! If you did, I wouldn't be"
	<< " asking for more !" << std::endl;
}

void	Harl::_warning(void) const
{
	std::cout << "I think I deserve to have some extra bacon for free. "
	<< "I've been coming for years whereas you started working here "
	<< "since last month." << std::endl;
}

void	Harl::_error(void) const
{
	std::cout << "This is unacceptable ! I want to speak to the manager now." 
	<< std::endl;
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
	harl_fnct_ptr 	tab_fnct[4] = {&Harl::_debug, &Harl::_info, &Harl::_warning, &Harl::_error};
	int				i = 0;

	while (i < 4)
	{
		if (level == complain_tab[i])
			return ((this->*tab_fnct[i])());
		i++;
	}
	std::cout << "I don't know how to complain sorry..." << std::endl;
}
