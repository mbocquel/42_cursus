/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 17:48:57 by mbocquel          #+#    #+#             */
/*   Updated: 2023/05/04 17:15:11 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMY_REQUEST_FORM_HPP
# define ROBOTOMY_REQUEST_FORM_HPP
# include "AForm.hpp"
# include <iostream>
# include <string>

class RobotomyRequestForm : public AForm
{
private:
	std::string				_target;
	static bool				_verbose;
	static unsigned char	_count;
	RobotomyRequestForm(void);
	
public:
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(RobotomyRequestForm const & copy);
	virtual ~RobotomyRequestForm(void);

	virtual RobotomyRequestForm & operator=(RobotomyRequestForm const & form);

	virtual void				execute(Bureaucrat const & executor) const;
	std::string					getTarget(void) const;
};

std::ostream & operator<<(std::ostream & o, RobotomyRequestForm const & form);


#endif