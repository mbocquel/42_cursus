/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 15:24:57 by mbocquel          #+#    #+#             */
/*   Updated: 2023/04/27 15:52:38 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP
# include "Animal.hpp"


class	Dog : public Animal
{
public:
	Dog(void);
	Dog(Dog const & copie);
	~Dog(void);

	Dog & operator=(Dog const & dog);
	
	virtual void	makeSound(void) const;

private:

};

#endif