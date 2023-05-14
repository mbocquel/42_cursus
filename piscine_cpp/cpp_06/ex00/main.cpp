/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 10:45:47 by mbocquel          #+#    #+#             */
/*   Updated: 2023/05/12 20:03:46 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Wrong number of arguments" << std::endl;
		return (1);
	}
	else
	{
		std::string	_str(argv[1]);	
		ScalarConverter::convert(_str);
		return (0);
	}
}

/*Vous devez premièrement détecter le type du littéral passé en paramètre, le convertir
de sa représentation sous forme de chaîne de caractères vers son véritable type, et ensuite
le convertir explicitement vers les trois autres types de données.*/

/*
Je converti avec strtod. je regarde ce qu'il reste dans la suite, si c'est juste un f, je sais que le type est un floatant. 
si il y a rien et dans la chaine de caractere on a aussi un . c'est un double. si on a pas de point c'est un entier. 

il faut aussi que je gere directement les pseudo truc qu'on me passe. 
*/

/*int	main(void)
{
	float	f, g;
	int		h;
	double d = std::atof("42.3");

	std::string _string("42.3f");

	g = 43.8f;
	f = static_cast<float>(d);
	h = static_cast<int>(d);
	std::cout << f << std::endl;
	std::cout << g << std::endl;
	std::cout << h << std::endl;
	std::cout << _string << std::endl;
	char *endptr;


	double doub = strtod("fertgfawdef nrfgtdr", &endptr);
	std::cout << "doub : " << doub << std::endl;
	std::cout << "endptr : " << endptr << std::endl;
	std::cout << isdigit(_string.c_str()[3]) << std::endl;
	return (0);
}
*/