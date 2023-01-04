/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_front_lst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 18:33:40 by mbocquel          #+#    #+#             */
/*   Updated: 2023/01/04 15:43:02 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_in_pile(t_pile *pile, int val)
{
	t_pile	*elem;

	elem = pile;
	while (elem)
	{
		if (elem->val == val)
			return (1);
		elem = elem->next;
	}
	return (0);
}

void	add_to_pile(t_ps *ps, int val)
{
	t_pile			*new;
	static t_pile	*prev = NULL;

	new = (t_pile *)malloc(sizeof(t_pile));
	if (new == NULL)
		ft_exit(ps, ERROR_PARSING);
	new->val = val;
	new->pos = 0;
	new->next = NULL;
	new->prev = NULL;
	if (ps->pile_a == NULL)
		ps->pile_a = new;
	else
	{
		new->next = ps->pile_a;
		ps->pile_a = new;
		if (prev)
			prev->prev = new;
	}
	prev = new;
}

void	push_front_lst(t_pile **pile_a, int val, int *error)
{
	t_pile			*new;
	static t_pile	*prev = NULL;

	new = (t_pile *)malloc(sizeof(t_pile));
	if (new == NULL)
	{
		*error = 1;
		return ;
	}
	new->val = val;
	new->pos = 0;
	new->next = NULL;
	new->prev = NULL;
	if (pile_a == NULL)
		*pile_a = new;
	else
	{
		new->next = *pile_a;
		*pile_a = new;
		if (prev)
			prev->prev = new;
		prev = new;
	}
}
