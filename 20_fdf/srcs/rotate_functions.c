/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 21:42:03 by mbocquel          #+#    #+#             */
/*   Updated: 2022/12/21 15:04:30 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point_3d	rotate(t_event_param *param, t_point_3d p3d)
{
	t_mat3x3	mat_rot;
	t_point_3d	result;
	float		angle_x;
	float		angle_y;
	float		angle_z;

	angle_x = param->angle_x;
	angle_y = param->angle_y;
	angle_z = param->angle_z;
	p3d.z_3d *= param->z_factor;
	mat_rot.l1[0] = cos(angle_y) * cos(angle_z);
	mat_rot.l1[1] = cos(angle_z) * sin(angle_y) * sin(angle_x)
		- sin(angle_z) * cos(angle_x);
	mat_rot.l1[2] = cos(angle_x) * sin(angle_y) * cos(angle_z)
		+ sin(angle_z) * sin(angle_x);
	mat_rot.l2[0] = sin(angle_z) * cos(angle_y);
	mat_rot.l2[1] = sin(angle_z) * sin(angle_y) * sin(angle_x)
		+ cos(angle_z) * cos(angle_x);
	mat_rot.l2[2] = sin(angle_z) * sin(angle_y) * cos(angle_x)
		- cos(angle_z) * sin(angle_x);
	mat_rot.l3[0] = -sin(angle_y);
	mat_rot.l3[1] = cos(angle_y) * sin(angle_x);
	mat_rot.l3[2] = cos(angle_y) * cos(angle_x);
	result = prod_mat3x3_p3d(mat_rot, p3d);
	return (result);
}

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
