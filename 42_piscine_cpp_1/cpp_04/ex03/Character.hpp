/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 13:12:20 by mbocquel          #+#    #+#             */
/*   Updated: 2023/05/02 16:58:31 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP
# include "ICharacter.hpp"

class Character : public ICharacter
{
	private:
		AMateria	*_materia_tab[4];
		std::string	_name;

	public:
		Character(void);
		Character(std::string name);
		Character(Character const & copy);
		~Character(void);

		Character & operator=(Character const & character);
		
		virtual std::string const &	getName() const;
		virtual void				equip(AMateria* m);
		virtual void				unequip(int idx);
		virtual void				use(int idx, ICharacter& target);
		AMateria*					getAMateria(int idx) const;
		
};

#endif