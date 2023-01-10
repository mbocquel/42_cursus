/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 13:20:26 by mbocquel          #+#    #+#             */
/*   Updated: 2023/01/10 18:21:16 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* ***************************** TARGET *************************************
 	3 numbers --> less than 3 moves.
	5 numbers --> less than 12 moves.

	100 numbers :
		less than 700 moves		--> 5 points
		less than 900 moves		--> 4 points
		less than 1100 moves	--> 3 points
		less than 1300 moves 	--> 2 points
		less than 1500 moves 	--> 1 point

	500 numbers :
		less than 5500 moves	--> 5 points
		less than 7000 moves	--> 4 points
		less than 8500 moves	--> 3 points
		less than 10000 moves 	--> 2 points
		less than 11500 moves 	--> 1 point
   ********************************************************************** */

void	print_instruction(t_ps *ps, int *move)
{
	int		i;
	char	*inst;

	i = -1;
	inst = NULL;
	while (ps->inst && (ps->inst)[++i])
	{
		if ((ps->inst)[i + 1] && *((ps->inst)[i]) != 'p'
			&& ft_abs(ft_strncmp((ps->inst)[i], (ps->inst)[i + 1], 3)) == 1
			&& *((ps->inst)[i]) == *((ps->inst)[i + 1]))
		{
			if ((ps->inst)[i][0] == 's')
				inst = "ss";
			if ((ps->inst)[i][0] == 'r' && (ps->inst)[i][1] != 'r')
				inst = "rr";
			if ((ps->inst)[i][0] == 'r' && (ps->inst)[i][1] == 'r')
				inst = "rrr";
			i++;
		}
		if (inst && ft_printf("%s\n", inst))
			(*move)++;
		else if (!inst && ft_printf("%s\n", (ps->inst)[i]))
			(*move)++;
		inst = NULL;
	}
}

int	main(int argc, char **argv)
{
	t_ps	ps;
	int		size;
	int		move;

	if (argc == 1)
		ft_exit(&ps, ERROR_ARG);
	parsing(argc, argv, &ps);
	size = pile_size(ps.pile_a);
	move = 0;
	if (size < 3 && !(pile_is_sorted(ps.pile_a)))
		add_action(&ps, "sa");
	else if (size == 3)
		start_process_3(&ps);
	else if (size <= 5)
		start_process_5(&ps);
	else
		start_process_big(&ps);
	bring_top(&ps, 1, 'a');
	print_instruction(&ps, &move);
	return (ft_exit(&ps, EXIT_NORMAL));
}
