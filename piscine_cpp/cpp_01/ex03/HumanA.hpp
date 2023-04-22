/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 15:42:29 by mbocquel          #+#    #+#             */
/*   Updated: 2023/04/22 16:31:30 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_A_HPP
# define HUMAN_A_HPP
# include "Weapon.hpp"
# include <iostream>
# include <string>


class HumanA
{
private:
	Weapon		&_weapon;
	std::string	_name;

public:
	HumanA(std::string name, Weapon &weapon);
	~HumanA();
	void	attack() const;
	void	setWeapon(Weapon &weapon);
};

#endif