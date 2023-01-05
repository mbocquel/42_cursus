/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 13:20:26 by mbocquel          #+#    #+#             */
/*   Updated: 2023/01/05 23:49:31 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* idees 

Gestion de la fin et des erreurs. Ne pas me balader avec ce pointeur de erreur
mais plutot envoyer des codes erreurs a une fonction exit, qui gere bien les 
truc (libere ce qu'il faut et affiche ou non la sortie d'erreur.)
utiliser les operatons binaire pour trouver les bons char d'erreur

*/

#include "push_swap.h"

static unsigned int	ft_abs(int i)
{
	if (i == -2147483648)
		return (0);
	if (i < 0)
		return (-i);
	return (i);
}

void	print_instruction(t_ps *ps)
{
	int		i;
	char	*inst;

	i = -1;
	inst = NULL;
	while (ps->inst && (ps->inst)[++i])
	{
		if ((ps->inst)[i + 1] 
			&& ft_abs(ft_strncmp((ps->inst)[i],(ps->inst)[i + 1], 3)) == 1 
			&& (ps->inst)[i][0] == (ps->inst)[i + 1][0])
		{
			if ((ps->inst)[i][0] == 's')
				inst = "ss";
			if ((ps->inst)[i][0] == 'r' && (ps->inst)[i][1] != 'r')
				inst = "rr";
			if ((ps->inst)[i][0] == 'r' && (ps->inst)[i][1] == 'r')
				inst = "rrr";
			i++;
		}
		if (inst)
			ft_printf("%s\n", inst);
		else
			ft_printf("%s\n", (ps->inst)[i]);
		inst = NULL;
	}
}

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
