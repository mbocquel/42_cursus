/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_big_back_to_a.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:50:03 by mbocquel          #+#    #+#             */
/*   Updated: 2023/01/17 18:53:04 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_cost	cost_bring_back_to_a(t_ps *ps, int pos)
{
	t_cost	c;
	int		top_a;

	init_cost(&c);
	c.rb = place(ps->pile_b, pos) - 1;
	c.rrb = pile_size(ps->pile_b) - place(ps->pile_b, pos) + 1;
	top_a = to_bring_top_a(ps, pos);
	if (top_a)
	{
		c.ra = place(ps->pile_a, top_a) - 1;
		c.rra = pile_size(ps->pile_a) - place(ps->pile_a, top_a) + 1;
	}
	c.total = ft_min4(ft_max(c.ra, c.rb), ft_max(c.rra, c.rrb),
			c.ra + c.rrb, c.rra + c.rb);
	if (c.total == ft_max(c.rra, c.rrb))
	{
		c.rev_a = 1;
		c.rev_b = 1;
	}
	else if (c.total == c.ra + c.rrb)
		c.rev_b = 1;
	else if (c.total == c.rra + c.rb)
		c.rev_a = 1;
	return (c);
}

int	to_bring_top_a(t_ps *ps, int pos)
{
	t_pile	*elem;
	int		to_bring_top;
	int		pos_min;

	if (!ps->pile_a)
		return (0);
	to_bring_top = pile_size(ps->pile_a) + pile_size(ps->pile_b) + 1;
	elem = ps->pile_a;
	pos_min = pile_size(ps->pile_a) + pile_size(ps->pile_b);
	while (elem)
	{
		if (elem->pos > pos && elem->pos < to_bring_top)
			to_bring_top = elem->pos;
		if (elem->pos < pos_min)
			pos_min = elem->pos;
		elem = elem->next;
		if (elem == ps->pile_a)
			break ;
	}
	if (to_bring_top == pile_size(ps->pile_a) + pile_size(ps->pile_b) + 1)
		return (pos_min);
	return (to_bring_top);
}

int	find_elem_to_bring_back(t_ps *ps)
{
	int		pos;
	int		cost;
	t_pile	*elem;

	elem = ps->pile_b;
	if (!elem)
		return (0);
	pos = elem->pos;
	cost = cost_bring_back_to_a(ps, elem->pos).total;
	while (elem)
	{
		if (cost_bring_back_to_a(ps, elem->pos).total < cost)
		{
			cost = cost_bring_back_to_a(ps, elem->pos).total;
			pos = elem->pos;
		}
		elem = elem->next;
		if (elem == ps->pile_b)
			break ;
	}
	return (pos);
}

void	return_to_a(t_ps *ps)
{
	t_cost	c;
	int		pos;

	pos = find_elem_to_bring_back(ps);
	c = cost_bring_back_to_a(ps, pos);
	if (!c.rev_a && !c.rev_b)
		rotate_ra_rb(ps, c);
	if (c.rev_a && c.rev_b)
		rotate_rra_rrb(ps, c);
	if (c.rev_a && !c.rev_b)
		rotate_rra_rb(ps, c);
	if (!c.rev_a && c.rev_b)
		rotate_ra_rrb(ps, c);
	add_action(ps, "pa");
}
