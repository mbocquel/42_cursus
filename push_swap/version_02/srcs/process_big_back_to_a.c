/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_big_back_to_a.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:50:03 by mbocquel          #+#    #+#             */
/*   Updated: 2023/01/10 15:14:59 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	cost_bring_back_to_a(t_ps *ps, int pos, int *rx)
{
	int	cost_rx;
	int	cost_rrx;
	int	top_a;
	int	size;

	*rx = 1;
	size = pile_size(ps->pile_a) + pile_size(ps->pile_b);
	cost_rx = place(ps->pile_b, pos) - 1;
	cost_rrx = pile_size(ps->pile_b) - place(ps->pile_b, pos) + 1;
	top_a = to_bring_top_a(ps->pile_a, pos, size);
	if (top_a)
	{
		cost_rx = ft_max(cost_rx, place(ps->pile_a, top_a) - 1);
		cost_rrx = ft_max(cost_rrx, pile_size(ps->pile_a)
				- place(ps->pile_a, top_a) + 1);
	}
	if (cost_rx <= cost_rrx)
		return (cost_rx);
	else
	{
		*rx = 0;
		return (cost_rrx);
	}
}

int	to_bring_top_a(t_pile *pile, int pos, int size)
{
	t_pile	*elem;
	int		to_bring_top;
	int		pos_min;

	if (!pile)
		return (0);
	to_bring_top = size + 1;
	elem = pile;
	pos_min = size;
	while (elem)
	{
		if (elem->pos > pos && elem->pos < to_bring_top)
			to_bring_top = elem->pos;
		if (elem->pos < pos_min)
			pos_min = elem->pos;
		elem = elem->next;
		if (elem == pile)
			break ;
	}
	if (to_bring_top == size + 1)
		return (pos_min);
	return (to_bring_top);
}

int	find_elem_to_bring_back(t_ps *ps)
{
	int		pos;
	int		cost;
	int		rx;
	t_pile	*elem;

	elem = ps->pile_b;
	if (!elem)
		return (0);
	rx = 1;
	pos = elem->pos;
	cost = cost_bring_back_to_a(ps, elem->pos, &rx);
	while (elem)
	{
		if (cost_bring_back_to_a(ps, elem->pos, &rx) < cost)
		{
			cost = cost_bring_back_to_a(ps, elem->pos, &rx);
			pos = elem->pos;
		}
		elem = elem->next;
		if (elem == ps->pile_b)
			break ;
	}
	return (pos);
}

void	action_return_opti(t_ps *ps, int cost_a, int cost_b, int rx)
{
	while (cost_a > 0 || cost_b > 0)
	{
		if (rx == 1 && cost_a-- > 0)
			add_action(ps, "ra");
		else if (rx == 0 && cost_a-- > 0)
			add_action(ps, "rra");
		if (rx == 1 && cost_b-- > 0)
			add_action(ps, "rb");
		else if (rx == 0 && cost_b-- > 0)
			add_action(ps, "rrb");
	}
	add_action(ps, "pa");
}

void	return_to_a(t_ps *ps, int size)
{
	int	cost_b;
	int	cost_a;
	int	rx;
	int	pos;

	pos = find_elem_to_bring_back(ps);
	rx = 0;
	cost_bring_back_to_a(ps, pos, &rx);
	cost_a = 0;
	if (rx == 1)
		cost_b = place(ps->pile_b, pos) - 1;
	else
		cost_b = pile_size(ps->pile_b) - place(ps->pile_b, pos) + 1;
	if (to_bring_top_a(ps->pile_a, pos, size))
	{
		if (rx == 1)
			cost_a = place(ps->pile_a,
					to_bring_top_a(ps->pile_a, pos, size)) - 1;
		else
			cost_a = pile_size(ps->pile_a)
				- place(ps->pile_a, to_bring_top_a(ps->pile_a, pos, size)) + 1;
	}
	action_return_opti(ps, cost_a, cost_b, rx);
}
