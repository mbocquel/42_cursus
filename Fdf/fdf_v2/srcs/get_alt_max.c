/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_alt_max.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 16:24:50 by mbocquel          #+#    #+#             */
/*   Updated: 2022/12/13 16:24:52 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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