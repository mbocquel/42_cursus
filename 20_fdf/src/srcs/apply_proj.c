/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_proj.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 14:52:02 by mbocquel          #+#    #+#             */
/*   Updated: 2022/12/21 15:15:42 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	apply_isometric_proj(t_event_param *param)
{
	t_mat3x2	mat_proj;
	t_trame		*elem;
	t_point_3d	point;

	mat_proj.l1[0] = 0.7071;
	mat_proj.l1[1] = -0.7071;
	mat_proj.l1[2] = 0;
	mat_proj.l2[0] = 0.4472;
	mat_proj.l2[1] = 0.4472;
	mat_proj.l2[2] = -0.8944;
	elem = param->trame;
	while (elem)
	{
		point = rotate(param, elem->point_3d);
		elem->point_2d_fl = prod_mat3x2_p3d(mat_proj, point);
		elem = elem->next;
	}
}

void	apply_para_proj(t_event_param *param)
{
	t_mat3x2	mat_proj;
	t_trame		*elem;
	t_point_3d	point;

	mat_proj.l1[0] = 1;
	mat_proj.l1[1] = -1;
	mat_proj.l1[2] = 0;
	mat_proj.l2[0] = 0;
	mat_proj.l2[1] = 1;
	mat_proj.l2[2] = -1;
	elem = param->trame;
	while (elem)
	{
		point = rotate(param, elem->point_3d);
		elem->point_2d_fl = prod_mat3x2_p3d(mat_proj, point);
		elem = elem->next;
	}
}

void	change_proj(t_event_param *param, int key)
{
	if (key == KEY_P && param->proj == 1)
	{
		ft_printf("---- Parallel projection ----\n");
		param->proj = 2;
		clear_img(param);
		apply_para_proj(param);
		calculate_point_pos(param);
		if (param->original_color == 1)
			tracer_trame(param);
		else
			tracer_trame_color(param);
	}
	if (key == KEY_I && param->proj == 2)
	{
		ft_printf("---- Isometric projection ----\n");
		param->proj = 1;
		clear_img(param);
		apply_isometric_proj(param);
		calculate_point_pos(param);
		if (param->original_color == 1)
			tracer_trame(param);
		else
			tracer_trame_color(param);
	}
}
