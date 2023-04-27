/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 15:52:58 by mbocquel          #+#    #+#             */
/*   Updated: 2023/04/27 15:55:14 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP
# include "Animal.hpp"

class Cat : public Animal
{

public:
	Cat(void);
	Cat(Cat const & copie);
	~Cat(void);

	Cat & operator=(Cat const & cat);
	
	virtual void	makeSound(void) const;

private:

};

#endif