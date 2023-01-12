/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_elem2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:04:23 by mbocquel          #+#    #+#             */
/*   Updated: 2023/01/12 15:06:18 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	action_double_swap(t_ps *ps)
{
	action_swap(&(ps->pile_a));
	action_swap(&(ps->pile_b));
}

void	action_double_rotate(t_ps *ps)
{
	action_rotate(&(ps->pile_a));
	action_rotate(&(ps->pile_b));
}

void	action_double_r_rotate(t_ps *ps)
{
	action_r_rotate(&(ps->pile_a));
	action_r_rotate(&(ps->pile_b));
}
