/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 10:29:16 by mbocquel          #+#    #+#             */
/*   Updated: 2023/04/27 11:17:45 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAV_TRAP_HPP
# define SCAV_TRAP_HPP
# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
public:
	ScavTrap(void);
	ScavTrap(ScavTrap const & copie);
	ScavTrap(std::string name);
	~ScavTrap();
	
	ScavTrap & operator=(ScavTrap const & scav_trap);
	
	void	attack(const std::string& target);
	void	guardGate(void);
	
private:

};

#endif
