/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 14:16:29 by mbocquel          #+#    #+#             */
/*   Updated: 2023/05/02 13:16:48 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef A_ANIMAL_HPP
# define A_ANIMAL_HPP
# include <iostream>
# include <string>
# include "Brain.hpp" 

class	AAnimal
{
public:
	AAnimal(void);
	AAnimal(AAnimal const & copie);
	AAnimal(std::string type);
	virtual ~AAnimal(void);

	AAnimal & operator=(AAnimal const & animal);
	
	virtual void	makeSound(void) const = 0; //permet d'en faire une classe abstraite
	std::string		getType(void) const;

protected:
	std::string _type;
	
};

#endif