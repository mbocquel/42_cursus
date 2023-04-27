/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 14:16:29 by mbocquel          #+#    #+#             */
/*   Updated: 2023/04/27 15:59:14 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_ANIMAL_HPP
# define WRONG_ANIMAL_HPP
# include <iostream>
# include <string>

class	WrongAnimal
{
public:
	WrongAnimal(void);
	WrongAnimal(WrongAnimal const & copie);
	WrongAnimal(std::string type);
	~WrongAnimal(void);

	WrongAnimal & operator=(WrongAnimal const & animal);
	
	void			makeSound(void) const;
	std::string		get_type(void) const;

protected:
	std::string _type;
	
};

#endif