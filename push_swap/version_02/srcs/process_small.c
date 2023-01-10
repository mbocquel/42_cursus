/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_small.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 15:57:50 by mbocquel          #+#    #+#             */
/*   Updated: 2023/01/10 16:59:43 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	start_process_3(t_ps *ps)
{
	t_pile	*top;

	top = ps->pile_a;
	if (top->pos > top->next->pos && top->next->pos < top->prev->pos
		&& top->pos < top->prev->pos)
		add_action(ps, "sa");
	else if (top->pos > top->next->pos && top->next->pos > top->prev->pos
		&& top->pos > top->prev->pos)
	{
		add_action(ps, "sa");
		add_action(ps, "rra");
	}
	else if (top->pos > top->next->pos && top->next->pos < top->prev->pos
		&& top->pos > top->prev->pos)
		add_action(ps, "ra");
	else if (top->pos < top->next->pos && top->next->pos > top->prev->pos
		&& top->pos < top->prev->pos)
	{
		add_action(ps, "sa");
		add_action(ps, "ra");
	}
	else if (top->pos < top->next->pos && top->next->pos > top->prev->pos
		&& top->pos > top->prev->pos)
		add_action(ps, "rra");
}

void	start_process_5(t_ps *ps)
{
	int	top_a;
	int	size;

	if (pile_is_sorted(ps->pile_a))
		return ;
	size = pile_size(ps->pile_a) + pile_size(ps->pile_b);
	top_a = 0;
	while (pile_size(ps->pile_a) > 3)
		add_action(ps, "pb");
	start_process_3(ps);
	while (ps->pile_b)
	{
		if (pile_size(ps->pile_b) == 2 && pile_is_sorted(ps->pile_b))
			add_action(ps, "sb");
		top_a = to_bring_top_a(ps->pile_a, ps->pile_b->pos, size);
		if (top_a)
			bring_top(ps, top_a, 'a');
		add_action(ps, "pa");
	}
}
