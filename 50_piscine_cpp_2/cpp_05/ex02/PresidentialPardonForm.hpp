/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 17:49:02 by mbocquel          #+#    #+#             */
/*   Updated: 2023/05/09 16:18:58 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIAL_PARDON_FORM_HPP
# define PRESIDENTIAL_PARDON_FORM_HPP
# include "AForm.hpp"
# include <iostream>
# include <string>

class PresidentialPardonForm : public AForm
{
private:
	std::string	_target;
	static bool	_verbose;
	PresidentialPardonForm(void);
	
public:
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(PresidentialPardonForm const & copy);
	virtual ~PresidentialPardonForm(void);

	virtual PresidentialPardonForm & operator=(PresidentialPardonForm const & form);

	virtual void				execute(Bureaucrat const & executor) const;
	std::string					getTarget(void) const;
};

std::ostream & operator<<(std::ostream & o, PresidentialPardonForm const & form);

#endif