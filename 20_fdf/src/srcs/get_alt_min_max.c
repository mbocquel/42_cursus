/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_alt_min_max.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 22:29:42 by mbocquel          #+#    #+#             */
/*   Updated: 2022/12/16 22:58:38 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_alt_min_max(t_trame *trame, float *min, float *max)
{
	t_trame	*elem;

	elem = trame;
	if (elem)
	{
		*min = elem->point_3d.z_3d;
		*max = elem->point_3d.z_3d;
	}
	while (elem)
	{
		if (elem->point_3d.z_3d < *min)
			*min = elem->point_3d.z_3d;
		if (elem->point_3d.z_3d > *max)
			*max = elem->point_3d.z_3d;
		elem = elem->next;
	}
}
