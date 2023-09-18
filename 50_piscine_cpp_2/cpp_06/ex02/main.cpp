/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 10:45:47 by mbocquel          #+#    #+#             */
/*   Updated: 2023/05/15 15:03:49 by mbocquel         ###   ########.fr       */
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
		std::cout << "Je fais un A" << std::endl;
		break;
	case 1:
		return_ptr = new B;
		std::cout << "Je fais un B" << std::endl;
		break;
	default:
		return_ptr = new C;
		std::cout << "Je fais un C" << std::endl;
		break;
	}
	return (return_ptr);	
}

/*It prints the actual type of the object pointed to by p: "A", "B" or "C".*/
void identify(Base* p)
{
	A	*ptr_A = dynamic_cast<A *>(p);
	if (ptr_A == NULL)
	{
		B	*ptr_B = dynamic_cast<B *>(p);
		if (ptr_B == NULL)
		{
			C	*ptr_C = dynamic_cast<C *>(p);
			if (ptr_C == NULL)
				std::cerr << "Error, no type is matching" << std::endl;
			else
				std::cout << "C" << std::endl;
		}
		else
			std::cout << "B" << std::endl;
	}
	else
		std::cout << "A" << std::endl;
}

/*It prints the actual type of the object pointed to by p: "A", "B" or "C". Using a pointer
inside this function is forbidden.*/
void identify(Base& p)
{
	try
	{
		A & ref_A = dynamic_cast<A &>(p);
		(void)ref_A;
		std::cout << "A" << std::endl;
	}
	catch (std::exception &e)
	{
		try
		{
			B & ref_B = dynamic_cast<B &>(p);
			(void)ref_B;
			std::cout << "B" << std::endl;
		}
		catch (std::exception &e)
		{
			try
			{
				C & ref_C = dynamic_cast<C &>(p);
				(void)ref_C;
				std::cout << "C" << std::endl;
			}
			catch (std::exception &e)
			{
				std::cerr << "Error, no type is matching" << std::endl;
			}
		}
	}
}

int	main(void)
{
	std::cout << "p0: ";
	Base *p0 = generate();
	std::cout << "p1: ";
	Base *p1 = generate();
	std::cout << "p2: ";
	Base *p2 = generate();
	std::cout << "p3: ";
	Base *p3 = generate();
	std::cout << "p4: ";
	Base *p4 = generate();
	std::cout << "p5: ";
	Base *p5 = generate();
	std::cout << "p6: ";
	Base *p6 = generate();
	std::cout << "p7: ";
	Base *p7 = generate();
	std::cout << "p8: ";
	Base *p8 = generate();
	std::cout << "p9: ";
	Base *p9 = generate();
	Base p10;

	std::cout << std::endl;
	std::cout << "	Idenfication via la fonction pointeur : " << std::endl;
	std::cout << "p0: J'identifie un ";
	identify(p0);
	std::cout << "p1: J'identifie un ";
	identify(p1);
	std::cout << "p2: J'identifie un ";
	identify(p2);
	std::cout << "p3: J'identifie un ";
	identify(p3);
	std::cout << "p4: J'identifie un ";
	identify(p4);
	std::cout << "p5: J'identifie un ";
	identify(p5);
	std::cout << "p6: J'identifie un ";
	identify(p6);
	std::cout << "p7: J'identifie un ";
	identify(p7);
	std::cout << "p8: J'identifie un ";
	identify(p8);
	std::cout << "p9: J'identifie un ";
	identify(p9);

	std::cout << std::endl;
	std::cout << "Je cherche a identifier un truc qui n'est ni A, B ou C (via pointeur): " << std::endl;
	identify(&p10);

	std::cout << std::endl;
	std::cout << "	Idenfication via la fonction reference : " << std::endl;
	std::cout << "p0: J'identifie un ";
	identify(*p0);
	std::cout << "p1: J'identifie un ";
	identify(*p1);
	std::cout << "p2: J'identifie un ";
	identify(*p2);
	std::cout << "p3: J'identifie un ";
	identify(*p3);
	std::cout << "p4: J'identifie un ";
	identify(*p4);
	std::cout << "p5: J'identifie un ";
	identify(*p5);
	std::cout << "p6: J'identifie un ";
	identify(*p6);
	std::cout << "p7: J'identifie un ";
	identify(*p7);
	std::cout << "p8: J'identifie un ";
	identify(*p8);
	std::cout << "p9: J'identifie un ";
	identify(*p9);
	
	std::cout << std::endl;
	std::cout << "Je cherche a identifier un truc qui n'est ni A, B ou C (via reference): " << std::endl;
	identify(p10);

	delete p0;
	delete p1;
	delete p2;
	delete p3;
	delete p4;
	delete p5;
	delete p6;
	delete p7;
	delete p8;
	delete p9;
	return (0);	
}
