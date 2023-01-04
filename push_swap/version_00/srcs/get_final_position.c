/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_final_position.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 18:52:31 by mbocquel          #+#    #+#             */
/*   Updated: 2023/01/04 17:04:42 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pile_size(t_pile *pile)
{
	int		i;
	t_pile	*elem;

	i = 0;
	elem = pile;
	while (elem)
	{
		i++;
		elem = elem->next;
		if (elem == pile)
			break ;
	}
	return (i);
}

int	get_elem_pos(int val, int *tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (tab[i] == val)
			return (i + 1);
		i++;
	}
	return (-1);
}

void	ft_sort_tab(int *tab, int size)
{
	int	test_finish;
	int	a;
	int	i;

	test_finish = 0;
	while (test_finish == 0)
	{
		test_finish = 1;
		i = 0;
		while (i < (size - 1))
		{
			if (tab[i] > tab[i + 1])
			{
				test_finish = 0;
				a = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = a;
			}
			i++;
		}
	}
}

void	add_position(t_ps *ps, int *tab, int size)
{
	t_pile	*elem;

	elem = ps->pile_a;
	while (elem)
	{
		elem->pos = get_elem_pos(elem->val, tab, size);
		elem = elem->next;
		if (elem == ps->pile_a)
			break ;
	}
}

void	get_final_position(t_ps *ps)
{
	int		*tab;
	int		i;
	t_pile	*elem;
	int		size;

	size = pile_size(ps->pile_a);
	tab = (int *)malloc(size * sizeof(int));
	if (tab == NULL)
		ft_exit(ps, ERROR_PARSING);
	i = 0;
	elem = ps->pile_a;
	while (elem)
	{
		tab[i] = elem->val;
		i++;
		elem = elem->next;
		if (elem == ps->pile_a)
			break ;
	}
	ft_sort_tab(tab, size);
	add_position(ps, tab, size);
	free(tab);
}
