/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_front_lst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 18:33:40 by mbocquel          #+#    #+#             */
/*   Updated: 2023/01/02 19:17:47 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_front_lst(t_lst_ps **pile_a, int arg, int *error)
{
	t_lst_ps		*new;
	static t_lst_ps	*prev = NULL;

	new = (t_lst_ps *)malloc(sizeof(t_lst_ps));
	if (new == NULL)
	{
		*error = 1;
		return ;
	}
	new->val = arg;
	new->next = NULL;
	new->prev = prev;
	if (pile_a == NULL)
	{
		*pile_a = new;
	}
	else
	{
		new->next = *pile_a;
		*pile_a = new;
		prev = new;
	}
}
