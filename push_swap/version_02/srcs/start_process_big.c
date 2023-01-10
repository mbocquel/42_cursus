/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_process_big.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 11:10:15 by mbocquel          #+#    #+#             */
/*   Updated: 2023/01/10 14:15:25 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_max(int a, int b)
{
	if (a >= b)
		return (a);
	else
		return (b);	
}

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

void	move_first_elem_a(t_ps *ps, int start, int end)
{
	int		cost_top;
	int		cost_bottom;
	t_pile	*pile;

	pile = ps->pile_a;
	cost_top = -1;
	cost_bottom = -1;
	cost_frist_top(pile, start, end, &cost_top);
	cost_frist_bottom(pile, start, end, &cost_bottom);
	if (cost_top == -1 || cost_bottom == -1)
		return ;
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

void	return_to_a(t_ps *ps, int size)
{
	int	cost_b;
	int	cost_a;
	int	rx;
	int	pos_to_send;
	
	pos_to_send = find_elem_to_bring_back(ps);
	rx = 0;
	cost_bring_back_to_a(ps, pos_to_send, &rx); //permet de savoir le sens
	cost_a = 0;
	if (rx == 1)
		cost_b = place(ps->pile_b, pos_to_send) - 1;
	else
		cost_b = pile_size(ps->pile_b) - place(ps->pile_b, pos_to_send) + 1;
	if (to_bring_top_a(ps->pile_a, pos_to_send, size))
	{
		if (rx == 1)
			cost_a = place(ps->pile_a, to_bring_top_a(ps->pile_a, pos_to_send, size)) - 1;
		else
			cost_a = pile_size(ps->pile_a) - place(ps->pile_a, to_bring_top_a(ps->pile_a, pos_to_send, size)) + 1;
	}
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

void	second_part_process(t_ps *ps)
{
	int	size;

	size = pile_size(ps->pile_a) + pile_size(ps->pile_b);
	while (ps->pile_b)
	{
		return_to_a(ps, size);
	}
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
		{
			//print_piles(ps);
			max = size;
		}
		else if (i % (size / nb_chunk) == 0)
		{
			//print_piles(ps);
			max = max + (size / nb_chunk);
		}
		move_first_elem_a(ps, 1, max);
		add_action(ps, "pb");
	}
	ft_printf("Fin du premier passage de a->b\n");
	print_piles(ps);
	second_part_process(ps);
	bring_top(ps, 1, 'a');
	print_piles(ps);
}
