/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:57:22 by mbocquel          #+#    #+#             */
/*   Updated: 2023/01/11 17:36:37 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	pile_is_sorted(t_pile *pile)
{
	t_pile	*elem;

	elem = pile;
	while (elem)
	{
		if (elem->next == pile)
			break ;
		if (elem->pos > elem->next->pos)
			return (0);
		elem = elem->next;
	}
	return (1);
}

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

void	init_cost(t_cost *c)
{
	c->ra = 0;
	c->rra = 0;
	c->rb = 0;
	c->rrb = 0;
	c->rev_a = 0;
	c->rev_b = 0;
}
