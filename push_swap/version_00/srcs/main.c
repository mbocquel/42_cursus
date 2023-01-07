/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 13:20:26 by mbocquel          #+#    #+#             */
/*   Updated: 2023/01/07 20:37:35 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_abs(int i)
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
		if (inst)
			ft_printf("%s\n", inst);
		else
			ft_printf("%s\n", (ps->inst)[i]);
		inst = NULL;
	}
	ft_printf("Instructions : %d\n", i);
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
	print_instruction(&ps);
	print_piles(&ps);
	return (ft_exit(&ps, 6));
}
