/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_point_pos.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 16:18:10 by mbocquel          #+#    #+#             */
/*   Updated: 2022/12/14 22:50:00 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	calculate_point_pos(t_trame *trame, t_wdim wdim)
{
	t_trame			*elem;
	t_point2d_fl	orig;
	float			factor;

	elem = trame;
	factor = get_scale_factor(trame, wdim);
	orig = get_origin_coord(trame);
	while (elem)
	{
		elem->point_2d_px.x = (int)(factor * (elem->point_2d_fl.xf + orig.xf));
		elem->point_2d_px.y = (int)(factor * (elem->point_2d_fl.yf + orig.yf));
		elem = elem->next;
	}
}
