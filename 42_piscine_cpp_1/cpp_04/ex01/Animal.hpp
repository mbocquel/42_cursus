/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 14:16:29 by mbocquel          #+#    #+#             */
/*   Updated: 2023/05/02 11:17:04 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <iostream>
# include <string>
# include "Brain.hpp" 

class	Animal
{
public:
	Animal(void);
	Animal(Animal const & copie);
	Animal(std::string type);
	virtual ~Animal(void);

	Animal & operator=(Animal const & animal);
	
	virtual void	makeSound(void) const;
	std::string		getType(void) const;

protected:
	std::string _type;
	
};

#endif