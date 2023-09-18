/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 15:52:58 by mbocquel          #+#    #+#             */
/*   Updated: 2023/04/27 15:55:14 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_CAT_HPP
# define WRONG_CAT_HPP
# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{

public:
	WrongCat(void);
	WrongCat(WrongCat const & copie);
	~WrongCat(void);

	WrongCat & operator=(WrongCat const &wrong_cat);
	
	void	makeSound(void) const;

private:

};

#endif