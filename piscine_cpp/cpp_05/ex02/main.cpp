/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 10:45:47 by mbocquel          #+#    #+#             */
/*   Updated: 2023/05/03 17:46:52 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	Form form1("A28b", 10, 20);
	Form form2("A32", 8, 5);

	std::cout << form1 << std::endl << std::endl;

	Bureaucrat bur_1("John", 9);
	std::cout << bur_1 << std::endl << std::endl;
	
	bur_1.signForm(form1);
	std::cout << form1 << std::endl << std::endl;
	
	//cas avec un bureaucrate pas assez haut place pour signer.
	bur_1.signForm(form2);
	std::cout << form2 << std::endl << std::endl;

	bur_1.increment_grade();
	std::cout << bur_1 << std::endl << std::endl;
	
	//Maintenant il est assez haut pour signer. 
	bur_1.signForm(form2);
	std::cout << form2 << std::endl << std::endl;

	return (0);
}
