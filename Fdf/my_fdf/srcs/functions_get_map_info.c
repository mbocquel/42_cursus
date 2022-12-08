/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_get_map_info.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 23:43:58 by mbocquel          #+#    #+#             */
/*   Updated: 2022/12/08 23:45:21 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_alt_point(int line, int col, t_map *begin_map)
{
	t_map	*elem;

	elem = begin_map;
	while (elem)
	{
		if (elem->n_line == line && col < elem->nb_col)
			return (elem->line_int[col]);
		elem = elem->next;
	}
	return (0);
}

int	get_alt_max(t_map *begin_map)
{
	t_map	*elem;
	int		max;
	int		i;

	elem = begin_map;
	if (elem)
		max = elem->line_int[0];
	while (elem)
	{
		i = 0;
		while (i < elem->nb_col)
		{
			if (elem->line_int[i] > max)
				max = elem->line_int[i];
			i++;
		}
		elem = elem->next;
	}
	return (max);
}

int	get_alt_min(t_map *begin_map)
{
	t_map	*elem;
	int		min;
	int		i;

	elem = begin_map;
	if (elem)
		min = elem->line_int[0];
	while (elem)
	{
		i = 0;
		while (i < elem->nb_col)
		{
			if (elem->line_int[i] < min)
				min = elem->line_int[i];
			i++;
		}
		elem = elem->next;
	}
	return (min);
}

int	get_nb_line(t_map *begin_map)
{
	t_map	*elem;
	int		i;

	elem = begin_map;
	i = 0;
	while (elem)
	{
		i++;
		elem = elem->next;
	}
	return (i);
}
