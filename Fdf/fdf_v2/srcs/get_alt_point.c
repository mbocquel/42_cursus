/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_alt_point.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 23:43:58 by mbocquel          #+#    #+#             */
/*   Updated: 2022/12/13 16:25:51 by mbocquel         ###   ########.fr       */
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

