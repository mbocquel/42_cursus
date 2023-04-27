/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 17:50:58 by mbocquel          #+#    #+#             */
/*   Updated: 2023/04/27 11:17:41 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAG_TRAP_HPP
# define FRAG_TRAP_HPP
# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
public:
	FragTrap(void);
	FragTrap(FragTrap const & copie);
	FragTrap(std::string name);
	FragTrap & operator=(FragTrap const & scav_trap);
	~FragTrap();
	void	highFivesGuys(void);
	
private:

};

#endif
