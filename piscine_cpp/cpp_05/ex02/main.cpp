/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 10:45:47 by mbocquel          #+#    #+#             */
/*   Updated: 2023/05/04 17:19:52 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main(void)
{
	std::cout << "	Let's create things" << std::endl;
	PresidentialPardonForm form1("Alfred Dreyfus");
	RobotomyRequestForm form2("Isaac Assimov");
	ShrubberyCreationForm form3("Garden");
	RobotomyRequestForm form4("Daneel Olivaw");
	Bureaucrat bur1("Maxence, practicly prime minister,", 4);
	Bureaucrat bur2("Vincent, member of the PM office,", 10);
	Bureaucrat bur3("Damien, a middle manager,", 30);
	Bureaucrat bur4("Thomas, a middle gouverment worker,", 50);
	Bureaucrat bur5("Jean, a low employee,", 80);
	Bureaucrat bur6("Alexandre, basicaly nobody in the administration,", 140);
	Bureaucrat bur7("Adrien, just better than an intern,", 147);
	std::cout << std::endl;

	std::cout << "	Let's have a look at my forms" << std::endl;
	std::cout << form1 << std::endl;
	std::cout << form2 << std::endl;
	std::cout << form3 << std::endl;
	std::cout << std::endl;

	std::cout << "	Let's test of the ShrubberyCreationForm" << std::endl;
	bur7.signForm(form3);
	std::cout << form3 << std::endl;
	bur6.executeForm(form3);
	bur6.signForm(form3);
	std::cout << form3 << std::endl;
	bur6.executeForm(form3);
	bur5.executeForm(form3);
	std::cout << std::endl;
	
	std::cout << "	Let's test of the RobotomyRequestForm" << std::endl;
	bur5.signForm(form2);
	std::cout << form2 << std::endl;
	bur4.executeForm(form2);
	bur4.signForm(form2);
	std::cout << form2 << std::endl;
	bur4.executeForm(form2);
	bur3.executeForm(form2);
	bur3.signForm(form4);
	std::cout << form4 << std::endl;
	bur3.executeForm(form4);
	bur3.executeForm(form4);
	bur3.executeForm(form4);
	std::cout << std::endl;

	std::cout << "	Test of the PresidentialPardonForm" << std::endl;
	bur3.signForm(form1);
	std::cout << form1 << std::endl;
	bur2.executeForm(form1);
	std::cout << form1 << std::endl;
	bur2.signForm(form1);
	bur2.executeForm(form1);
	bur1.executeForm(form1);
	std::cout << std::endl;

	std::cout << "	Let's destroy everything" << std::endl;
	return (0);
}
