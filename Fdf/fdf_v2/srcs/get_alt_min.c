/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_alt_min.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 16:23:54 by mbocquel          #+#    #+#             */
/*   Updated: 2022/12/13 16:24:06 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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