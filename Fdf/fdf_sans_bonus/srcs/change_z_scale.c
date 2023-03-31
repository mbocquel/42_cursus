/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_z_scale.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 19:11:18 by mbocquel          #+#    #+#             */
/*   Updated: 2023/03/31 11:28:30 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	change_z_scale(t_event_param *param, int key)
{
	clear_img(param);
	if (key == KEY_L && param->z_factor >= 0)
	{
		param->z_factor -= 0.01;
		ft_printf("---- Altitude scale reduced ----\n");
	}
	if (key == KEY_H)
	{
		param->z_factor += 0.01;
		ft_printf("---- Altitude scale increased ----\n");
	}
	apply_isometric_proj(param);
	calculate_point_pos(param);
	tracer_trame(param);
}
