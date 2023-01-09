/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_process_big.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 15:57:50 by mbocquel          #+#    #+#             */
/*   Updated: 2023/01/09 19:30:10 by mbocquel         ###   ########.fr       */
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
	if (cost_top == -1 || cost_bottom == -1)
		return ;
	if (c == 'a')
	{
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
	else
	{
		if (cost_top <= cost_bottom)
		{
			while (cost_top-- > 0)
				add_action(ps, "rb");
		}
		else
		{
			while (cost_bottom-- > 0)
				add_action(ps, "rrb");
		}
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

/*void	bring_back_to_a(t_ps *ps, int size)
{
	int	i;

	i = 0;
	while (++i <= size)
	{
		if (to_bring_top_a(ps->pile_a, ps->pile_b->pos, size))
			bring_top(ps,
				to_bring_top_a(ps->pile_a, ps->pile_b->pos, size), 'a');
		add_action(ps, "pa");
	}
}*/

void	bring_back_to_a(t_ps *ps, int nb_chunk, int size)
{
	int	i;
	int	min;

	min = size - size / nb_chunk;
	ft_printf("nb_chunk %d\n", nb_chunk);
	ft_printf("min %d\n", min);
	i = 0;
	while (++i <= size)
	{
		if (i % (size / nb_chunk) == 0 && min == size - (nb_chunk - 1) * nb_chunk * (size / nb_chunk))
		{
			min = 1;
			//print_piles(ps);
		}
		else if (i % (size / nb_chunk) == 0)
		{
			min = min - (size / nb_chunk);
			//print_piles(ps);
		}
		move_first_elem(ps, min, size, 'b');
		add_action(ps, "pa");
	}

}

void	passage_vers_b(t_ps *ps, int nb_chunk, int size)
{
	int	i;
	int	max;
	
	max = size / nb_chunk;
	ft_printf("nb_chunk %d\n", nb_chunk);
	ft_printf("max %d\n", max);
	ft_printf("size %d\n", size);
	i = 0;
	while (++i <= size)
	{
		if (i % (size / nb_chunk) == 0 && max == nb_chunk * (size / nb_chunk))
		{
			//print_piles(ps);
			max = size;
		}
		else if (i % (size / nb_chunk) == 0 && max < size)
		{
			//print_piles(ps);
			max = max + (size / nb_chunk);
		}
		print_piles(ps);
		ft_printf("move_first_elem(ps, 1, %d, 'a');\n", max);
		move_first_elem(ps, 1, max, 'a');
		add_action(ps, "pb");
	}
}
/*
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
		move_first_elem(ps, 1, max, 'a');
		add_action(ps, "pb");
	}
	ft_printf("Fin du premier passage de a->b\n");
	print_piles(ps);
	bring_back_to_a(ps, nb_chunk * nb_chunk, size);
}
*/

void	start_process_big(t_ps *ps, int nb_chunk)
{
	int	size;

	size = pile_size(ps->pile_a);
	passage_vers_b(ps, nb_chunk, size);
	ft_printf("Fin du premier passage de a->b\n");
	print_piles(ps);
	bring_back_to_a(ps, nb_chunk * nb_chunk, size);
	ft_printf("Fin du retour vers a\n");
	print_piles(ps);
	passage_vers_b(ps, nb_chunk * nb_chunk * 2, size);
	
	
}
