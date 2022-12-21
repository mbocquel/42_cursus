/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_unzoom.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 18:38:41 by mbocquel          #+#    #+#             */
/*   Updated: 2022/12/20 16:07:57 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	zoom_function(t_event_param *param, int button)
{
	if (button == MOUSE_ROLL_ZOOM)
	{
		param->scale_factor *= 1.1;
		ft_printf("---- Zoom in ----\n");
	}
	if (button == MOUSE_ROLL_UNZOOM)
	{
		param->scale_factor *= 0.9;
		ft_printf("---- Zoom out ----\n");
	}
	clear_img(param);
	apply_isometric_proj(param);
	calculate_point_pos(param);
	if (param->original_color)
		tracer_trame(param);
	else
		tracer_trame_color(param);
}
