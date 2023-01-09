/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_process_big.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 15:57:50 by mbocquel          #+#    #+#             */
/*   Updated: 2023/01/09 17:04:41 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cost_frist_top(t_pile *pile, int start, int end, int *cost)
{
	t_pile	*elem;
	int		i;

	i = 0;
	elem = pile;
	while (elem)
	{
		if (elem->pos >= start && elem->pos <= end)
		{
			*cost = i;
			return ;
		}
		elem = elem->next;
		if (elem == pile)
			break ;
		i++;
	}
}

void	cost_frist_bottom(t_pile *pile, int start, int end, int *cost)
{
	t_pile	*elem;
	int		i;

	i = 0;
	elem = pile;
	while (elem)
	{
		if (elem->pos >= start && elem->pos <= end)
		{
			*cost = i + 1;
			return ;
		}
		elem = elem->prev;
		if (elem == pile)
			break ;
		i++;
	}
}

void	move_first_elem(t_ps *ps, int start, int end, char c)
{
	int		cost_top;
	int		cost_bottom;
	t_pile	*pile;

	pile = ps->pile_a;
	if (c == 'b')
		pile = ps->pile_b;
	cost_top = -1;
	cost_bottom = -1;
	cost_frist_top(pile, start, end, &cost_top);
	cost_frist_bottom(pile, start, end, &cost_bottom);
	if (cost_top <= cost_bottom)
	{
		while (cost_top-- > 0)
			add_action(ps, "ra");
	}
	else
	{
		while (cost_bottom-- > 0)
			add_action(ps, "rra");
	}
}

int	to_bring_top_b(t_pile *pile, int pos)
{
	t_pile	*elem;
	int		to_bring_top;
	int		pos_max;

	to_bring_top = 0;
	elem = pile;
	pos_max = 0;
	while (elem)
	{
		if (elem->pos < pos && elem->pos > to_bring_top)
			to_bring_top = elem->pos;
		if (elem->pos > pos_max)
			pos_max = elem->pos;
		elem = elem->next;
		if (elem == pile)
			break ;
	}
	if (to_bring_top == 0)
		return (pos_max);
	return (to_bring_top);
}

void	start_process_big(t_ps *ps, int nb_chunk)
{
	int	i;
	int	max;
	int	size;

	size = pile_size(ps->pile_a);
	i = 0;
	max = size / nb_chunk;
	while (++i <= size)
	{
		if (i % (size / nb_chunk) == 0 && max == nb_chunk * (size / nb_chunk))
			max = size;
		else if (i % (size / nb_chunk) == 0)
			max = max + (size / nb_chunk);
		move_first_elem(ps, 1, max, 'a');
		if (to_bring_top_b(ps->pile_b, ps->pile_a->pos) == 0)
			add_action(ps, "pb");
		else
		{
			bring_top(ps, to_bring_top_b(ps->pile_b, ps->pile_a->pos), 'b');
			add_action(ps, "pb");
		}
	}
	while (ps->pile_b)
		add_action(ps, "pa");
}
