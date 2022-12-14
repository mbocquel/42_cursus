/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nb_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 16:22:31 by mbocquel          #+#    #+#             */
/*   Updated: 2022/12/13 16:23:13 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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