/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 14:15:46 by mbocquel          #+#    #+#             */
/*   Updated: 2023/05/02 11:54:09 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

std::string	i_to_string(int n);

/* Main qui ne peux pas compiler car ma classe AAnimal 
est une classe abstraitre*/

/*int	main(void)
{
	AAnimal *animal = new AAnimal();
	return (0);
}*/

int	main(void)
{
	AAnimal *animal_tab[10];

	// Creation de mes annimaux
	for (int i = 0; i < 5; i++)
		animal_tab[i] = new Dog();
	for (int i = 5; i < 10; i++)
		animal_tab[i] = new Cat();
	
	// Affectation des ideas 
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 100; j++)
			((Dog *)animal_tab[i])->set_new_idea("Idee de l'animal " + i_to_string(i) 
				+ " (" + animal_tab[i]->getType() + ") numero " + i_to_string(j));
	}
	for (int i = 5; i < 10; i++)
	{
		for (int j = 0; j < 100; j++)
			((Cat *)animal_tab[i])->set_new_idea("Idee de l'animal " + i_to_string(i) 
				+ " (" + animal_tab[i]->getType() + ") numero " + i_to_string(j));
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
