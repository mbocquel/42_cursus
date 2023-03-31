/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_all_change.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 16:04:46 by mbocquel          #+#    #+#             */
/*   Updated: 2023/03/31 11:15:33 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	clear_all_change(t_event_param *param)
{
	int	change;

	change = 0;
	clear_img(param);
	if (param->z_factor != 1 || param->original_color != 1)
	{
		initiate_param(param);
		change = 1;
	}
	apply_isometric_proj(param);
	if (param->scale_factor != get_scale_factor(param->trame, param->wdim)
		|| param->orig.xf != get_origin_coord(param).xf
		|| param->orig.yf != get_origin_coord(param).yf)
	{
		param->scale_factor = get_scale_factor(param->trame, param->wdim);
		param->orig = get_origin_coord(param);
		change = 1;
	}
	calculate_point_pos(param);
	tracer_trame(param);
	if (change)
		ft_printf("---- All changes cleared ----\n");
}
