/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_all_change.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 16:04:46 by mbocquel          #+#    #+#             */
/*   Updated: 2022/12/21 15:02:45 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	clear_all_change(t_event_param *p)
{
	int	change;

	change = 0;
	clear_img(p);
	if (p->z_factor != 1 || p->angle_x != 0 || p->original_color != 1
		|| p->angle_z != 0 || p->angle_y != 0 || p->proj != 1)
	{
		initiate_param(p);
		change = 1;
	}
	apply_isometric_proj(p);
	if (p->scale_factor != get_scale_factor(p->trame, p->wdim)
		|| p->orig.xf != get_origin_coord(p).xf
		|| p->orig.yf != get_origin_coord(p).yf)
	{
		p->scale_factor = get_scale_factor(p->trame, p->wdim);
		p->orig = get_origin_coord(p);
		change = 1;
	}
	calculate_point_pos(p);
	tracer_trame(p);
	if (change)
		ft_printf("---- All changes cleared ----\n");
	else
		ft_printf("---- No changes to clear ----\n");
}
