/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 15:24:57 by mbocquel          #+#    #+#             */
/*   Updated: 2023/05/02 11:36:31 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP
# include "AAnimal.hpp"
# include "Brain.hpp"


class	Dog : public AAnimal
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