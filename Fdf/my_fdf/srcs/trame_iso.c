/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trame_iso.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 16:32:48 by mbocquel          #+#    #+#             */
/*   Updated: 2022/12/12 19:59:17 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_trame	*mk_trame_elem(int line, int col)
{
	t_trame	*new;

	new = malloc(sizeof(t_trame));
	if (!new)
		return (NULL);
	new->line = line;
	new->col = col;
	new->point.x = 0;
	new->point.y = 0;
	new->point.color = create_trgb(0, 125, 125, 105);
	new->down = NULL;
	new->right = NULL;
	new->next = NULL;
	return (new);
}

t_trame	*get_tram_elem(int line, int col, t_trame *begin)
{
	t_trame	*elem;

	elem = begin;
	while (elem)
	{
		if (elem->line == line && elem->col == col)
			return (elem);
		if (elem->line != line && elem->down)
			elem = elem->down;
		else if (elem->line == line && elem->col != col && elem->right)
			elem = elem->right;
	}
	return (NULL);
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
			elem = mk_trame_elem(line, col);
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
