/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_alt_max.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 16:24:50 by mbocquel          #+#    #+#             */
/*   Updated: 2022/12/15 17:20:31 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
/* 
int	get_alt_max(t_map *begin_map)
{
	t_map	*elem;
	int		max;
	int		i;

	elem = begin_map;
	if (elem)
		max = ft_atoi(elem->elem_map[0][0]);
	while (elem)
	{
		i = 0;
		while (i < elem->nb_col)
		{
			if (ft_atoi(elem->elem_map[0][i]) > max)
				max = ft_atoi(elem->elem_map[0][i]);
			i++;
		}
		elem = elem->next;
	}
	return (max);
}
 */