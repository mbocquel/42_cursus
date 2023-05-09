/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 10:11:00 by mbocquel          #+#    #+#             */
/*   Updated: 2023/05/09 10:19:14 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP
# include "AForm.hpp"
# include <string>

class Intern
{
private:
	static bool	_verbose;
	
public:
	Intern(void);
	Intern(Intern const & copy);
	~Intern(void);
	
	Intern & operator=(Intern const & intern);

	AForm *makeForm(std::string request, std::string target);
};

#endif