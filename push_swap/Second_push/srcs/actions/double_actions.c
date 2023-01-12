/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_actions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 17:34:26 by mbocquel          #+#    #+#             */
/*   Updated: 2023/01/11 17:34:27 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate_ra_rb(t_ps *ps, t_cost c)
{
	while (c.ra > 0 || c.rb > 0)
	{
		if (c.ra-- > 0)
			add_action(ps, "ra");
		if (c.rb-- > 0)
			add_action(ps, "rb");
	}
}

void	rotate_rra_rrb(t_ps *ps, t_cost c)
{
	while (c.rra > 0 || c.rrb > 0)
	{
		if (c.rra-- > 0)
			add_action(ps, "rra");
		if (c.rrb-- > 0)
			add_action(ps, "rrb");
	}
}

void	rotate_rra_rb(t_ps *ps, t_cost c)
{
	while (c.rra-- > 0)
		add_action(ps, "rra");
	while (c.rb-- > 0)
		add_action(ps, "rb");
}

void	rotate_ra_rrb(t_ps *ps, t_cost c)
{
	while (c.ra-- > 0)
		add_action(ps, "ra");
	while (c.rrb-- > 0)
		add_action(ps, "rrb");
}
