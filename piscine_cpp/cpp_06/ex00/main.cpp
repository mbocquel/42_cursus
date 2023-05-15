/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 10:45:47 by mbocquel          #+#    #+#             */
/*   Updated: 2023/05/15 10:53:33 by mbocquel         ###   ########.fr       */
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