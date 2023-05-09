/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 17:48:46 by mbocquel          #+#    #+#             */
/*   Updated: 2023/05/04 15:35:53 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERY_CREATION_FORM_HPP
# define SHRUBBERY_CREATION_FORM_HPP
# include "AForm.hpp"
# include <iostream>
# include <string>

class ShrubberyCreationForm : public AForm
{
private:
	std::string	_target;
	static bool	_verbose;
	ShrubberyCreationForm(void);
	
public:
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(ShrubberyCreationForm const & copy);
	virtual ~ShrubberyCreationForm(void);

	virtual ShrubberyCreationForm & operator=(ShrubberyCreationForm const & form);

	virtual void	execute(Bureaucrat const & executor) const;
	std::string		getTarget(void) const;

	class ShrubberyCreationFileFailed : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
};

std::ostream & operator<<(std::ostream & o, ShrubberyCreationForm const & form);
#endif

