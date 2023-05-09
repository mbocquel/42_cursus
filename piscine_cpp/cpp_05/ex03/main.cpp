/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 10:45:47 by mbocquel          #+#    #+#             */
/*   Updated: 2023/05/09 10:48:30 by mbocquel         ###   ########.fr       */
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
	Intern	intern_0;
	Intern	intern_1(intern_0);
	Intern	intern_2;
	AForm	*form0;
	AForm	*form1;
	AForm	*form2;

	std::cout << "All intern are the same... " << std::endl;
	intern_2 = intern_0;
	//std::string	tab[3] = {"robotomy request", "presidential pardon", "shrubbery creation"};
	
	std::cout << "	Boss: Intern ! I want you to make a robot of Daneel Olivaw" << std::endl;
	form0 = intern_0.makeForm("robotomy request", "Daneel Olivaw");
	std::cout << "	Boss: Ok, let's have a look at what you made..." << std::endl;
	std::cout << *form0 << std::endl;
	delete form0;
	std::cout << std::endl;

	std::cout << "	Boss: Intern ! I want you to make a presidential pardon form for Alfred Dreyfus" << std::endl;
	form1 = intern_0.makeForm("presidential pardon", "Alfred Dreyfus");
	std::cout << "	Boss: Ok, let's have a look at what you made..." << std::endl;
	std::cout << *form1 << std::endl;
	delete form1;
	std::cout << std::endl;
	
	std::cout << "	Boss: Intern ! I want you to make a shrubbery creation form for the garden" << std::endl;
	form2 = intern_0.makeForm("shrubbery creationn", "Garden");
	std::cout << "	Boss: Ok, let's have a look at what you made..." << std::endl;
	std::cout << *form2 << std::endl;
	delete form2;
	std::cout << std::endl;
	
	return (0);
}
