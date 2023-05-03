/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 14:15:46 by mbocquel          #+#    #+#             */
/*   Updated: 2023/05/02 17:13:27 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ICharacter.hpp"
#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

int	main(void)
{
	// Test des construction et destruction des Materias et Materia Source
	std::cout << "Test des construction et destruction des Materias et Materia Source" 
	<< std::endl << std::endl;
	IMateriaSource* src = new MateriaSource();
	
	AMateria *ice_1 = new Ice();
	AMateria *ice_2 = new Ice(*((Ice *)ice_1));
	AMateria *cure_1 = new Cure();
	AMateria *cure_2 = cure_1->clone();
	
	std::cout << "adresse de ice_1: "<< ice_1 << std::endl;
	std::cout << "adresse de ice_2: "<< ice_2 << std::endl;
	std::cout << "adresse de cure_1: "<< cure_1 << std::endl;
	std::cout << "adresse de cure_2: "<< cure_2 << std::endl;
	
	src->learnMateria(ice_1);
	src->learnMateria(cure_1);

	AMateria *ice_3 = src->createMateria("ice");
	std::cout << "adresse de ice_3: "<< ice_3 << std::endl;
	std::cout << "type de ice_3: "<< ice_3->getType() << std::endl;

	AMateria *cure_3 = src->createMateria("cure");
	std::cout << "adresse de cure_2: "<< cure_2 << std::endl;
	std::cout << "type de cure_2: "<< cure_2->getType() << std::endl;

	AMateria *unknowed_materia = src->createMateria("something else");
	std::cout << "adresse de unknowed_materia: "<< unknowed_materia << std::endl;

	//delete src; // supprime ice_1 et cure_1 lors de sa destruction
	delete ice_2;
	delete ice_3;
	delete cure_2;
	delete cure_3;
	
	// Test de la partie Character
	std::cout << std::endl << std::endl;
	std::cout << "Test de la partie Character" << std::endl << std::endl;
	Character character_1("Maxence");
	Character character_2("Sebastien");
	Character character_3;
	
	character_1.equip(src->createMateria("ice"));
	character_1.equip(src->createMateria("cure"));

	character_1.use(0, character_2);
	character_1.use(1, character_2);
	character_1.use(2, character_2);
	
	std::cout << "		character_3 = character_1; --> Test de la copie profonde" << std::endl;
	character_3 = character_1;
	character_3.use(0, character_2);
	character_3.use(1, character_2);
	character_3.use(2, character_2);
	
	std::cout << "		character_3 = character_2; -->ca va supprimer tous les equip" << std::endl;
	character_3 = character_2;
	character_3.use(0, character_2);
	character_3.use(1, character_2);
	character_3.use(2, character_2);
	
	
	AMateria *follen_materia;
	std::cout << "		Maxence (character 1) fait tomber son ice (possition 1)" << std::endl;
	follen_materia = character_1.getAMateria(0);
	if (follen_materia)
		character_1.unequip(0);
	
	std::cout << "		Sebastien rammasse l'ice tombe et la prend" << std::endl;
	character_2.equip(follen_materia);
	character_2.use(0, character_1);
	character_2.use(1, character_1);

	std::cout << "		Test de la creation par recopie" << std::endl;
	Character character_4(character_1);
	character_4.use(0, character_2);
	character_4.use(1, character_2);
	character_4.use(2, character_2);
	character_4.use(3, character_2);
	
	delete src;
	return (0);
}

// Main du sujet
/*int	main(void)
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	
	ICharacter* me = new Character("me");
	
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	
	ICharacter* bob = new Character("bob");
	
	me->use(0, *bob);
	me->use(1, *bob);
	
	delete bob;
	delete me;
	delete src;
	
	return (0);
}
*/