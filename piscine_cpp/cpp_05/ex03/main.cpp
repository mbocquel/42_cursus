/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 10:45:47 by mbocquel          #+#    #+#             */
/*   Updated: 2023/05/09 16:48:28 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int	main(void)
{
	try
	{
		Intern		intern_0;
		Intern		intern_1(intern_0);
		Intern		intern_2;
		Bureaucrat	boss("Max", 2);
		AForm		*form0;
		AForm		*form1;
		AForm		*form2;
		AForm		*form3;

		std::cout << std::endl;
		std::cout << "All intern are the same... " << std::endl;
		intern_2 = intern_0;
		std::cout << std::endl;

		//RobotomyRequestForm
		std::cout << "Boss: Intern ! I want you to make a robot of Daneel Olivaw" << std::endl;
		form0 = intern_0.makeForm("robotomy request", "Daneel Olivaw");
		if (form0)
		{
			std::cout << "Boss: Ok, let's have a look at what you made..." << std::endl;
			std::cout << *form0 << std::endl;
			boss.signForm(*form0);
			std::cout << *form0 << std::endl;
			boss.executeForm(*form0);
			delete form0;
		}
		else
			std::cout << "Boss: you idiot, you should know what I want anyway!" << std::endl;
		std::cout << std::endl;

		//PresidentialPardonForm
		std::cout << "Boss: Intern ! I want you to make a presidential pardon form for Alfred Dreyfus" << std::endl;
		form1 = intern_0.makeForm("presidential pardon", "Alfred Dreyfus");
		if (form1)
		{
			std::cout << "Boss: Ok, let's have a look at what you made..." << std::endl;
			std::cout << *form1 << std::endl;
			boss.signForm(*form1);
			std::cout << *form1 << std::endl;
			boss.executeForm(*form1);
			delete form1;
		}
		else
			std::cout << "Boss: you idiot, you should know what I want anyway!" << std::endl;
		std::cout << std::endl;
		
		//ShrubberyCreationForm
		std::cout << "Boss: Intern ! I want you to make a shrubbery creation form for the garden" << std::endl;
		form2 = intern_0.makeForm("shrubbery creation", "Garden");
		if (form2)
		{
			std::cout << "Boss: Ok, let's have a look at what you made..." << std::endl;
			std::cout << *form2 << std::endl;
			boss.signForm(*form2);
			std::cout << *form2 << std::endl;
			boss.executeForm(*form2);
			delete form2;
		}
		else
			std::cout << "Boss: you idiot, you should know what I want anyway!" << std::endl;
		std::cout << std::endl;

		//Siomething else
		std::cout << "Boss: Intern ! I want you to make a ********** form for M. Bean" << std::endl;
		form3 = intern_0.makeForm("**********", "M. Bean");
		if (form3)
		{
			std::cout << "Boss: Ok, let's have a look at what you made..." << std::endl;
			std::cout << *form3 << std::endl;
			boss.signForm(*form3);
			std::cout << *form3 << std::endl;
			boss.executeForm(*form3);
			delete form3;
		}
		else
			std::cout << "Boss: you idiot, you should know what I want anyway!" << std::endl;
		std::cout << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
