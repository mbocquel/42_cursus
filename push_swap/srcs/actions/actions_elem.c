/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_elem.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 14:46:34 by mbocquel          #+#    #+#             */
/*   Updated: 2023/01/12 15:04:37 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	action_swap(t_pile **pile)
{
	t_pile	*first;
	t_pile	*second;
	int		temp_val;
	int		temp_pos;

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

void	action_push(t_pile **pile_from, t_pile **pile_to)
{
	t_pile	*from_first;

	if (*pile_from == NULL)
		return ;
	from_first = *pile_from;
	if (from_first->next == from_first)
		*pile_from = NULL;
	else
	{
		(from_first->next)->prev = (from_first->prev);
		(from_first->prev)->next = (from_first->next);
		*pile_from = from_first->next;
	}
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

void	action_rotate(t_pile **pile)
{
	if (*pile)
	{
		*pile = (*pile)->next;
	}
}

void	action_r_rotate(t_pile **pile)
{
	if (*pile)
	{
		*pile = (*pile)->prev;
	}
}
