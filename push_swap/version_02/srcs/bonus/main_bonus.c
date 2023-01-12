/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 19:04:09 by mbocquel          #+#    #+#             */
/*   Updated: 2023/01/11 18:21:37 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_instruction(char *inst)
{
	if (ft_strncmp(inst, "pa\n", ft_strlen(inst)) == 0)
		return (1);
	if (ft_strncmp(inst, "pb\n", ft_strlen(inst)) == 0)
		return (1);
	if (ft_strncmp(inst, "sa\n", ft_strlen(inst)) == 0)
		return (1);
	if (ft_strncmp(inst, "sb\n", ft_strlen(inst)) == 0)
		return (1);
	if (ft_strncmp(inst, "ra\n", ft_strlen(inst)) == 0)
		return (1);
	if (ft_strncmp(inst, "rb\n", ft_strlen(inst)) == 0)
		return (1);
	if (ft_strncmp(inst, "rra\n", ft_strlen(inst)) == 0)
		return (1);
	if (ft_strncmp(inst, "rrb\n", ft_strlen(inst)) == 0)
		return (1);
	if (ft_strncmp(inst, "rr\n", ft_strlen(inst)) == 0)
		return (1);
	if (ft_strncmp(inst, "rrr\n", ft_strlen(inst)) == 0)
		return (1);
	if (ft_strncmp(inst, "ss\n", ft_strlen(inst)) == 0)
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_ps	ps;
	char	*inst;

	if (argc == 1)
		return (0);
	parsing(argc, argv, &ps);
	inst = get_next_line(0);
	while (inst)
	{
		if (check_instruction(inst))
			add_action(&ps, inst);
		else
		{
			free(inst);
			ft_exit(&ps, ERROR_ACTION);
		}
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
