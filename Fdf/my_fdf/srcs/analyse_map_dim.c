/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyse_map_dim.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 17:38:36 by mbocquel          #+#    #+#             */
/*   Updated: 2022/12/09 18:04:11 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_px_unit_x(t_map *map, t_wdim wdim)
{
	int	u_x;
	int	qt;

	u_x = 0;
	qt = (int)((float)((get_nb_line(map) + map->nb_col) * 120) / 100);
	if (qt)
		u_x = wdim.width / qt;
	return (u_x);
}

int	get_px_unit_y(t_map *map, t_wdim wdim)
{
	int	u_y;
	int	qt;

	u_y = 0;
	qt = (int)((float)((get_nb_line(map) + map->nb_col) * 120) / 100);
	if (qt)
		u_y = wdim.width / qt;
	return (u_y);
}

int	va_abs(int i)
{
	if (i < 0 && i != -2147483648)
		i = -i;
	return (i);
}

int	get_max_high_up(t_map *map)
{
	t_map	*elem;
	int		max;
	int		i;

	elem = map;
	if (elem)
		max = elem->line_int[0];
	while (elem)
	{
		i = 0;
		while (i < elem->nb_col)
		{
			if (elem->line_int[i] - elem->n_line - i > max)
				max = elem->line_int[i] - elem->n_line - i;
			i++;
		}
		elem = elem->next;
	}
	return (max);
}
/*
t_point	get_origin_coord(t_map *map, t_wdim wdim)
{
	
}
*/

