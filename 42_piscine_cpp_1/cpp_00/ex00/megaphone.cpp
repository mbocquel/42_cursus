/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 10:20:28 by mbocquel          #+#    #+#             */
/*   Updated: 2023/04/19 11:31:32 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main(int argc, char **argv)
{
	int	i;
	
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		argv++;
		while (*argv)
		{
			i = 0;
			while ((*argv)[i])
			{
				std::cout << static_cast<char> (std::toupper((*argv)[i]));
				i++;
			}
			argv++;
		}
		std::cout << std::endl;
	}
	return (0);	
}
