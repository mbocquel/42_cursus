/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tram_elem.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 17:09:43 by mbocquel          #+#    #+#             */
/*   Updated: 2022/12/20 14:19:27 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_trame	*get_tram_elem(int line, int col, t_trame *begin)
{
	t_trame	*elem;

	elem = begin;
	while (elem)
	{
		if (elem->point_3d.y_3d == (float)line
			&& elem->point_3d.x_3d == (float)col)
			return (elem);
		else
			elem = elem->next;
	}
	return (NULL);
}
