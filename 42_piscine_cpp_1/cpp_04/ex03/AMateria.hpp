/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 12:06:45 by mbocquel          #+#    #+#             */
/*   Updated: 2023/05/02 16:25:01 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef A_MATERIA_HPP
# define A_MATERIA_HPP
# include <iostream>
# include <string>
# include "ICharacter.hpp"

class ICharacter;

class AMateria
{
protected:
	std::string const _type;
	AMateria(void);

public:
	AMateria(std::string const & type);
	AMateria(AMateria const & copy);
	virtual ~AMateria(void);

	AMateria & operator=(AMateria const & amateria);

	std::string const & getType() const; //Returns the materia type
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
};

#endif