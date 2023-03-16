/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_big_to_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 11:10:15 by mbocquel          #+#    #+#             */
/*   Updated: 2023/03/08 16:02:58 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	start_process_big(t_ps *ps)
{
	int	med;
	int	i;
	int	size;

	i = -1;
	size = pile_size(ps->pile_a);
	med = pile_size(ps->pile_a) / 2;
	while (++i < size)
	{
		if (ps->pile_a->pos < med && ps->pile_a->pos < med / 2)
		{
			add_action(ps, "pb");
			add_action(ps, "rb");
		}
		else if (ps->pile_a->pos < med)
			add_action(ps, "pb");
		else
			add_action(ps, "ra");
	}
	process_big_part_2(med, ps);
}

void	process_big_part_2(int med, t_ps *ps)
{
	int	i;
	int	size;

	while (pile_size(ps->pile_a) > 3)
	{
		i = -1;
		size = pile_size(ps->pile_a);
		med = med + pile_size(ps->pile_a) / 2;
		while (++i < size && pile_size(ps->pile_a) > 3)
		{
			if (ps->pile_a->pos < med)
				add_action(ps, "pb");
			else
				add_action(ps, "ra");
		}
	}
	start_process_3(ps);
	while (ps->pile_b)
	{
		return_to_a(ps);
	}
}
