/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_isometric_proj.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 14:04:57 by mbocquel          #+#    #+#             */
/*   Updated: 2022/12/14 15:29:05 by mbocquel         ###   ########.fr       */
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
	mat_proj.l2[0] = 0.4082;
	mat_proj.l2[1] = 0.4082;
	mat_proj.l2[2] = -0.8165;
	elem = param->trame;
	while (elem)
	{
		point = rotate(param, elem->point_3d);
		elem->point_2d_fl = prod_mat3x2_p3d(mat_proj, point);
		elem = elem->next;
	}
}
