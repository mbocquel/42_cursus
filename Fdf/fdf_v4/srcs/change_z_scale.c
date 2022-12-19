/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_z_scale.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 19:11:18 by mbocquel          #+#    #+#             */
/*   Updated: 2022/12/19 23:04:51 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	change_z_scale(t_event_param *param, int key)
{
	clear_img(param);
	if (key == KEY_L && param->z_factor >= 0)
		param->z_factor -= 0.05;
	if (key == KEY_H)
		param->z_factor += 0.05;
	apply_isometric_proj(param->trame, param->z_factor);
	calculate_point_pos(param);
	if (param->original_color)
		tracer_trame(param);
	else
		tracer_trame_color(param);
}
