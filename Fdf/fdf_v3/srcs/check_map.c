/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 16:27:12 by mbocquel          #+#    #+#             */
/*   Updated: 2022/12/14 22:47:51 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	check_map(t_map *begin_map)
{
	t_map	*elem;
	int		nb_col;

	elem = begin_map;
	if (elem)
		nb_col = elem->nb_col;
	while (elem)
	{
		if (nb_col != elem->nb_col)
			return (0);
		elem = elem->next;
	}
	return (1);
}
