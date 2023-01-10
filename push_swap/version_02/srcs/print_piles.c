/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_piles.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 18:06:41 by mbocquel          #+#    #+#             */
/*   Updated: 2023/01/10 16:46:32 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_piles_2(t_pile *e_a, t_pile *e_b, int b_a, int b_b)
{
	if (!b_a)
		ft_printf("| %d				", e_a->pos);
	else
		ft_printf("|				");
	if (!b_b)
		ft_printf("| %d \n", e_b->pos);
	else
		ft_printf("|\n");
}

void	print_piles(t_ps *ps)
{
	t_pile	*elem_a;
	t_pile	*elem_b;
	int		break_a;
	int		break_b;

	elem_a = ps->pile_a;
	elem_b = ps->pile_b;
	break_a = 0;
	break_b = 0;
	if (!elem_a)
		break_a = 1;
	if (!elem_b)
		break_b = 1;
	while (!break_a || !break_b)
	{
		print_piles_2(elem_a, elem_b, break_a, break_b);
		if (!break_a)
			elem_a = elem_a->next;
		if (elem_a == ps->pile_a)
			break_a = 1;
		if (!break_b)
			elem_b = elem_b->next;
		if (elem_b == ps->pile_b)
			break_b = 1;
	}
}
