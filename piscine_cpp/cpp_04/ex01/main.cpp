/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 14:15:46 by mbocquel          #+#    #+#             */
/*   Updated: 2023/04/28 18:55:01 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

std::string	ft_itoa(int n);

int	main(void)
{
	Animal *animal_tab[10];

	// Creation de mes annimaux
	for (int i = 0; i < 5; i++)
		animal_tab[i] = new Dog();
	for (int i = 5; i < 10; i++)
		animal_tab[i] = new Cat();
	
	// Affectation des ideas 

	

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 100; j++)
			((Dog *)animal_tab[i])->set_new_idea("Idee de l'animal " + ft_itoa(i) 
				+ " (" + animal_tab[i]->getType() + ") numero " + ft_itoa(j));
	}
	for (int i = 5; i < 10; i++)
	{
		for (int j = 0; j < 100; j++)
			((Cat *)animal_tab[i])->set_new_idea("Idee de l'animal " + ft_itoa(i) 
				+ " (" + animal_tab[i]->getType() + ") numero " + ft_itoa(j));
	}
	
	//Voir les idees de tout le monde
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 100; j++)
			std::cout << ((Dog *)animal_tab[i])->getBrain()->get_idea(j) << std::endl;
	}
	for (int i = 5; i < 10; i++)
	{
		for (int j = 0; j < 100; j++)
			std::cout << ((Cat *)animal_tab[i])->getBrain()->get_idea(j) << std::endl;
	}
	
	// Test de la copie profonde 
	Dog my_dog;
	for (int j = 0; j < 100; j++)
		std::cout << "my_dog idea " << j << ": " << my_dog.getBrain()->get_idea(j) << std::endl;
		
	my_dog = *((Dog *)animal_tab[0]);
	std::cout << "	my_dog = *((Dog *)animal_tab[0]);" << std::endl;
	for (int j = 0; j < 100; j++)
		std::cout << "my_dog idea " << j << ": " << my_dog.getBrain()->get_idea(j) << std::endl;


	my_dog = *((Dog *)animal_tab[2]);
	std::cout << "	my_dog = *((Dog *)animal_tab[0]);" << std::endl;
	for (int j = 0; j < 100; j++)
		std::cout << "my_dog idea " << j << ": " << my_dog.getBrain()->get_idea(j) << std::endl;
	
	// Destruction de mes annimaux
	for (int i = 0; i < 10; i++)
		delete animal_tab[i];
	return (0);
}
