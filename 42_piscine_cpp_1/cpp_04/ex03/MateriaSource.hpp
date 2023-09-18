/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 13:11:54 by mbocquel          #+#    #+#             */
/*   Updated: 2023/05/02 15:45:29 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIA_SOURCE_HPP
# define MATERIA_SOURCE_HPP
# include "IMateriaSource.hpp"

class	MateriaSource : public IMateriaSource
{
	private:
		AMateria*	_materia_tab[4];

	public:
		MateriaSource(void);
		MateriaSource(MateriaSource const & copy);
		~MateriaSource(void);

		MateriaSource & operator=(MateriaSource const & materia_source);

		virtual void		learnMateria(AMateria* amateria);
		virtual AMateria*	createMateria(std::string const & type);
		AMateria*			get_amateria(int idx) const;
};

#endif