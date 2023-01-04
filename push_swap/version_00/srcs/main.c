/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 13:20:26 by mbocquel          #+#    #+#             */
/*   Updated: 2023/01/04 17:09:13 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* idees 

Gestion de la fin et des erreurs. Ne pas me balader avec ce pointeur de erreur
mais plutot envoyer des codes erreurs a une fonction exit, qui gere bien les 
truc (libere ce qu'il faut et affiche ou non la sortie d'erreur.)
utiliser les operatons binaire pour trouver les bons char d'erreur

*/

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_ps	ps;
	int		size;

	if (argc == 1)
		ft_exit(&ps, ERROR_ARG);
	parsing(argc, argv, &ps);
	size = pile_size(ps.pile_a);
	if (size <= 3)
		start_process_3(&ps);
	else if (size <= 5)
		start_process_5(&ps);
	else if (size <= 100)
		start_process_100(&ps);
	else
		start_process_big(&ps);
	return (ft_exit(&ps, 6));
}
