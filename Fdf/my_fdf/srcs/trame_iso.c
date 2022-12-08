/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trame_iso.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 16:32:48 by mbocquel          #+#    #+#             */
/*   Updated: 2022/12/08 23:35:56 by mbocquel         ###   ########.fr       */
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
	new->point.color = 0;
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

	begin_trame = mk_trame_elem(0, 0);
	if (!begin_trame)
		return (NULL);
	previous = begin_trame;
	line = 0;
	col = 1;
	while (line < get_nb_line(begin_map))
	{
		if (line > 0)
			col = 0;
		while (col < begin_map->nb_col)
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
			col++;
		}
		line++;
	}
	return (begin_trame);
}

void	free_trame(t_trame *begin_trame)
{
	t_trame	*elem;
	t_trame	*next;

	elem = begin_trame;
	while (elem)
	{
		next = elem->next;
		free(elem);
		elem = next;
	}
}
