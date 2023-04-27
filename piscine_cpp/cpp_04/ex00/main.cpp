/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 14:15:46 by mbocquel          #+#    #+#             */
/*   Updated: 2023/04/27 16:20:54 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

int	main(void)
{
	std::cout << "	const Animal* meta = new Animal();" << std::endl;
	const Animal* meta = new Animal();
	std::cout << std::endl << "	const Animal* j = new Dog();" << std::endl;
	const Animal* j = new Dog();
	std::cout << std::endl << "	const Animal* i = new Cat();" << std::endl;
	const Animal* i = new Cat();
	std::cout << std::endl << "	const WrongAnimal* wc = new WrongCat();" << std::endl;
	const WrongAnimal* wc = new WrongCat();
	std::cout << std::endl << "	const WrongCat* normal_wc = new WrongCat();" << std::endl;
	const WrongCat* normal_wc = new WrongCat();
	
	std::cout << "j->getType(): " << j->getType() << std::endl;
	std::cout << "i->getType(): " << i->getType() << std::endl;
	
	std::cout << std::endl << "	i->makeSound();" << std::endl;
	i->makeSound(); //will output the cat sound!
	std::cout << std::endl << "	j->makeSound();" << std::endl;
	j->makeSound();
	std::cout << std::endl << "	meta->makeSound();" << std::endl;
	meta->makeSound();
	std::cout << std::endl << "	wc->makeSound();" << std::endl;
	wc->makeSound();
	std::cout << std::endl << "	normal_wc->makeSound();" << std::endl;
	normal_wc->makeSound();

	std::cout << std::endl << "	delete meta;" << std::endl;
	delete meta;
	std::cout << std::endl << "	delete i;" << std::endl;
	delete i;
	std::cout << std::endl << "	delete j;" << std::endl;
	delete j;
	std::cout << std::endl << "	delete wc;" << std::endl;
	delete wc;
	std::cout << std::endl << "	delete normal_wc;" << std::endl;
	delete normal_wc;
	
	return (0);
}

