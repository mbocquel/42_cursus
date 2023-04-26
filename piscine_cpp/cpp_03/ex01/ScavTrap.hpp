/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 10:29:16 by mbocquel          #+#    #+#             */
/*   Updated: 2023/04/26 13:53:49 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
public:
	ScavTrap(void);
//	ScavTrap(ScavTrap const & copie);
	ScavTrap(std::string name);
//	ScavTrap & operator=(ScavTrap const & scav_trap);
	~ScavTrap();
//	void	guardGate(void);
};