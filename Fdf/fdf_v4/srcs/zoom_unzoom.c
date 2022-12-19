/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_unzoom.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 18:38:41 by mbocquel          #+#    #+#             */
/*   Updated: 2022/12/19 22:50:43 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	zoom_function(t_event_param *param, int x, int y)
{
	(void)x;
	(void)y;
	clear_img(param);
	param->scale_factor *= 1.1;
	apply_isometric_proj(param->trame, param->z_factor);
	calculate_point_pos(param);
	if (param->original_color)
		tracer_trame(param);
	else
		tracer_trame_color(param);
}
	
void	unzoom_function(t_event_param *param, int x, int y)
{
	(void)x;
	(void)y;
	clear_img(param);
	param->scale_factor *= 0.9;
	apply_isometric_proj(param->trame, param->z_factor);
	calculate_point_pos(param);
	if (param->original_color)
		tracer_trame(param);
	else
		tracer_trame_color(param);
}