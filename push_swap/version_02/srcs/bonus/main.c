/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 19:04:09 by mbocquel          #+#    #+#             */
/*   Updated: 2023/01/10 19:34:25 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int argc, char **argv)
{
	t_ps	ps;
	char	*inst;

	if (argc == 1)
		ft_exit(&ps, ERROR_ARG);
	parsing(argc, argv, &ps);
	inst = get_next_line(0);
	while (inst)
	{
		add_action(&ps, inst);
		free(inst);
		inst = get_next_line(0);
	}
	free(inst);
	if (pile_is_sorted(ps.pile_a) && pile_size(ps.pile_b) == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	return (ft_exit(&ps, EXIT_NORMAL));
}
