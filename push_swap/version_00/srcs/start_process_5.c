/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_process_5.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 15:57:50 by mbocquel          #+#    #+#             */
/*   Updated: 2023/01/07 22:03:53 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	place(t_pile *pile, int pos)
{
	t_pile	*elem;
	int		i;

	i = 1;
	elem = pile;
	while (elem)
	{
		if (elem->pos == pos)
			return (i);
		elem = elem->next;
		if (elem == pile)
			break ;
		i++;
	}
	return (0);
}

int	next_pos_in_pile(t_ps *ps, int pos, char c)
{
	t_pile	*elem;
	t_pile	*start;
	int		next;

	next = pile_size(ps->pile_a) + pile_size(ps->pile_b) + 1;
	start = ps->pile_a;
	if (c == 'b')
		start = ps->pile_b;
	elem = start;
	while (elem)
	{
		if (elem->pos > pos && elem->pos < next)
			next = elem->pos;
		elem = elem->next;
		if (elem == start)
			break ;
	}
	if (next == pile_size(ps->pile_a) + pile_size(ps->pile_b) + 1)
		return (0);
	else
		return (next);
}

void	bring_top(t_ps *ps, int i, char c)
{
	int		cost;
	char	*rx;
	char	*rrx;
	t_pile	*pile;

	pile = ps->pile_a;
	rx = "ra";
	rrx = "rra";
	if (c == 'b')
	{
		pile = ps->pile_b;
		rx = "rb";
		rrx = "rrb";
	}
	if (place(pile, i) - 1 <= pile_size(pile) - place(pile, i) + 1)
		cost = place(pile, i) - 1;
	else
	{
		cost = pile_size(pile) - place(pile, i) + 1;
		rx = rrx;
	}
	while (cost--)
		add_action(ps, rx);
}

void	start_process_5(t_ps *ps)
{
	int	to_bring_top;

	to_bring_top = 0;
	while (pile_size(ps->pile_a) > 3)
		add_action(ps, "pb");
	start_process_3(ps);
	while (ps->pile_b)
	{
		if (pile_size(ps->pile_b) == 2 && pile_is_sorted(ps->pile_b))
			add_action(ps, "sb");
		to_bring_top = next_pos_in_pile(ps, ps->pile_b->pos, 'a');
		if (to_bring_top == 0)
		{
			add_action(ps, "pa");
			add_action(ps, "ra");
		}
		else
		{
			bring_top(ps, to_bring_top, 'a');
			add_action(ps, "pa");
		}
	}
	bring_top(ps, 1, 'a');
}
