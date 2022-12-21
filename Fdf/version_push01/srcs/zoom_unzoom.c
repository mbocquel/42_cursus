/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_unzoom.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 18:38:41 by mbocquel          #+#    #+#             */
/*   Updated: 2022/12/21 15:05:24 by mbocquel         ###   ########.fr       */
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
	if (param->proj == 1)
		apply_isometric_proj(param);
	else
		apply_para_proj(param);
	calculate_point_pos(param);
	if (param->original_color)
		tracer_trame(param);
	else
		tracer_trame_color(param);
}
