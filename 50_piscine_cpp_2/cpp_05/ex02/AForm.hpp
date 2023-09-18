/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:21:57 by mbocquel          #+#    #+#             */
/*   Updated: 2023/05/09 16:14:50 by mbocquel         ###   ########.fr       */
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

	std::string const	getName(void) const;
	bool				getSigned(void) const;
	int					getGrade_to_sign(void) const;
	int 				getGrade_to_execute(void) const;
	void				beSigned(Bureaucrat const & bur_to_sng);
	virtual void		execute(Bureaucrat const & executor) const = 0;
	void				check_executable(Bureaucrat const & executor) const;

	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
	class FormNotSigned : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
	class ExecutionFailed : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
};

std::ostream & operator<<(std::ostream & o, AForm const & form);


#endif