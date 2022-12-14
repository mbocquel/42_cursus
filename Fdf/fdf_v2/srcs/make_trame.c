/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_trame.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 16:32:48 by mbocquel          #+#    #+#             */
/*   Updated: 2022/12/14 19:38:24 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_trame	*mk_trame_elem(int line, int col, t_map *map)
{
	t_trame	*new;

	new = malloc(sizeof(t_trame));
	if (!new)
		return (NULL);
	new->point_3d.x_3d = col;
	new->point_3d.y_3d = line;
	new->point_3d.z_3d = get_alt_point(line, col, map);
	new->point_2d_px.x = 0;
	new->point_2d_px.y = 0;
	if (new->point_3d.z_3d > 0)
		new->point_2d_px.color = create_trgb(0, 255, 0, 255);
	else
		new->point_2d_px.color = create_trgb(0, 255, 255, 255);
	new->point_2d_fl.xf = 0;
	new->point_2d_fl.yf = 0;
	new->down = NULL;
	new->right = NULL;
	new->next = NULL;
	return (new);
}

void	trame_add_back(t_trame *new, t_trame **begin_trame)
{
	t_trame	*elem;

	if (new == NULL)
		return ;
	if (*begin_trame == NULL)
	{
		*begin_trame = new;
		return ;
	}
	elem = *begin_trame;
	while (elem->next)
	{
		elem = elem->next;
	}
	elem->next = new;
}

t_trame	*make_trame(t_map *begin_map)
{
	int		col;
	int		line;
	t_trame	*begin_trame;
	t_trame	*elem;
	t_trame	*previous;

	begin_trame = NULL;
	line = -1;
	while (++line < get_nb_line(begin_map))
	{
		col = -1;
		while (++col < begin_map->nb_col)
		{
			elem = mk_trame_elem(line, col, begin_map);
			if (!elem)
				return (NULL);
			if (line > 0)
				get_tram_elem(line - 1, col, begin_trame)->down = elem;
			if (col > 0)
				previous->right = elem;
			trame_add_back(elem, &begin_trame);
			previous = elem;
		}
	}
	return (begin_trame);
}
