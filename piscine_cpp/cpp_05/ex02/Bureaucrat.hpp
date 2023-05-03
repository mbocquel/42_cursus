/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 10:46:19 by mbocquel          #+#    #+#             */
/*   Updated: 2023/05/03 17:34:27 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <string>
# include <iostream>
# include "Form.hpp"

class Form;

class Bureaucrat
{
private:
	std::string const 	_name;
	int					_grade;
	static bool			_verbose;
	Bureaucrat(void);
	
public:
	Bureaucrat(std::string name, int grade);
	Bureaucrat(Bureaucrat const & copy);
	~Bureaucrat(void);
		
	Bureaucrat & operator=(Bureaucrat const & bureaucrat);

	std::string const	getName(void) const;
	int					getGrade(void) const;
	void				increment_grade(void);
	void				decrement_grade(void);
	void				signForm(Form & form);

	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
};

std::ostream & operator<<(std::ostream & o, Bureaucrat const & bureaucrat);

#endif