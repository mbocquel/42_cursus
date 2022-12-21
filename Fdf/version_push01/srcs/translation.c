/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 20:56:14 by mbocquel          #+#    #+#             */
/*   Updated: 2022/12/21 15:05:12 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	translation(t_event_param *param, int key)
{
	float	move;

	if (param->scale_factor)
		move = 10 / param->scale_factor;
	else
		move = 0.1;
	clear_img(param);
	if (key == KEY_LEFT_ARROW)
		param->orig.xf -= move;
	if (key == KEY_UP_ARROW)
		param->orig.yf -= move;
	if (key == KEY_LOW_ARROW)
		param->orig.yf += move;
	if (key == KEY_RIGHT_ARROW)
		param->orig.xf += move;
	if (param->proj == 1)
		apply_isometric_proj(param);
	else
		apply_para_proj(param);
	calculate_point_pos(param);
	ft_printf("---- Translation ----\n");
	if (param->original_color)
		tracer_trame(param);
	else
		tracer_trame_color(param);
}

void	focus_point(t_event_param *param, int x, int y)
{
	int	x_diff_px;
	int	y_diff_px;

	x_diff_px = (param->wdim.width / 2) - x;
	y_diff_px = (param->wdim.height / 2) - y;
	if (param->scale_factor)
	{
		param->orig.xf += (float)x_diff_px / param->scale_factor;
		param->orig.yf += (float)y_diff_px / param->scale_factor;
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
