/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_swap_push.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 14:46:34 by mbocquel          #+#    #+#             */
/*   Updated: 2023/01/03 18:54:23 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	action_swap(t_pile **pile)
{
	t_pile	*first;
	t_pile	*second;
	int			temp_val;
	int			temp_pos;

	if (*pile && (*pile)->next)
	{
		first = *pile;
		second = (*pile)->next;
		temp_val = second->val;
		second->val = first->val;
		first->val = temp_val;
		temp_pos = second->pos;
		second->pos = first->pos;
		first->pos = temp_pos;
	}
}

void	action_d_swap(t_pile **pile_a, t_pile **pile_b)
{
	action_swap(pile_a);
	action_swap(pile_b);
}

void	action_push(t_pile **pile_from, t_pile **pile_to)
{
	t_pile	*from_first;
	t_pile	*from_second;
	t_pile	*from_last;

	if (*pile_from == NULL)
		return ;
	from_first = *pile_from;
	from_second = from_first->next;
	from_last = from_first->prev;
	from_second->prev = from_last;
	from_last->next = from_second;
	*pile_from = from_second;
	if (*pile_to == NULL)
	{
		*pile_to = from_first;
		from_first->next = from_first;
		from_first->prev = from_first;
		return ;
	}
	from_first->next = *pile_to;
	from_first->prev = (*pile_to)->prev;
	((*pile_to)->prev)->next = from_first;
	(*pile_to)->prev = from_first;
	*pile_to = from_first;
}
