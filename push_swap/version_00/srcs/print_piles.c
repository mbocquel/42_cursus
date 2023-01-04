/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_piles.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 18:06:41 by mbocquel          #+#    #+#             */
/*   Updated: 2023/01/04 15:49:51 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		ft_printf("________________________	________________________\n");
		if (!break_a)
			ft_printf("| %d				", elem_a->val);
		else
			ft_printf("|				");
		if (!break_b)
			ft_printf("| %d\n", elem_b->val);
		else
			ft_printf("|\n");
		if (!break_a)
			ft_printf("| pos %d				", elem_a->pos);
		else
			ft_printf("|				");
		if (!break_b)
			ft_printf("| pos %d\n", elem_b->pos);
		else
			ft_printf("|\n");
		if (!break_a)
			ft_printf("| %p		", elem_a);
		else
			ft_printf("|				");
		if (!break_b)
			ft_printf("| %p\n", elem_b);
		else
			ft_printf("|\n");
		if (!break_a)
			ft_printf("| next %p		", elem_a->next);
		else
			ft_printf("|				");
		if (!break_b)
			ft_printf("| next %p\n", elem_b->next);
		else
			ft_printf("|\n");
		if (!break_a)
			ft_printf("| prev %p		", elem_a->prev);
		else
			ft_printf("|				");
		if (!break_b)
			ft_printf("| prev %p		\n", elem_b->prev);
		else
			ft_printf("|			\n");
		if (!break_a)
			elem_a = elem_a->next;
		if (elem_a == ps->pile_a)
			break_a = 1;
		if (!break_b)
			elem_b = elem_b->next;
		if (elem_b == ps->pile_b)
			break_b = 1;
	}
	ft_printf("________________________	________________________\n");
	ft_printf("       PILE A           	          PILE B\n");
}
