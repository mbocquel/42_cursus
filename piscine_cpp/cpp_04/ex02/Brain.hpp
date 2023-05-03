/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 17:14:32 by mbocquel          #+#    #+#             */
/*   Updated: 2023/04/28 16:21:10 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP
# include <iostream>
# include <string>

class	Brain
{
public:
	Brain(void);
	Brain(Brain const & copie);
	~Brain(void);

	Brain & operator=(Brain const & brain);

	std::string	get_idea(int i) const;
	int			get_idea_index(void) const;
	void		add_idea(std::string & new_idea);
	void		add_idea(std::string & new_idea, int index);

private:
	std::string _ideas[100];
	int			_idea_index;

};

#endif