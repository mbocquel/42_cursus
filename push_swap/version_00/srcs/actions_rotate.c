/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 18:24:03 by mbocquel          #+#    #+#             */
/*   Updated: 2023/01/03 18:54:23 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	action_rotate(t_pile **pile)
{
	if (*pile)
	{
		*pile = (*pile)->next;
	}
}

void	action_d_rotate(t_pile **pile_a, t_pile **pile_b)
{
	action_rotate(pile_a);
	action_rotate(pile_b);
}

void	action_r_rotate(t_pile **pile)
{
	if (*pile)
	{
		*pile = (*pile)->prev;
	}
}

void	action_d_r_rotate(t_pile **pile_a, t_pile **pile_b)
{
	action_r_rotate(pile_a);
	action_r_rotate(pile_b);
}
