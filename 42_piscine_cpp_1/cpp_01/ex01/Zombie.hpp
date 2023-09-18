/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 18:22:10 by mbocquel          #+#    #+#             */
/*   Updated: 2023/04/21 19:03:39 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include <iostream>
# include <string>

class	Zombie {

public:
	Zombie(void);
	~Zombie(void);
	void	set_zombie_name(std::string name);
	void	announce(void);

private:
	std::string	_name;
};

#endif