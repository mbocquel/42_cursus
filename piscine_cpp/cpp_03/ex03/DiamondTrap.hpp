/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 18:09:24 by mbocquel          #+#    #+#             */
/*   Updated: 2023/04/27 12:26:22 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMOND_TRAP_HPP
# define DIAMOND_TRAP_HPP
# include "FragTrap.hpp"
# include "ScavTrap.hpp"
# include <string>

class DiamondTrap : public FragTrap, public ScavTrap
{
public:
	DiamondTrap(void);
	DiamondTrap(DiamondTrap const & copie);
	DiamondTrap(std::string name);
	~DiamondTrap(void);

	DiamondTrap & operator=(DiamondTrap const & diamond_trap);
	
	void		attack(const std::string& target);
	void		whoAmI(void) const;
	std::string	get_name(void) const;
	
private:
	std::string	_name;
};


#endif