/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 15:24:57 by mbocquel          #+#    #+#             */
/*   Updated: 2023/04/28 16:51:27 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP
# include "Animal.hpp"
# include "Brain.hpp"


class	Dog : public Animal
{
public:
	Dog(void);
	Dog(Dog const & copie);
	~Dog(void);

	Dog & operator=(Dog const & dog);
	
	virtual void	makeSound(void) const;
	Brain 			*getBrain(void) const;
	void			set_new_idea(std::string new_idea);

private:
	Brain	*_my_brain;
};

#endif