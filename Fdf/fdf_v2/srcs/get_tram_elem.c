/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tram_elem.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 17:09:43 by mbocquel          #+#    #+#             */
/*   Updated: 2022/12/13 18:46:02 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_trame	*get_tram_elem(int line, int col, t_trame *begin)
{
	t_trame	*elem;

	elem = begin;
	while (elem)
	{
		if (elem->point_3d.y_3d == line && elem->point_3d.x_3d == col)
			return (elem);
		if (elem->point_3d.y_3d != line && elem->down)
			elem = elem->down;
		else if (elem->point_3d.y_3d == line && elem->point_3d.x_3d != col && elem->right)
			elem = elem->right;
	}
	return (NULL);
}