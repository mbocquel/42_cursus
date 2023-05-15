/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 10:45:47 by mbocquel          #+#    #+#             */
/*   Updated: 2023/05/15 12:03:37 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Classes.hpp"
#include <stdlib.h> 
#include <iostream>

int	random(int i)
{
	return (rand() % i);
}

/*It randomly instanciates A, B or C and returns the instance as a Base pointer. 
Feel free to use anything you like for the random choice implementation.*/
Base * generate(void)
{
	Base *return_ptr;
	int i = random(3);

	switch (i)
	{
	case 0:
		return_ptr = new A;
		break;
	case 1:
		return_ptr = new B;
		break;
	default:
		return_ptr = new C;
		break;
	}
	return (return_ptr);	
}

/*It prints the actual type of the object pointed to by p: "A", "B" or "C".*/
void identify(Base* p)
{
	
}

/*It prints the actual type of the object pointed to by p: "A", "B" or "C". Using a pointer
inside this function is forbidden.*/
void identify(Base& p)
{

}

int	main(void)
{
	
	return (0);	
}
