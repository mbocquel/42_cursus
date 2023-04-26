/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 17:38:54 by mbocquel          #+#    #+#             */
/*   Updated: 2023/04/26 14:56:00 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAP_TRAP_HPP
# define CLAP_TRAP_HPP
# include <iostream>

class ClapTrap 
{
public:
	ClapTrap(void);
	ClapTrap(ClapTrap const & copie);
	ClapTrap(std::string name);
	~ClapTrap(void);

	ClapTrap & operator=(ClapTrap const & clap_trap);
	
	std::string		get_name(void) const;
	unsigned int	get_hit_points(void) const;
	unsigned int	get_energy_point(void) const;
	unsigned int	get_attack_damage(void) const;
	void		attack(const std::string& target);
	void		takeDamage(unsigned int amount);
	void		beRepaired(unsigned int amount);
	void		set_points(unsigned int	hit_points,
			unsigned int energy_points, unsigned int attack_damage);

private:
	std::string		_name;
	unsigned int	_hit_points;
	unsigned int 	_energy_points;
	unsigned int 	_attack_damage;

};

#endif