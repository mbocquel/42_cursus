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

void	apply_isometric_proj(t_trame *trame)
{
	t_mat3x2	mat_proj;
	t_trame		*elem;

	mat_proj.l1[0] = 0.7071;
	mat_proj.l1[1] = -0.7071;
	mat_proj.l1[2] = 0;
	mat_proj.l2[0] = 0.4082;
	mat_proj.l2[1] = 0.4082;
	mat_proj.l2[2] = -0.8165;
	elem = trame;
	while (elem)
	{
		elem->point_2d_fl.xf = prod_mat3x2_p3d(mat_proj, elem->point_3d).xf;
		elem->point_2d_fl.yf = prod_mat3x2_p3d(mat_proj, elem->point_3d).yf;
		elem = elem->next;
	}
}
