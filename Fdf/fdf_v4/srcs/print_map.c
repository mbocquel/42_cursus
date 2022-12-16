/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:47:36 by mbocquel          #+#    #+#             */
/*   Updated: 2022/12/13 16:27:33 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_map(t_map *begin_map)
{
	t_map	*elem;
	int		i;

	elem = begin_map;
	while (elem)
	{
		i = -1;
		while (++i < elem->nb_col)
			ft_printf("%d\t", elem->line_int[i]);
		ft_printf("\n");
		elem = elem->next;
	}
}
