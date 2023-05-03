/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:21:57 by mbocquel          #+#    #+#             */
/*   Updated: 2023/05/03 18:54:25 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP
# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
	static	bool		_verbose;
	std::string const	_name;
	bool				_signed;
	int const			_grade_to_sign;
	int const			_grade_to_execute;
	AForm(void);

public:
	AForm(std::string const form_name, int const grade_to_sign, int const grade_to_execute);
	AForm(AForm const & copy);
	virtual ~AForm(void);

	virtual AForm & operator=(AForm const & form);

	virtual std::string const	getName(void) const;
	virtual bool				getSigned(void) const;
	virtual int					getGrade_to_sign(void) const;
	virtual int 				getGrade_to_execute(void) const;
	virtual void				beSigned(Bureaucrat const & bur_to_sng);
	virtual void				execute(Bureaucrat const & executor) const = 0;
	virtual void				check_executable(Bureaucrat const & executor);
	
	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
};

std::ostream & operator<<(std::ostream & o, AForm const & form);


#endif