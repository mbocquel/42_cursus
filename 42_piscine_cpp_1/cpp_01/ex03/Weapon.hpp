/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 15:42:40 by mbocquel          #+#    #+#             */
/*   Updated: 2023/04/26 16:35:47 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP
# include <iostream>
# include <string>

class Weapon
{
private:
	std::string	_type;
	
public:
	Weapon(std::string weapon_type);
	Weapon(void);
	~Weapon();
	const std::string	&getType(void) const;
	void				setType(std::string type);
};

#endif