/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 18:22:10 by mbocquel          #+#    #+#             */
/*   Updated: 2023/04/26 15:37:15 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include <iostream>
# include <string>

class	Zombie {

public:
	Zombie(std::string name);
	Zombie(void);
	~Zombie(void);
	void	announce(void);

private:
	std::string	_name;
};

#endif