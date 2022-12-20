/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_trame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 18:40:23 by mbocquel          #+#    #+#             */
/*   Updated: 2022/12/20 14:25:38 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_trame(t_event_param *param, int key)
{
	if (key == KEY_X)
	{
		param->angle_x += (3.14159 / 30);
		ft_printf("---- Rotation on the X axis ----\n");
	}
	if (key == KEY_Y)
	{
		param->angle_y += (3.14159 / 30);
		ft_printf("---- Rotation on the Y axis ----\n");
	}
	if (key == KEY_Z)
	{
		param->angle_z += (3.14159 / 30);
		ft_printf("---- Rotation on the Z axis ----\n");
	}
	clear_img(param);
	apply_isometric_proj(param);
	calculate_point_pos(param);
	if (param->original_color)
		tracer_trame(param);
	else
		tracer_trame_color(param);
}
