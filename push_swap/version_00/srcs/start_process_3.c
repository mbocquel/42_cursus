/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_process_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 15:57:50 by mbocquel          #+#    #+#             */
/*   Updated: 2023/01/07 18:04:38 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
